#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

#include "dialogs/AboutDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    QString m_filename;
    AboutDialog *m_aboutDialog;
};
#endif // MAINWINDOW_H
