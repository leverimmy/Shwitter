#ifndef CUSTOMLISTITEMWIDGET_H
#define CUSTOMLISTITEMWIDGET_H

#include "widget.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class CustomListItemWidget;
}
QT_END_NAMESPACE

class CustomListItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomListItemWidget(const QString& text, Widget* parent);

private slots:
    void handleButtonClicked();

private:
    QHBoxLayout* layout;
    QLabel* label;
    QPushButton* button;
    Widget* m_parent;
};

#endif // CUSTOMLISTITEMWIDGET_H
