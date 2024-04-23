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

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    void dda(int x1, int y1, int x2, int y2);

    void rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    void sutherland(int x1, int y1, int x2, int y2,int bcolor);
    QString Code(int x, int y);

    void reset(int x1, int y1, int x2, int y2);
};
#endif // MAINWINDOW_H
