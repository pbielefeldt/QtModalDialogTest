#include "mywidget.h"
#include "mydialog.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>

MyWidget::MyWidget(const QString &text, QWidget *parent)
    : QWidget{parent}
{
    QPushButton *button = new QPushButton("Open Dialog", this);
    connect(button, &QPushButton::clicked, this, [=]() {
        MyDialog *dialog = new MyDialog(text, this);
        dialog->show();
    });

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    setLayout(layout);
}
