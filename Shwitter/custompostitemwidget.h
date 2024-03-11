#ifndef CUSTOMPOSTITEMWIDGET_H
#define CUSTOMPOSTITEMWIDGET_H

#include "widget.h"
#include "postelement.h"
#include "utils.h"
#include "post.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class CustomPostItemWidget;
}
QT_END_NAMESPACE

class CustomPostItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit CustomPostItemWidget(const PostElement& post, Widget* parent);

private slots:
    void handleButtonClicked();

private:
    QHBoxLayout* layout;
    QLabel* usernameLabel;
    QLabel* timeLabel;
    QLabel* postLabel;
    QPushButton* button;
    QString m_post_uuid;
    Widget* m_parent;
};

#endif // CUSTOMPOSTITEMWIDGET_H
