#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)

{
    setSurfaceType(QWindow::OpenGLSurface);

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);
    setFormat(format);

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    function = context->functions();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeGL()
{

}

void MainWindow::resizeGL(int w, int h)
{

}

void MainWindow::paintGL()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

//    glColor3f(0.0f,1.0f,0.0f);
//    glVertex2f(-0.5f,-0.5f);
//    glColor3f(0.0f,1.0f,0.0f);
//    glVertex2f(-0.5f,0.5f);
//    glColor3f(0.0f,1.0f,0.0f);
//    glVertex2f(0.5f,0.5f);
//    glColor3f(0.0f,1.0f,0.0f);
//    glVertex2f(0.5f,-0.5f);




    glEnd();


    glFlush();


}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{

    paintGL();

}

