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
    void set_bold_text();
    void saveSettings();
    void loadSettings();

private:
    QString m_SettingsFile;
    MainWindow* m_mainwin;
};

#endif // SETTINGSDIALOG_H
