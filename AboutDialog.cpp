#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include <QUrl>
#include <QTimer>
#include <QEventLoop>
#include <QJsonObject>
#include <QProgressBar>
#include <QProgressDialog>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("About");

    QString aboutVersion = "<b>Version:</b>" + QString(" 1.0");

     ui->versionLabel->setText(aboutVersion);

}

AboutDialog::~AboutDialog()
{
    delete ui;
}


void AboutDialog::on_closeButton_clicked(){

    this->close();
}
