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

    // QPushButton button("Hello World!");
    // button.show();
    MyWidget *widget1 = new MyWidget("Dialog 1");
    MyWidget *widget2 = new MyWidget("Dialog 2");

    QHBoxLayout *layout = new QHBoxLayout(mainWindow);
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    mainWindow->setLayout(layout);

    mainWindow->show();

    return app.exec();
}
