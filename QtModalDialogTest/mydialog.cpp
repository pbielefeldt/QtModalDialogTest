#include "mydialog.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QMetaEnum>

MyDialog::MyDialog(const QString& text, Qt::WindowModality &modality, QWidget *parent)
    : QDialog{parent}
{
    QLabel *content = new QLabel("QDialog with \n\n\'" + text + "\' as QWidget *parent.", parent);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(content);
    this->setLayout(layout);

    setWindowFlag(Qt::Window);
    resize(300, 200);
    setWindowModality(modality);

    const auto mod_text = QString(QMetaEnum::fromType<Qt::WindowModality>().key(this->windowModality()));
    qDebug() << QString("this is a MyDialog, modality: ") + mod_text;
}

