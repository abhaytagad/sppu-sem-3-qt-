#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QtMath>
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap:: fromImage((img)));
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


QList<int> xpts;
QList<int> ypts;

void MainWindow:: fractal(int j, int x1, int y1, int x2, int y2){

    xpts.append(x1);
    xpts.append(x2);
    ypts.append(y1);
    ypts.append(y2);

    int dx ,dy,x3,x4,x5,y3,y4,y5;

    float theta = qDegreesToRadians(60);

    while(j > 0){

        int size = xpts.size();
        int i = 1;
        for(int k = 1; k < size;k++){

            dx = (xpts[i] - xpts[i-1])/3;
            dy = (ypts[i] - ypts[i-1])/3;

            x3=xpts[i-1]+dx;
            y3=ypts[i-1]+dy;

            x5 = 2*dx+xpts[i-1];
            y5= 2*dy+ypts[i-1];
           x4 = (int) (0.5 * (xpts[i] + xpts[i-1]) + sqrt(3) * (ypts[i] - ypts[i-1])/6);
           y4 = (int) (0.5+(ypts[i] + ypts[i-1]) + sqrt(3) * (xpts[i-1] - xpts[i])/6);

//             x4 = x3 + (x5 - x3)* qCos(theta)+ (y5 - y3) * qSin(theta);
//             y4 = y3 - (x5 - x3)* qSin(theta)+(y5 - y3) * qCos(theta);


            xpts.insert(i,x5);
            xpts.insert(i,x4);
            xpts.insert(i,x3);

            ypts.insert(i,y5);
            ypts.insert(i,y4);
            ypts.insert(i,y3);
            i += 4;


        }

        j--;

    }

    for(int i = 0; i < xpts.size()-1; i++){


        DDA_line(xpts[i],ypts[i],xpts[i+1],ypts[i+1]);

    }


    ui->label->setPixmap(QPixmap:: fromImage((img)));
}



void MainWindow:: snowflake(int j, int x1, int y1, int x2, int y2,int x3,int y3){


    fractal(j, x1,y1,x2,y2);
    xpts.clear();
    ypts.clear();
    fractal(j, x2,y2,x3,y3);
    xpts.clear();
    ypts.clear();
    fractal(j, x3,y3,x1,y1);

}


void MainWindow::on_pushButton_clicked()
{
    int x1,x2,y2,y1;

    x1 = ui->textEdit->toPlainText().toFloat();
    y1 = ui->textEdit_2->toPlainText().toFloat();
    x2 = ui->textEdit_3->toPlainText().toFloat();
    y2 = ui->textEdit_4->toPlainText().toFloat();

   //fractal(x1,100,200,420,200);

   snowflake(x1,100,300,400,300,250,50);

    ui->label->setPixmap(QPixmap:: fromImage((img)));

}

