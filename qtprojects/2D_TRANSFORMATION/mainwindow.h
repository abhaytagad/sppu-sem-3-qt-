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

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event);
    void DDA_line(int x1, int y1, int x2, int y2);
    void trans(QList<int> &l1, QList<int> &l2, float tx, float ty,int x0 , int y0);
    void reset();
    void axesess(int x0, int y0);
    void scaling(QList<int> &l1, QList<int> &l2, float sx, float sy, int x0, int y0);
    void rotate(QList<int> &l1, QList<int> &l2, double angle, int x0 ,int y0);
    void shearing(QList<int> &l1, QList<int> &l2, float shr, QString axis, int x0, int y0 );
    void reflection(QList<int> &l1, QList<int> &l2, QString line, int x0, int y0);
};
#endif // MAINWINDOW_H
