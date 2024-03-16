#ifndef POSTWINDOW_H
#define POSTWINDOW_H

#include "post.h"
#include "widget.h"

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

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
