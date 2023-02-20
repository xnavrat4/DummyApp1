#include "mainwindow.h"
#include "OpenLicenseModule/openlicensemodule.h"
#include "ui_mainwindow.h"

#include <QSettings>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings;
    m_licenseKey = settings.value("licenseKey").toString();

    m_licenseModule = new OpenLicenseModule(QApplication::applicationName());
    connect(m_licenseModule, &OpenLicenseModule::signalLicenseValidated, this, &MainWindow::onLicenseValidated);
    connect(m_licenseModule, &OpenLicenseModule::signalError, [] (const QString& errorMessage) {
        qInfo() << "[ERROR]\t[" << QDateTime::currentDateTime().toString(Qt::ISODate)
                << "] OpenLicenseModule: " << errorMessage;
        QApplication::quit();
    });

    if (m_licenseKey.isEmpty()){
        m_keyDialog = new InsertKeyDialog(this);
        connect(m_keyDialog, &InsertKeyDialog::signalLicenseKeyInserted, this, &MainWindow::onLicenseKeyInserted);
        connect(m_keyDialog, &InsertKeyDialog::signalDialogCanceled, this, [] () {
            qInfo() << "[ERROR]\t[" << QDateTime::currentDateTime().toString(Qt::ISODate)
                    << "] InsertKeyDialog closed";
            QApplication::quit();
        });
        m_keyDialog->show();
        return;
    }else{
        ui->serialNumberLabel->setText(m_licenseKey);
    }

    m_licenseModule->validate(m_licenseKey);
}

MainWindow::~MainWindow()
{
    QSettings settings;
    settings.setValue("licenseKey", m_licenseKey);

    delete ui;
}

void MainWindow::onLicenseValidated(bool valid, QString params, QString message)
{
    ui->statusLabel->setText(valid ? "Valid!" : "Invalid!");
    ui->parametersLabel->setText(valid ? params : message);
}

void MainWindow::onLicenseKeyInserted(QString key)
{
    m_licenseKey = key;
    ui->serialNumberLabel->setText(key);
    m_licenseModule->validate(key);
}

