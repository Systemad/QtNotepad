#include "dialogs/AboutDialog.h"
#include "ui_aboutdialog.h"

#include <QUrl>
#include <QTimer>
#include <QEventLoop>
#include <QJsonObject>
#include <QProgressBar>
#include <QProgressDialog>
#include "mainwindow.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("About");

    QString aboutVersion = "<b>Version:</b>" + QString(" 1.0");

    ui->versionLabel->setText(aboutVersion);
    ui->createdLabel->setText("<a href=\"https://github.com/Systemad\"><b>Created by systemad@github</b></a>");
    ui->createdLabel->setTextFormat(Qt::RichText);
    ui->createdLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->createdLabel->setOpenExternalLinks(true);

    ui->githubrepoLabel->setText("<a href=\"https://github.com/Systemad/QtNotepad\"><b>GitHub</b></a>");
    ui->githubrepoLabel->setTextFormat(Qt::RichText);
    ui->githubrepoLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->githubrepoLabel->setOpenExternalLinks(true);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
