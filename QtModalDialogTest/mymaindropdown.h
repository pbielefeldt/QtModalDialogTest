#ifndef MYMAINDROPDOWN_H
#define MYMAINDROPDOWN_H

#include <QWidget>

class MyMainDropdown : public QWidget
{
    Q_OBJECT
public:
    explicit MyMainDropdown(QWidget *parent = nullptr);

signals:
    void modalityChanged(int index);

};

#endif // MYMAINDROPDOWN_H
