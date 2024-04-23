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

private:
    Ui::MainWindow *ui;
    void dda(int x1, int y1, int x2, int y2);
    void dda_line(float x1, float y1, float x2, float y2);
    void behsen(int x1, int y1, int x2, int y2);
    void breh(int x1, int y1, int x2, int y2);
    void circle(int radius);
    void Bcircle(int c1, int c2, int R);
    void circle(int c1, int c2, int radius);
    void drawBresenhamLine( int x1, int y1, int x2, int y2);
    void midpt(int c1, int c2, int r);
    void heart();
    void flood(int x, int y, int bcolor, int fillcolr);

};
#endif // MAINWINDOW_H
