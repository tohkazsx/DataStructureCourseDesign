#include "countdlg.h"
#include "ui_countdlg.h"

countDlg::countDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::countDlg)
{
    ui->setupUi(this);
}

countDlg::~countDlg()
{
    delete ui;
}

void countDlg::display()
{
    QString disnum;
    this->ui->lE_all->setText(disnum.setNum(Num_all));
    this->ui->lE_blank->setText(disnum.setNum(Blanks));
    this->ui->lE_char->setText(disnum.setNum(Chars));
    this->ui->lE_num->setText(disnum.setNum(Nums));
}

void countDlg::setNums(int num_all,int nums,int chars,int blanks)
{
    this->Num_all=num_all;
    this->Nums=nums;
    this->Chars=chars;
    this->Blanks=blanks;
}

void countDlg::on_pushButton_clicked()
{
    this->close();
}
