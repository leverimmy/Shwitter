#include "custompostitemwidget.h"

CustomPostItemWidget::CustomPostItemWidget(const PostElement& post, Widget *parent)
    :m_parent(parent) {

    layout = new QHBoxLayout(this);
    usernameLabel = new QLabel(get_username_by_uuid(post.get_poster_uuid()), this);
    timeLabel = new QLabel(post.get_timestamp().toString(), this);
    postLabel = new QLabel(post.get_post_content(), this);
    m_post_uuid = post.get_post_uuid();
    button = new QPushButton("删除", this);

    layout->addWidget(usernameLabel);
    layout->addWidget(timeLabel);
    layout->addWidget(postLabel);
    layout->addWidget(button);
    if (post.get_poster_uuid() != parent->get_global_user_uuid()) {
        qDebug() << "Removed button.";
        button->setVisible(false);
    }
    layout->setSpacing(0); // 删除两行之间的空白

    setLayout(layout);

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
