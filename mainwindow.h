#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QAction>
#include "dialogs/AboutDialog.h"
#include "dialogs/settingsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Ui::MainWindow *ui;
    SettingsDialog *m_settingsDialog;
    ~MainWindow();

private slots:
    void actionNew();
    void actionOpen();
    void actionSaveAs();
    void actionExit();
    void actionSave();
    void actionRedo();
    void actionUndo();
    void actionCut();
    void actionPaste();
    void actionCopy();

    void actionAbout();
    void actionSettings();

private:
    QString m_filename;
    AboutDialog *m_aboutDialog;
};
#endif // MAINWINDOW_H
