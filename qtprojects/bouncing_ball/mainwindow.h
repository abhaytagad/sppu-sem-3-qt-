#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTimer>
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


public slots:

    void animation(float x0, float y0);

private:
    Ui::MainWindow *ui;


    void rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    void reset(int c1, int c2, int radius);
    void dda(int x1, int y1, int x2, int y2);
    void Bresanham(int c1, int c2, int radius);

};
#endif // MAINWINDOW_H
