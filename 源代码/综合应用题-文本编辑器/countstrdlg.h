#ifndef COUNTSTRDLG_H
#define COUNTSTRDLG_H

#include <QDialog>

namespace Ui {
class countStrDlg;
}

class countStrDlg : public QDialog
{
    Q_OBJECT

public:
    explicit countStrDlg(QWidget *parent = nullptr);
    ~countStrDlg();
    void setNum(int num_str);
    void setStr(QString str);
    QString getStr();
private slots:
    void on_btn_confirm_clicked();

private:
    Ui::countStrDlg *ui;
    QString Text_Str;
    int Num_Str;
};

#endif // COUNTSTRDLG_H
