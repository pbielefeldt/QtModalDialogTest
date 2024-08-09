#include "mydialog.h"

#include <QLabel>
#include <QVBoxLayout>

MyDialog::MyDialog(const QString& text, QWidget *parent)
    : QDialog{parent}
{
    QLabel *content = new QLabel("QDialog with \n\n\'" + text + "\' as QWidget *parent.", parent);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(content);
    this->setLayout(layout);

    setWindowFlag(Qt::Window);
    resize(300, 200);
    setWindowModality(Qt::WindowModal);
    printInfo();
}

void MyDialog::printInfo() const
{
    QString modality = "n.a.";
    switch (this->windowModality()) {
    case Qt::WindowModality::NonModal:
        modality = "non modal";
        break;
    case Qt::WindowModality::WindowModal:
        modality = "window modal";
        break;
    case Qt::WindowModality::ApplicationModal:
        modality = "application modal";
        break;
    default:
        break;
    }

    qDebug() << "this is a MyDialog, modality: " + modality;
}
