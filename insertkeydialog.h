#ifndef INSERTKEYDIALOG_H
#define INSERTKEYDIALOG_H

#include <QDialog>

namespace Ui {
class InsertKeyDialog;
}

class InsertKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertKeyDialog(QWidget *parent = nullptr);
    ~InsertKeyDialog();

private slots:
    void on_buttonBox_accepted();
    void on_InsertKeyDialog_rejected();

signals:
    void signalLicenseKeyInserted(QString key);
    void signalDialogCanceled();

private:
    Ui::InsertKeyDialog *ui;
};

#endif // INSERTKEYDIALOG_H
