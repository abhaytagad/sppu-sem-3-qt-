#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QOpenGLFunctions>
#include<QOpenGLWindow>
#include<QSurfaceFormat>
#include<GL/gl.h>



QT_BEGIN_NAMESPACE


class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void draw();
private:

    QOpenGLContext *context;
    QOpenGLFunctions *function;


private:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
