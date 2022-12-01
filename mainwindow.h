#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QString>
#include<QVector>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_eq_clicked();

    void on_notsure_clicked();

    void on_ineq_clicked();

    void on_nextpair_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> filenamelist1;
    QVector<QString> filenamelist2;
    QVector<QString> list1;
    QVector<QString> list2;
    int num;
    int judged;
    QVector<int>sameline;
};

#endif // MAINWINDOW_H
