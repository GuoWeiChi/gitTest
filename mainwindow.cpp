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

void code(char *s)
{
    while(*s)//遍历一个字符串
    {
        (*s)++;
        s++;
    }
}

void decode(char *s)
{
    while(*s)
    {
        (*s)--;
        s++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    char s[1024] = {0};
    FILE *p = fopen("a.txt","r");//用读方式打开文件
    FILE *p1 = fopen("b.txt","w");//用写的方式打开一个文件
    //feof(p);//如果已经到了文件最后,函数返回真
    while(!feof(p))
    {
        memset(s,0,sizeof(s));
        fgets(s,sizeof(s),p);//第一个参数是一个内存地址;第二个参数是这块内存的大小;
                             //第三个参数是fopen返回的指针
                             //每次读一行
        code(s);
        fputs(s,p1);
    }

    fclose(p);
    fclose(p1);
}

void MainWindow::on_pushButton_2_clicked()
{
    char s[1024] = {0};
    FILE *p = fopen("b.txt","r");//用读方式打开文件
    FILE *p1 = fopen("c.txt","w");//用写的方式打开一个文件
    //feof(p);//如果已经到了文件最后,函数返回真
    while(!feof(p))
    {
        memset(s,0,sizeof(s));
        fgets(s,sizeof(s),p);//第一个参数是一个内存地址;第二个参数是这块内存的大小;
                             //第三个参数是fopen返回的指针
                             //每次读一行
        decode(s);
        fputs(s,p1);
    }

    fclose(p);
    fclose(p1);
}
