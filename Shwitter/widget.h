#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSql>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
class CustomListItemWidget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void drawSubscriptionPage();

private slots:
    void on_registerButton_clicked();
    void on_backButton_1_clicked();
    void on_backButton_2_clicked();
    void on_helpButton_clicked();
    void on_loginButton_clicked();
    void on_confirmButton_clicked();
    void on_logoutButton_clicked();
    void on_backButton_3_clicked();
    void on_followButton_clicked();
    void on_subscribeButton_clicked();

public:
    Ui::Widget *ui;
    QString global_user_uuid;
    QSqlDatabase db;
};

class CustomListItemWidget : public QWidget {
    Q_OBJECT
public:
    explicit CustomListItemWidget(const QString& text, QListWidget* listWidget, Widget* parent);

private slots:
    void handleButtonClicked();

private:
    QHBoxLayout* layout;
    QLabel* label;
    QPushButton* button;
    Widget* m_parent;
};

#endif // WIDGET_H
