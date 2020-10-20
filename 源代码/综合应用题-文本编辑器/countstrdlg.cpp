#include "countstrdlg.h"
#include "ui_countstrdlg.h"

countStrDlg::countStrDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::countStrDlg)
{
    ui->setupUi(this);
}


countStrDlg::~countStrDlg()
{
    delete ui;
}

void countStrDlg::setNum(int num_str)
{
    Num_Str=num_str;
}

void countStrDlg::setStr(QString str)
{
    Text_Str=str;
}

QString countStrDlg::getStr()
{
    return Text_Str;
}

void countStrDlg::on_btn_confirm_clicked()
{
    QString str_fc;   //string for count
    str_fc = this->ui->lE_countStr->text();
    QString str_text;
    str_text=this->getStr();
    int num_str=str_text.count(str_fc);
    this->ui->label_display->setNum(num_str);
}
