#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

enum struct  DialogParent {THIS, NULLPTR, WINDOW};

class MyMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyMainWidget(DialogParent dialog_parent, QWidget *parent);

private:
    Qt::WindowModality selectedModality;

signals:

public slots:
    void setModality(int index);

};

#endif // MYWIDGET_H
