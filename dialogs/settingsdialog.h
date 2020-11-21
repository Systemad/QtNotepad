#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(MainWindow* mainwin,QWidget *parent = nullptr);
    Ui::SettingsDialog *ui;
    ~SettingsDialog();


private slots:
    void clearButtonText();
    void on_clearButton_clicked();

    void on_bold_checkBox_clicked();

private:
    MainWindow* m_mainwin;
};

#endif // SETTINGSDIALOG_H
