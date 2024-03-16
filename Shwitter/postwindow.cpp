#include "postwindow.h"

NewWindow::NewWindow(QWidget *parent, Widget *m_parent)
    : QDialog(parent), m_parent(m_parent) {
    textEdit = new QTextEdit(this);
    QPushButton *submitButton = new QPushButton("发表", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->addWidget(submitButton);
    setLayout(layout);

    connect(submitButton, &QPushButton::clicked, this, &NewWindow::handleSubmitButtonClicked);
}

void NewWindow::handleSubmitButtonClicked() {
    QString text = textEdit->toPlainText(); // 获取文本输入框内容
    // 在这里进行存储文本输入框内容的操作
    qDebug() << "Input text:" << text;
    insert_or_post(m_parent->get_global_user_uuid(), text);

    close(); // 关闭新窗口
    m_parent->drawPostPage();
}
