#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <countdlg.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //文件操作 信号与槽的连接
    connect(ui->actionopen,SIGNAL(triggered()),this,SLOT(openfile()));
    connect(ui->actionsave,SIGNAL(triggered()),this,SLOT(savefile()));
    connect(ui->actionsaveas,SIGNAL(triggered()),this,SLOT(saveasfile()));
    //统计字数菜单
    connect(ui->actioncount,SIGNAL(triggered()),this,SLOT(count()));
    //统计字符串菜单
    connect(ui->actioncounts,SIGNAL(triggered()),this,SLOT(countStr()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setfilePath(QString fp)
{
    filePath=fp;
}

QString MainWindow::getfilePath()
{
    return filePath;
}

void MainWindow::openfile()
{
    QString filepath;
    filepath = QFileDialog::getOpenFileName(this,tr("文件"),"",tr("text(*.txt)"));
    QFile file(filepath);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        return;
    }
    else
    {
        this->setfilePath(filepath); //设置filePath为目前打开的文件路径
        QTextStream in(&file);
        this->ui->plainTextEdit->setPlainText(in.readAll());
        file.close();
    }
}

void MainWindow::savefile()
{
    QString filepath;
    filepath=this->getfilePath();
    if(filepath.isEmpty())
      filepath = QFileDialog::getSaveFileName(this,tr("文件"),"", tr("text(*.txt)"));

    if(!filepath.isEmpty())
    {
        QFile file(filepath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
             QMessageBox::warning(this, tr("Write File"),tr("Cannot open file:\n%1").arg(filepath));
             return;
        }
        QTextStream out(&file);
        out << this->ui->plainTextEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));
    }
}

void MainWindow::saveasfile()
{
    QString filepath;
    filepath = QFileDialog::getSaveFileName(this,tr("文件"),"", tr("text(*.txt)"));
    if(!filepath.isEmpty())
    {
        QFile file(filepath);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
             QMessageBox::warning(this, tr("Write File"),tr("Cannot open file:\n%1").arg(filepath));
             return;
        }
        QTextStream out(&file);
        out << this->ui->plainTextEdit->toPlainText();
        this->setfilePath(filepath); //设置filePath为保存的文件路径
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));
    }
}

void MainWindow::count()
{
    cdlg = new countDlg(this);
    cdlg->setModal(false);
    QString text = this->ui->plainTextEdit->toPlainText();

    int num_blanks=text.count(" ");
    int num_nums=text.count("0")+text.count("1")+text.count("2")+text.count("3")+
                 text.count("4")+text.count("5")+text.count("6")+text.count("7")+
                 text.count("8")+text.count("9");
    int num_enter =text.count("\n");           //换行符个数
    int num_all = text.count()-num_enter;      //去除换行符后的有效字符数
    int num_chars=num_all-num_blanks-num_nums;

    cdlg->setNums(num_all,num_nums,num_chars,num_blanks);
    cdlg->display();
    cdlg->show();
}

void MainWindow::countStr()
{
    csdlg =new countStrDlg(this);
    csdlg->setModal(false);
    csdlg->setStr(this->ui->plainTextEdit->toPlainText());
    csdlg->show();
}
