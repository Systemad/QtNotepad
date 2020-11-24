#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QSettings>

SettingsDialog::SettingsDialog(MainWindow *mainwin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    m_mainwin = mainwin;

    m_SettingsFile = QApplication::applicationDirPath().left(1) + ":/settings.ini";

    //connect(ui->bold_checkBox, &QCheckBox::stateChanged, this, &SettingsDialog::clearButtonText);

    connect(ui->bold_checkBox, SIGNAL(clicked(bool)), this, SLOT(set_bold_text()));
    connect(ui->save_button, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(ui->load_button, SIGNAL(clicked()), this, SLOT(loadSettings()));
    //connect(ui->clearButton, &QAction::triggered, this, &SettingsDialog::cl);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::saveSettings()
{
    QSettings settings(m_SettingsFile, QSettings::NativeFormat);
    QString boldtext;

    if(ui->bold_checkBox->isChecked()){
        boldtext = "true";
    }
    else {
        boldtext = "false";
    }

    settings.value("bold", boldtext);
    m_mainwin->setWindowTitle("Saved");
}

void SettingsDialog::loadSettings()
{
    QSettings settings(m_SettingsFile, QSettings::NativeFormat);
    QString boldText = settings.value("bold", "").toString();

    if(strcmp("boldText", "true")){
        m_mainwin->ui->textEdit->setFontWeight(QFont::Bold);
    }
    else {
        m_mainwin->ui->textEdit->setFontWeight(QFont::Normal);
    }
}

void SettingsDialog::set_bold_text(){

    if(ui->bold_checkBox->isChecked()){
        //m_mainwin->setWindowTitle("Bold");
        m_mainwin->ui->textEdit->setFontWeight(QFont::Bold);
    } else {
        //ui->bold_checkBox->setChecked(false);
        //m_mainwin->setWindowTitle("Normal");
        m_mainwin->ui->textEdit->setFontWeight(QFont::Normal);
    }
}
/*
void SettingsDialog::on_clearButton_clicked()
{
    m_mainwin->setWindowTitle("hello");
    m_mainwin->ui->textEdit->setFontWeight(QFont::Bold);
}
*/
/*
void SettingsDialog::on_bold_checkBox_clicked()
{
    ui->bold_checkBox->isChecked() ? m_mainwin->ui->textEdit->setFontWeight(QFont::Bold) :
                                  m_mainwin->ui->textEdit->setFontWeight(QFont::Normal);
}
*/
