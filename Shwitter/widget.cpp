#include "widget.h"
#include "ui_widget.h"

#include "login.h"
#include "register.h"
#include "utils.h"
#include "subscription.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("shwitter_database.db");

    // 打开数据库连接
    if (!db.open()) {
        // 处理连接失败的情况
        qDebug() << "Failed to connect to database.";
    } else {
        qDebug() << "Connected to database successfully.";
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (uuid UUID PRIMARY KEY, username VARCHAR(20), password VARCHAR(20))");
    query.exec("CREATE TABLE IF NOT EXISTS subscription (uuid UUID PRIMARY KEY, uuid_list JSONB)");
}

Widget::~Widget() {
    delete ui;
    db.close();
}

CustomListItemWidget::CustomListItemWidget(const QString& text, QListWidget* listWidget, Widget* parent)
    : m_parent(parent) {
    layout = new QHBoxLayout(this);
    label = new QLabel(text, this);
    button = new QPushButton("删除", this);

    layout->addWidget(label);
    layout->addWidget(button);
    layout->setSpacing(0); // 删除两行之间的空白

    setLayout(layout);

    connect(button, &QPushButton::clicked, this, &CustomListItemWidget::handleButtonClicked);

    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // QListWidgetItem* listItem = new QListWidgetItem(listWidget);
    // listWidget->addItem(listItem);
    // listWidget->setItemWidget(listItem, this);
}

void CustomListItemWidget::handleButtonClicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("警告");
    msgBox.setText(QString("取消关注 %1？").arg(this->label->text()));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();
    if (result == QMessageBox::Yes) {
        remove_or_uuid(m_parent->global_user_uuid, get_uuid_by_username(this->label->text()));
        m_parent->drawSubscriptionPage();
    }
}


void Widget::on_registerButton_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_backButton_1_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_backButton_2_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_helpButton_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
}


// 重要，处理登录
void Widget::on_loginButton_clicked() {
    QString username = ui->loginUsernameLineEdit->text();
    QString password = ui->loginPasswordLineEdit->text();

    // 检查登录是否成功
    if (is_valid_username_and_password(username, password) == true) {
        // 如果登录成功，记录下当前用户 uuid，并且转到主页面
        global_user_uuid = get_uuid_by_username(username);
        ui->stackedWidget->setCurrentIndex(2);
    } else {
        // 如果登录失败，弹出警告框，重新填写用户名和密码
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("用户名或密码错误，请重新登录！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();
    }
    ui->loginUsernameLineEdit->clear();
    ui->loginPasswordLineEdit->clear();
}


// 重要，处理注册
void Widget::on_confirmButton_clicked() {
    QString username = ui->registerUsernameLineEdit->text();
    QString password1 = ui->registerPasswordLineEdit->text();
    QString password2 = ui->registerConfirmPasswordLineEdit->text();

    // 检查用户名是否合法
    if (is_valid_username(username) == false) {

        // 如果不合法，弹出警告框，重新填写用户名和密码
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("用户名不合法，请重新注册！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->registerUsernameLineEdit->clear();
        ui->registerPasswordLineEdit->clear();
        ui->registerConfirmPasswordLineEdit->clear();
        return;
    }

    // 检查密码是否合法
    if ((is_valid_password(password1) && is_valid_password(password2)) == false) {

        // 如果不合法，弹出警告框，重新填写密码
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("密码不合法，请重新注册！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->registerPasswordLineEdit->clear();
        ui->registerConfirmPasswordLineEdit->clear();
        return;
    }

    // 检查两次输入的密码是否相同
    if (password1 != password2) {

        // 弹出警告框，重新填写密码
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("两次输入的密码不同，请重新注册！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->registerPasswordLineEdit->clear();
        ui->registerConfirmPasswordLineEdit->clear();
        return;
    }

    // 检查数据库是否能够注册新账号
    if (is_username_exist(username) == false) {

        // 在数据库中新增一条目录，(uid, username, password)
        QUuid uuid = QUuid::createUuid();
        QString uuidString = uuid.toString();
        QSqlQuery query;
        query.prepare("INSERT INTO users (uuid, username, password) VALUES (?, ?, ?)");
        query.addBindValue(uuidString);
        query.addBindValue(username);
        query.addBindValue(calculateSHA256(password1));
        query.exec();

        // 弹出成功框，并返回登录页面
        QMessageBox msgBox;
        msgBox.setWindowTitle("成功");
        msgBox.setText("注册成功！欢迎使用 Shwiteer！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->stackedWidget->setCurrentIndex(0);
    } else {

        // 弹出警告框，重新填写用户名和密码
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("该用户名已被注册，请重新注册！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->registerUsernameLineEdit->clear();
        ui->registerPasswordLineEdit->clear();
        ui->registerConfirmPasswordLineEdit->clear();
        return;

    }
    ui->registerUsernameLineEdit->clear();
    ui->registerPasswordLineEdit->clear();
    ui->registerConfirmPasswordLineEdit->clear();
}


// 重要，处理退出账号
void Widget::on_logoutButton_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
    // 还需要处理登录状态，比如保存数据

}


void Widget::on_backButton_3_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}


void Widget::on_followButton_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
    // 重新绘制关注列表
    drawSubscriptionPage();
}


void Widget::on_subscribeButton_clicked() {
    // 判断 username 是否存在
    QString username = ui->subscribeLineEdit->text();

    if (is_username_exist(username) == true) {

        // 加入关注列表
        QString uuid = get_uuid_by_username(username);
        qDebug() << "Global:" << global_user_uuid << "\n" << "uuid:" << uuid;
        insert_or_uuid(global_user_uuid, uuid);

        // 重新展示新的关注列表
        drawSubscriptionPage();

        // 弹出提示框，关注成功
        QMessageBox msgBox;
        msgBox.setWindowTitle("成功");
        msgBox.setText(QString("您已成功关注 %1！").arg(username));
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->subscribeLineEdit->clear();
    } else {

        // 弹出警告框，重新填写用户名
        QMessageBox msgBox;
        msgBox.setWindowTitle("警告");
        msgBox.setText("该用户名不存在！");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, "明白了");
        msgBox.exec();

        ui->subscribeLineEdit->clear();
    }
}

void Widget::drawSubscriptionPage() {

    // 先清空原来的展示关注列表
    ui->listWidget->clear();


    QStringList followingUUIDList = get_following_uuid(global_user_uuid);
    for (const QString& item : followingUUIDList) {
        QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget);
        CustomListItemWidget* customWidget = new CustomListItemWidget(get_username_by_uuid(item), ui->listWidget, this);
        listItem->setSizeHint(customWidget->sizeHint());
        ui->listWidget->setItemWidget(listItem, customWidget);
    }

    // 再展示新的关注列表
    ui->listWidget->show();
}