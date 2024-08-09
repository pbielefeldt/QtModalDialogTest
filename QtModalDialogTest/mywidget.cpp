#include "mywidget.h"
#include "mydialog.h"
#include "mywindow.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>

MyWidget::MyWidget(DialogParent dialog_parent, QWidget *parent)
    : QWidget{parent}
{
    QWidget *use_as_parent = nullptr;
    QString parent_text = "";

    switch (dialog_parent) {
    case DialogParent::THIS:
        use_as_parent = this;
        parent_text = "widget parent";
        break;
    case DialogParent::NULLPTR:
        use_as_parent = nullptr;
        parent_text = "nullptr";
        break;
    case DialogParent::WINDOW:
        use_as_parent = parent;
        parent_text = "main window parent";
        break;
    default:
        break;
    }


    QPushButton *dialog_button = new QPushButton("Open " + parent_text + " Dialog", this);

    connect(dialog_button, &QPushButton::clicked, this, [=]() {
        MyDialog *dialog = new MyDialog(parent_text, use_as_parent);
    });


    QPushButton *window_button = new QPushButton("Open " + parent_text + " Window", this);

    connect(window_button, &QPushButton::clicked, this, [=]() {
        MyWindow *window = new MyWindow(parent_text, use_as_parent);
    });


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dialog_button);
    layout->addWidget(window_button);
    setLayout(layout);
}
