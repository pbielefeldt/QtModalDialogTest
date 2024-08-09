#include <QApplication>
#include <QWidget>
#include <QDebug>

#include <QVBoxLayout>

#include "mywidget.h"
#include "mydialog.h"

int main(int argc, char**argv){
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Main Window");

    MyWidget *widget1 = new MyWidget(DialogParent::THIS, mainWindow);
    MyWidget *widget2 = new MyWidget(DialogParent::NULLPTR, mainWindow);
    MyWidget *widget3 = new MyWidget(DialogParent::WINDOW, mainWindow);

    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    layout->addWidget(widget3);
    mainWindow->setLayout(layout);

    mainWindow->show();

    return app.exec();
}
