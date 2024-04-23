#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QThread>
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

    void DDA_line(int x1, int y1, int x2, int y2);
    void mousePressEvent(QMouseEvent *event);
    //void scanline();
    void sort(int max);
    void flood(int x, int y, int bcolor, int fillcolr);

    //void mouseMoveEvent(QMouseEvent *event);

    QString Code(int x, int y);
    void sutherland(int x1, int y1, int x2, int y2, int bcolor);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
//    void DDA_line(int x1, int y1, int x2, int y2);
//    void mousePressEvent(QMouseEvent *event);
//    //void scanline();
//    void sort(int max);
//    void flood(int x, int y, int bcolor, int fillcolr);

//    //void mouseMoveEvent(QMouseEvent *event);

//    string Code(int x, int y);
//    void sutherland(int x1, int y1, int x2, int y2);
};
#endif // MAINWINDOW_H
