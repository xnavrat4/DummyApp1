#include "mainwindow.h"

#include <QApplication>

const QString APP_NAME = "DummyApp1";
const QString ORG_NAME = "DummyOrg1";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName(APP_NAME);
    QApplication::setOrganizationName(ORG_NAME);
    MainWindow w;
    w.show();
    return a.exec();
}
