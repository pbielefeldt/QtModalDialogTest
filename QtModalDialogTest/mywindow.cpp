#include "mywindow.h"

#include <QLabel>
#include <QVBoxLayout>

MyWindow::MyWindow(const QString &text, QWidget *parent)
    : QWindow()
{
    QWidget *container = QWidget::createWindowContainer(this, parent);

    QLabel *content = new QLabel("QWindow with \n\n\'" + text + "\' as QWidget *parent.", parent);
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->addWidget(content);
    container->setLayout(layout);

    container->setWindowFlag(Qt::Window);
    container->resize(300, 200);
    setModality(Qt::WindowModal);
    printInfo();
    container->show();
}

void MyWindow::printInfo() const
{
    QString modality = "n.a.";
    switch (this->modality()) {
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
