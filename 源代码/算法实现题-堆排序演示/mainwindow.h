#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array_input.h>
#include <heap.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    array_input ar;       //存放输入的数组的对象
    heap he;              //排序所用的堆对象
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_input_clicked();

    void on_btn_finish_clicked();

    void on_btn_next_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
