#include "mywindow.h"

#include <QLabel>
#include <QVBoxLayout>

MyWindow::MyWindow(const QString &text, Qt::WindowModality &modality, QWidget *parent)
    : QWidget{parent}
{
    QLabel *content = new QLabel("QWindow with \n\n\'" + text + "\' as QWidget *parent.", parent);
    QVBoxLayout *layout = new QVBoxLayout(parent);
    layout->addWidget(content);
    setLayout(layout);

    setWindowFlag(Qt::Window);
    resize(300, 200);
    setWindowModality(modality);
    printInfo();
}

void MyWindow::printInfo() const
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

    qDebug() << "this is a MyWindow, modality: " + modality;
}
