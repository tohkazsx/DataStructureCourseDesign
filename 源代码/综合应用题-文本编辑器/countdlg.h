#ifndef COUNTDLG_H
#define COUNTDLG_H

#include <QDialog>

namespace Ui {
class countDlg;
}

class countDlg : public QDialog
{
    Q_OBJECT

public:
    explicit countDlg(QWidget *parent = nullptr);
    ~countDlg();
    void setNums(int num_all,int nums,int chars,int blanks);
    void display();
private slots:
    void on_pushButton_clicked();

private:
    Ui::countDlg *ui;
    int Num_all;
    int Nums;
    int Chars;
    int Blanks;
};

#endif // COUNTDLG_H
