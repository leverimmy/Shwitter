#include "custompostitemwidget.h"

CustomPostItemWidget::CustomPostItemWidget(const PostElement& post, Widget *parent)
    :m_parent(parent) {

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* headerLayout = new QHBoxLayout();
    QHBoxLayout* contentLayout = new QHBoxLayout();

    QFont font1("Microsoft YaHei UI", 12); // 设置字体为 Microsoft YaHei UI，大小为 12

    usernameLabel = new QLabel("用户 " + get_username_by_uuid(post.get_poster_uuid()));
    usernameLabel->setFont(font1);
    timeLabel = new QLabel("发表于 " + post.get_timestamp().toString("yyyy-MM-dd hh:mm:ss"));
    button = new QPushButton("删除");
    m_post_uuid = post.get_post_uuid();

    headerLayout->addWidget(usernameLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(timeLabel);
    headerLayout->addStretch();

    if (post.get_poster_uuid() == parent->get_global_user_uuid()) {
        headerLayout->addWidget(button);
    } else {
        qDebug() << "Removed button.";
        button->setVisible(false);
    }

    postLabel = new QLabel(post.get_post_content());
    QFont font2("SimSun", 18); // 设置字体为 SimSun，大小为 18
    postLabel->setFont(font2); // 设置内容的字体
    contentLayout->addWidget(postLabel);

    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(contentLayout);

    mainLayout->setSpacing(1); // 删除两行之间的空白

    // 创建滚动区域并将主布局添加到其中
    QScrollArea* scrollArea = new QScrollArea;
    QWidget* scrollWidget = new QWidget;
    scrollWidget->setLayout(mainLayout);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setStyleSheet("QScrollArea { border: none; }");


    // 设置滚动条策略
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 将滚动区域设置为 CustomPostItemWidget 的布局
    QVBoxLayout* widgetLayout = new QVBoxLayout(this);
    widgetLayout->addWidget(scrollArea);
    setLayout(widgetLayout);

    connect(button, &QPushButton::clicked, this, &CustomPostItemWidget::handleButtonClicked);

    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}


void CustomPostItemWidget::handleButtonClicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("警告");
    msgBox.setText("删除该动态？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();
    if (result == QMessageBox::Yes) {
        // 删除 Post
        remove_or_post(this->m_post_uuid);
        m_parent->drawPostPage();
    }
}
