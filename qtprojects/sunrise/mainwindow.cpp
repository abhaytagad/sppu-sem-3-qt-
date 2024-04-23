#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>


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


void MainWindow:: initializeGL(){


}
void MainWindow:: resizeGL(int w, int h){

}

float colR=5.0;
float colG=5.0;
float colB=0.0;

float ballX=-0.8f;
float ballY=-0.3f;
float ballZ=-1.2f;
void MainWindow:: paintGL(){

    glBegin(GL_LINE_LOOP);
    glColor3f(colR,colG,colB);
    glTranslatef(ballX,ballY,ballZ);
    //glutSolidSphere(0.1,30,30);

    glEnd();


    // Bresanham(c1,c2,radius-1);





}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}
