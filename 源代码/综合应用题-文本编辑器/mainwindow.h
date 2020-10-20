#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <countdlg.h>
#include <countstrdlg.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setfilePath(QString);
    QString getfilePath();
private slots:
    void openfile();       //打开文件
    void savefile();       //保存文件
    void saveasfile();     //另存为文件
    void count();          //计数
    void countStr();       //字符串计数
private:
    bool m_isTextChanged;  //指示文本是否发生过改变
    QString filePath;      //当前打开的文件路径
    Ui::MainWindow *ui;
    countDlg *cdlg;        //字数统计窗口对象
    countStrDlg *csdlg;    //字符串统计窗口对象
};

#endif // MAINWINDOW_H
