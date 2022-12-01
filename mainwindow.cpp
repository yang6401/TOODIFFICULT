#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   QFile file("C:/Users/y2002/Desktop/test/equal.csv");
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }
    QString filename;
    filename=file.readLine();
    QStringList filelist;
    while(!file.atEnd()){
        filename=file.readLine();
        filelist=filename.split(',');
        list1.append(filelist[0]);
        list2.append(filelist[1]);
        filelist.clear();
    }
    file.close();
    for(int i=0;i<list1.size();i++){
        int same=0;
        QFile file1(list1[i]);
        if(!file1.open(QIODevice::ReadOnly)){
            return;
        }
        QString temp=list2[i].left(list2[i].size()-2);
        QFile file2(temp);
        if(!file2.open(QIODevice::ReadOnly)){
            return;
        }
        while(!file1.atEnd()&&!file2.atEnd()){
            QString temp1=file1.readLine();
            QString temp2=file2.readLine();
            if(temp1==temp2){
                same++;
            }
        }
        sameline.append(same);
    }
    for(int i=1000;i>=0;i--){
        for(int j=0;j<sameline.size();j++){
            if(sameline[j]==i){
                filenamelist1.append(list1[j]);
                filenamelist2.append(list2[j]);
            }
        }
    }
    num=0;
    judged=1;
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_eq_clicked()
{
    if(judged==1){
        return;
    }
    QFile file("C:/Users/y2002/Desktop/test/equal.csv");
    if(!file.open(QIODevice::Append)){
        return;
    }
    QString temp =filenamelist1[num]+','+filenamelist2[num]+'\n';
    file.write(temp.toUtf8());
    num++;
    judged=1;
}

void MainWindow::on_notsure_clicked()
{
    if(judged==1){
        return;
    }
    num++;
    judged=1;
}


void MainWindow::on_ineq_clicked()
{
    if(judged==1){
        return;
    }
    QFile file("C:/Users/y2002/Desktop/test/inequal.csv");
    if(!file.open(QIODevice::Append)){
        return;
    }
    QString temp =filenamelist1[num]+','+filenamelist2[num]+'/n';
    file.write(temp.toUtf8());
    num++;
    judged=1;
}


void MainWindow::on_nextpair_clicked()
{
    if(judged==0){
        return;
    }
    if(num>=filenamelist1.size()){
        return;
    }
    QFile file1(filenamelist1[num]);
    if(!file1.open(QIODevice::ReadOnly)){
        ui->text1->setText("unexpected error");
        return;
    }
    QByteArray temp1 =file1.readAll();
    ui->text1->setText(temp1);
    QString temp=filenamelist2[num].left(filenamelist2[num].size()-2);
    QFile file2(temp);
    if(!file2.open(QIODevice::ReadOnly)){
        ui->text2->setText("unexpected error");
        return;
    }
    QByteArray temp2 =file2.readAll();
    ui->text2->setText(temp2);
    file1.close();
    file2.close();
    judged=0;
}
