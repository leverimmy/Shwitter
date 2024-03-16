#include "customsubscriptionitemwidget.h"
#include "utils.h"
#include "subscription.h"

CustomSubscriptionItemWidget::CustomSubscriptionItemWidget(const QString& text, Widget* parent)
    : m_parent(parent) {
    layout = new QHBoxLayout(this);
    label = new QLabel(text, this);
    button = new QPushButton("取消关注", this);

    layout->addWidget(label);
    layout->addWidget(button);
    layout->setSpacing(0); // 删除两行之间的空白

    setLayout(layout);
    
    connect(button, &QPushButton::clicked, this, &CustomSubscriptionItemWidget::handleButtonClicked);

    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void CustomSubscriptionItemWidget::handleButtonClicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("警告");
    msgBox.setText(QString("确定要取消关注 %1？").arg(this->label->text()));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int result = msgBox.exec();
    if (result == QMessageBox::Yes) {
        remove_or_uuid(m_parent->global_user_uuid, get_uuid_by_username(this->label->text()));
        m_parent->drawSubscriptionPage();
    }
}
