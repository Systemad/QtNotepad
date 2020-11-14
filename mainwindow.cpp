#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>

#include "dialogs/AboutDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    m_filename.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
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
void MainWindow::on_actionSave_as_triggered()
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

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    m_aboutDialog = new AboutDialog(this);
    m_aboutDialog->show();
}

void MainWindow::on_actionSave_triggered()
{
    // If no file has been opened, call save ass function
    if(m_filename.isEmpty())
        on_actionSave_as_triggered();

    QFile QFile(m_filename);

    if(QFile.open(QFile::WriteOnly | QFile::Text)){
        QTextStream out(&QFile);
        out << ui->textEdit->toPlainText();
        QFile.flush();
        QFile.close();
    }
}
