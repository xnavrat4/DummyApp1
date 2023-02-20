#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "OpenLicenseModule/openlicensemodule.h"
#include "insertkeydialog.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString m_licenseKey;
    QString m_parameteres;

    InsertKeyDialog* m_keyDialog;
    OpenLicenseModule* m_licenseModule;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onLicenseValidated(bool valid, QString params, QString message);
    void onLicenseKeyInserted(QString key);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
