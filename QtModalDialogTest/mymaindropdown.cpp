#include "mymaindropdown.h"

#include <QComboBox>
#include <QMetaEnum>
#include <QVBoxLayout>

MyMainDropdown::MyMainDropdown(QWidget *parent)
    : QWidget{parent}
{
    QComboBox *comboBox = new QComboBox(this);

    QMetaEnum metaEnum = QMetaEnum::fromType<Qt::WindowModality>();
    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        comboBox->addItem(metaEnum.key(i));
    }

    // Set the default value of the QComboBox to match the default modality
    comboBox->setCurrentIndex((int)Qt::NonModal);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);

    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MyMainDropdown::modalityChanged);
}
