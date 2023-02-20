#include "insertkeydialog.h"
#include "ui_insertkeydialog.h"

InsertKeyDialog::InsertKeyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertKeyDialog)
{
    ui->setupUi(this);
}

InsertKeyDialog::~InsertKeyDialog()
{
    delete ui;
}

void InsertKeyDialog::on_buttonBox_accepted()
{
    if (ui->lineEdit->text().isEmpty()){
        return;
    }
    emit signalLicenseKeyInserted(ui->lineEdit->text());
}


void InsertKeyDialog::on_InsertKeyDialog_rejected()
{
    emit signalDialogCanceled();
}

