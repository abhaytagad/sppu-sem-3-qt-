#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QOpenGLWindow>
#include<QOpenGLFunctions>
#include<QSurfaceFormat>
#include<QtOpenGL>
#include<GL/glu.h>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QOpenGLContext *context;
    QOpenGLFunctions *function;

protected:


    virtual void initializeGL();
     virtual void resizeGL(int w ,int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent * event);
    void paintEvent(QPaintEvent * event);

};
#endif // MAINWINDOW_H
