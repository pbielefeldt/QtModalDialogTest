#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

enum struct  DialogParent {THIS, NULLPTR, WINDOW};

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(DialogParent dialog_parent, QWidget *parent);

signals:

};

#endif // MYWIDGET_H
