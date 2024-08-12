#include "mywindow.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QMetaEnum>

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

    const auto mod_text = QString(QMetaEnum::fromType<Qt::WindowModality>().key(this->windowModality()));
    qDebug() << QString("this is a MyDialog, modality: ") + mod_text;
}
