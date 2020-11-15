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
#include "dialogs/settingsdialog.h"

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
    void actionNew();
    void actionOpen();
    void actionSaveAs();
    void actionExit();
    void actionAbout();
    void actionSave();
    void actionRedo();
    void actionUndo();
    void actionCut();
    void actionPaste();
    void actionCopy();

    void actionSettings();

private:
    Ui::MainWindow *ui;
    QString m_filename;
    AboutDialog *m_aboutDialog;
    SettingsDialog *m_settingsDialog;
};
#endif // MAINWINDOW_H
