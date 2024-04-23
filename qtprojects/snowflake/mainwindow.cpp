#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>

QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void delay(int millisecondsToWait)
{
    QTime dieTime=QTime::currentTime().addMSecs(millisecondsToWait);
    while(QTime::currentTime()<dieTime)
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents,100);
    }
}

void MainWindow:: DDA_line(int x1, int y1, int x2, int y2){

    float x, y , dy, dx, len, xinc, yinc;

    dx = x2 - x1;
    dy = y2 - y1;

    len = abs(dy);

    if (abs(dx) > abs(dy)){

        len = abs(dx);
    }

    xinc = dx/len;
    yinc = dy/len;

    int i = 0;

    x = x1;
    y = y1;

    while(i < len){

        delay(7);

        img.setPixel(x,y,qRgb(0,250,0));
        x += xinc;
        y += yinc;


        i++;

        ui->label->setPixmap(QPixmap::fromImage(img));

    }



}





void MainWindow ::koch(int it,int x1,int y1,int x5,int y5)
{
    int x2,y2,x3,y3,x4,y4;
    int dx,dy;
    if (it==0)
    {
        DDA_line(x1,y1,x5,y5);
    }
    else
    {
        //delay(10);
        dx=(x5-x1)/3;
        dy=(y5-y1)/3;
        x2=x1+dx;
        y2=y1+dy;
        x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
        y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
        x4=2*dx+x1;
        y4=2*dy+y1;
        koch(it-1,x1,y1,x2,y2);
        koch(it-1,x2,y2,x3,y3);
        koch(it-1,x3,y3,x4,y4);
        koch(it-1,x4,y4,x5,y5);
         ui->label->setPixmap(QPixmap::fromImage(img));
    }
}



void MainWindow::on_pushButton_clicked()
{

    int it;

    it = ui->textEdit->toPlainText().toInt();
    koch(it,150,20,20,280);
    koch(it,280,280,150,20);
    koch(it,20,280,280,280);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

