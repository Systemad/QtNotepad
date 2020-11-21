#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

SettingsDialog::SettingsDialog(MainWindow *mainwin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    m_mainwin = mainwin;

    //connect(ui->clearButton, &QAction::triggered, this, &SettingsDialog::cl);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::clearButtonText(){
    m_mainwin->setWindowTitle("hello");
    m_mainwin->ui->textEdit->setFontWeight(QFont::Bold);
}
void SettingsDialog::on_clearButton_clicked()
{
    m_mainwin->setWindowTitle("hello");
    m_mainwin->ui->textEdit->setFontWeight(QFont::Bold);
}


void SettingsDialog::on_bold_checkBox_clicked()
{
    ui->bold_checkBox->isChecked() ? m_mainwin->ui->textEdit->setFontWeight(QFont::Bold) :
                                  m_mainwin->ui->textEdit->setFontWeight(QFont::Normal);
}
