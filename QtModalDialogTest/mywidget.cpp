#include "mywidget.h"
#include "mydialog.h"

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

    QString dialog_text = "Dialog with \n\n" + parent_text + " as QWidget *parent\".";
    QPushButton *button = new QPushButton("Open " + parent_text + " Dialog", this);

    connect(button, &QPushButton::clicked, this, [=]() {
        MyDialog *dialog = new MyDialog(dialog_text, use_as_parent);
        // dialog->setWindowModality(Qt::ApplicationModal);
        dialog->setWindowModality(Qt::WindowModal);
        dialog->show();
    });

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    setLayout(layout);
}
