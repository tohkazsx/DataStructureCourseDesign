#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_input_clicked()
{
    static QString numString = "";
    int num=int(this->ui->number_input->value());
    ar.add(num);

    QString tmp;
    tmp.sprintf("%d",num);
    numString.append(tmp+"  ");
    this->ui->lb_array->setText(numString);
}



void MainWindow::on_btn_finish_clicked()
{
    //生成堆
    QString heap_s="",tmpS;
    he.build(ar.A, ar.n);
    for(int i = 1; i <= he.n; ++i)
        he.push_up(i);
    for(int i = 1; i <= this->he.tail; ++i)
        tmpS.sprintf("%d",this->he.head[i]), heap_s.append(tmpS + "  ");
    this->ui->lb_heap->setText(heap_s);
}

void MainWindow::on_btn_next_clicked()
{
    if(this->he.tail == 0)
    {
        ui->btn_next->setText("退出");
        this->close();
        return;
    }
    if(this->he.tail == 1)
        ui->btn_next->setText("退出");
    else
        ui->btn_next->setText("下一步");
    ui->lcd_result->display(this->he.top());

    int tmp = this->he.head[1];
    this->he.head[1] = this->he.head[this->he.tail];
    this->he.head[this->he.tail] = tmp;
    --this->he.tail;
    this->he.push_down();

    QString sorted = "", unsorted = "", tmpQS;
   // qDebug("%d %d\n",he.n, he.tail);

    for(int i = 1; i <= this->he.tail; ++i)
        tmpQS.sprintf("%d",this->he.head[i]), unsorted.append(tmpQS + "  ");
    for(int i = this->he.tail + 1; i <= this->he.n; ++i)
        tmpQS.sprintf("%d",this->he.head[i]), sorted.append(tmpQS + "  ");


    this->ui->lb_heap->setText(unsorted);
    this->ui->lb_result->setText(sorted);
}
