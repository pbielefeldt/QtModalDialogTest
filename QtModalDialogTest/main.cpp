#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QDebug>

#include <QVBoxLayout>
#include "mainwidget.h"
#include "mymaindropdown.h"

int main(int argc, char**argv){
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("Main Window");

    MyMainDropdown *dropdown = new MyMainDropdown(mainWindow);

    MyMainWidget *widget1 = new MyMainWidget(DialogParent::THIS, mainWindow);
    MyMainWidget *widget2 = new MyMainWidget(DialogParent::NULLPTR, mainWindow);
    MyMainWidget *widget3 = new MyMainWidget(DialogParent::WINDOW, mainWindow);

    QVBoxLayout *mainLayout = new QVBoxLayout(mainWindow);
    QHBoxLayout *widgetsLayout = new QHBoxLayout();
    widgetsLayout->addWidget(widget1);
    widgetsLayout->addWidget(widget2);
    widgetsLayout->addWidget(widget3);

    mainLayout->addWidget(dropdown);
    mainLayout->addLayout(widgetsLayout);
    mainLayout->addSpacing(24);
    mainLayout->addWidget(new QLabel(QString("using Qt ") + QString(QT_VERSION_STR)));

    QObject::connect(dropdown, &MyMainDropdown::modalityChanged, widget1, &MyMainWidget::setModality);
    QObject::connect(dropdown, &MyMainDropdown::modalityChanged, widget2, &MyMainWidget::setModality);
    QObject::connect(dropdown, &MyMainDropdown::modalityChanged, widget3, &MyMainWidget::setModality);

    mainWindow->setLayout(mainLayout);
    mainWindow->show();

    return app.exec();
}
