#ifndef POSTWINDOW_H
#define POSTWINDOW_H

#include "widget.h"
#include "post.h"

#include <QDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class NewWindow;
}
QT_END_NAMESPACE

class NewWindow : public QDialog {
    Q_OBJECT
public:
    explicit NewWindow(QWidget *parent, Widget *m_parent);

private slots:
    void handleSubmitButtonClicked();

private:
    QTextEdit *textEdit;
    Widget *m_parent;
};

#endif // POSTWINDOW_H
