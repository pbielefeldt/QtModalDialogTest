#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(const QString& text, Qt::WindowModality& modality, QWidget *parent = nullptr);

signals:

private:
    void printInfo() const;

};

#endif // MYWINDOW_H
