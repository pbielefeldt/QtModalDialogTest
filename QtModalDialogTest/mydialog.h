#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(const QString& text, QWidget *parent = nullptr);

signals:

};

#endif // MYDIALOG_H
