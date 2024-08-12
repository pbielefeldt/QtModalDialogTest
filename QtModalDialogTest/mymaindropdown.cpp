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

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);

    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MyMainDropdown::modalityChanged);
}
