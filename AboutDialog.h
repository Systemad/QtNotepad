#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

protected slots:
    void on_closeButton_clicked();

private:
    Ui::AboutDialog *ui;
    QString buildQtVersionString(void);
    //QPushButton *closeButton;
};

#endif // ABOUTDIALOG_H
