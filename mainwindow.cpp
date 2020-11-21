#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>

#include "dialogs/AboutDialog.h"
#include "dialogs/settingsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::actionNew);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::actionOpen);
    connect(ui->actionSave_as, &QAction::triggered, this, &MainWindow::actionSaveAs);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::actionExit);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::actionAbout);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::actionSave);

    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::actionRedo);
    connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::actionUndo);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::actionCut);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::actionPaste);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::actionCopy);
    connect(ui->actionSettings, &QAction::triggered, this, &MainWindow::actionSettings);

    m_settingsDialog = new SettingsDialog(this);
    this->setWindowTitle("Notepad");
    this->setCentralWidget(ui->textEdit);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionNew()
{
    m_filename.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::actionOpen()
{
    QString file = QFileDialog::getOpenFileName(this,"Open a file");
    if(!file.isEmpty())
    {
        QFile QFile(file);
        if(QFile.open(QFile::ReadOnly | QFile::Text ))
        {
            m_filename = file;
            QTextStream in(&QFile);
            QString text = in.readAll();
            QFile.close();
            ui->textEdit->setPlainText(text);
            QFileInfo fileInfo(QFile.fileName());
            this->setWindowTitle(fileInfo.fileName());
        }
    }
}
void MainWindow::actionSaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    m_filename = fileName;
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    m_filename = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::actionExit()
{
    QApplication::quit();
}

void MainWindow::actionAbout()
{
    m_aboutDialog = new AboutDialog(this);
    m_aboutDialog->show();
}

void MainWindow::actionSave()
{
    // If no file has been opened, call save ass function
    if(m_filename.isEmpty())
        actionSaveAs();

    QFile QFile(m_filename);

    if(QFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&QFile);
        out << ui->textEdit->toPlainText();
        QFile.flush();
        QFile.close();
    }
}

void MainWindow::actionRedo()
{
    ui->textEdit->redo();
}

void MainWindow::actionUndo()
{
    ui->textEdit->undo();
}

void MainWindow::actionCut()
{
    ui->textEdit->cut();
}

void MainWindow::actionPaste()
{
    ui->textEdit->paste();
}

void MainWindow::actionCopy()
{
    ui->textEdit->copy();
}

void MainWindow::actionSettings()
{

    m_settingsDialog = new SettingsDialog(this);
    m_settingsDialog->show();
}
