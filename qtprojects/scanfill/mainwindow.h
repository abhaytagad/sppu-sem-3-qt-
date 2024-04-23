#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void DDA(int,int,int,int);
    void mousePressEvent(QMouseEvent*event);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int count;
    bool start;
    int a[100],b[100],ver,i,xi[20],j,k,m,n,temp;
    float slope[20];
};
#endif // MAINWINDOW_H