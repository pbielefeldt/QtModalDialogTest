#include "mydialog.h"

#include <QLabel>
#include <QVBoxLayout>

MyDialog::MyDialog(const QString& text, QWidget *parent) : QDialog(parent) {
    QLabel *label = new QLabel(text, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}
