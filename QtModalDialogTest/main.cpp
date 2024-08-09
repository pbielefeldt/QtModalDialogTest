#include <QApplication>
#include <QWidget>
#include <QDebug>

#include <QVBoxLayout>

#include "mainwidget.h"

int main(int argc, char**argv){
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Main Window");

    MyMainWidget *widget1 = new MyMainWidget(DialogParent::THIS, mainWindow);
    MyMainWidget *widget2 = new MyMainWidget(DialogParent::NULLPTR, mainWindow);
    MyMainWidget *widget3 = new MyMainWidget(DialogParent::WINDOW, mainWindow);

    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    layout->addWidget(widget3);
    mainWindow->setLayout(layout);

    mainWindow->show();

    return app.exec();
}
