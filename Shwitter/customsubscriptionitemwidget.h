#ifndef CUSTOMSUBSCRIPTIONITEMWIDGET_H
#define CUSTOMSUBSCRIPTIONITEMWIDGET_H

#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CustomSubscriptionItemWidget;
}
QT_END_NAMESPACE

class CustomSubscriptionItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomSubscriptionItemWidget(const QString& text, Widget *parent);

private slots:
    void handleButtonClicked();

private:
    QHBoxLayout *layout;
    QLabel *label;
    QPushButton *button;
    Widget *m_parent;
};

#endif // CUSTOMSUBSCRIPTIONITEMWIDGET_H
