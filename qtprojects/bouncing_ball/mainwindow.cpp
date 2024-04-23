#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<qmath.h>

QImage img(2000,1000,QImage::Format_RGB888);

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



void delay(float milisecondsToWait)
{
    QTime dieTime=QTime::currentTime().addMSecs( milisecondsToWait);
    while(QTime::currentTime()<dieTime)
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents,1);
    }
}


void MainWindow:: Bresanham(int c1,int c2, int radius){

    float x = 0 , y = radius, d;

    if (radius  == 0){

        return;
    }
    d = 3 - (2*radius);


    img.setPixel(x+c1,y+c2 , qRgb(0,255,0));
    img.setPixel(-x+c1,y+c2 , qRgb(0,255,0));
    img.setPixel(x+c1,-y+c2 , qRgb(0,255,0));
    img.setPixel(-x+c1,-y+c2 , qRgb(0,255,0));
    img.setPixel(-y+c1,x+c2 , qRgb(0,255,0));
    img.setPixel(y+c1,-x+c2 , qRgb(0,255,0));
    img.setPixel(-y+c1,-x+c2 , qRgb(0,255,0));
    img.setPixel(y+c1,x+c2 , qRgb(0,255,0));
    ui->label->setPixmap(QPixmap::fromImage(img));

    while(x <= y){

        if (d < 0){

            x++;

            img.setPixel(x+c1,y+c2 , qRgb(0,255,0));
            img.setPixel(-x+c1,y+c2 , qRgb(0,255,0));
            img.setPixel(x+c1,-y+c2 , qRgb(0,255,0));
            img.setPixel(-x+c1,-y+c2 , qRgb(0,255,0));
            img.setPixel(-y+c1,x+c2 , qRgb(0,255,0));
            img.setPixel(y+c1,-x+c2 , qRgb(0,255,0));
            img.setPixel(-y+c1,-x+c2 , qRgb(0,255,0));
            img.setPixel(y+c1,x+c2 , qRgb(0,255,0));
             ui->label->setPixmap(QPixmap::fromImage(img));

            d = d + (4*x) +6;
        }
        else{
            x++;
            y--;
            img.setPixel(x+c1,y+c2 , qRgb(0,255,0));
            img.setPixel(-x+c1,y+c2 , qRgb(0,255,0));
            img.setPixel(x+c1,-y+c2 , qRgb(0,255,0));
            img.setPixel(-x+c1,-y+c2 , qRgb(0,255,0));
            img.setPixel(-y+c1,x+c2 , qRgb(0,255,0));
            img.setPixel(y+c1,-x+c2 , qRgb(0,255,0));
            img.setPixel(-y+c1,-x+c2 , qRgb(0,255,0));
            img.setPixel(y+c1,x+c2 , qRgb(0,255,0));
             ui->label->setPixmap(QPixmap::fromImage(img));
            d = d + (4*(x - y)) +10;
        }
    }





   // Bresanham(c1,c2,radius-1);




}



void MainWindow::dda(int x1, int y1, int x2, int y2){

    float dx = x2 - x1;
    float dy  = y2 - y1;
    int len;

    if (abs(dx)>=abs(dy)){

        len = abs(dx);

    }else{
        len = abs(dy);
    }

    float xinc = dx/len;
    float yinc = dy/len;
    float x = x1;
    float y = y1;

    int i = 0;
    while (i <= len) {

        img.setPixel(x,y,qRgb(0,255,0));
        x = x + xinc;
        y = y + yinc;
        i++;

    }
}

void MainWindow:: reset(int c1,int c2,int radius){


    float x = 0 , y = radius, d;

    if (radius  == 0){

        return;
    }
    d = 3 - (2*radius);


    img.setPixel(x+c1,y+c2 , qRgb(0,0,0));
    img.setPixel(-x+c1,y+c2 , qRgb(0,0,0));
    img.setPixel(x+c1,-y+c2 , qRgb(0,0,0));
    img.setPixel(-x+c1,-y+c2 , qRgb(0,0,0));
    img.setPixel(-y+c1,x+c2 , qRgb(0,0,0));
    img.setPixel(y+c1,-x+c2 , qRgb(0,0,0));
    img.setPixel(-y+c1,-x+c2 , qRgb(0,0,0));
    img.setPixel(y+c1,x+c2 , qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(img));

    while(x <= y){

        if (d < 0){

            x++;
            img.setPixel(x+c1,y+c2 , qRgb(0,0,0));
            img.setPixel(-x+c1,y+c2 , qRgb(0,0,0));
            img.setPixel(x+c1,-y+c2 , qRgb(0,0,0));
            img.setPixel(-x+c1,-y+c2 , qRgb(0,0,0));
            img.setPixel(-y+c1,x+c2 , qRgb(0,0,0));
            img.setPixel(y+c1,-x+c2 , qRgb(0,0,0));
            img.setPixel(-y+c1,-x+c2 , qRgb(0,0,0));
            img.setPixel(y+c1,x+c2 , qRgb(0,0,0));
            ui->label->setPixmap(QPixmap::fromImage(img));

            d = d + (4*x) +6;
        }
        else{
            x++;
            y--;
            img.setPixel(x+c1,y+c2 , qRgb(0,0,0));
            img.setPixel(-x+c1,y+c2 , qRgb(0,0,0));
            img.setPixel(x+c1,-y+c2 , qRgb(0,0,0));
            img.setPixel(-x+c1,-y+c2 , qRgb(0,0,0));
            img.setPixel(-y+c1,x+c2 , qRgb(0,0,0));
            img.setPixel(y+c1,-x+c2 , qRgb(0,0,0));
            img.setPixel(-y+c1,-x+c2 , qRgb(0,0,0));
            img.setPixel(y+c1,x+c2 , qRgb(0,0,0));
            ui->label->setPixmap(QPixmap::fromImage(img));
            d = d + (4*(x - y)) +10;
        }
    }



   //reset(c1,c2,radius-1);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow:: rectangle(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4){

    dda(x1,y1,x2,y2);
    dda(x1,y1,x4,y4);
    dda(x3,y3,x2,y2);
    dda(x4,y4,x3,y3);


}

void MainWindow:: animation(float x0, float y0){

     float c1 = x0,c2 = y0;
    Bresanham(x0,y0,30);
    dda(c1,c2+30,1900,c2+30);


    float xp = c1, yp = c2;

    for (float i = 1; i <= 1500; i+= 20){

        if (x0 > 1900 || y0 > 1000){

            break;
        }
        if (x0 < 0 || y0 <0){

            break;
        }
        float angle =  qDegreesToRadians(i);
        float y = qSin(angle);
        y *= 200;
        angle *= 100;
        x0  = c1 + angle ;

        if (y > 0){

            y0 = c2 - y ;
        }
        else{

            y0 = c2 + y ;
        }

        reset(xp,yp,30);
        dda(c1,c2+30,1900,c2+30);

        xp = x0;
        yp = y0;

        Bresanham(x0,y0,30);

        delay(1);

       ui->label->setPixmap(QPixmap::fromImage(img));

    }


}


void MainWindow::on_pushButton_clicked()
{

    float x0,y0;

    x0 = ui->textEdit->toPlainText().toFloat();
    y0 = ui->textEdit_2->toPlainText().toFloat();

    //Bresanham(250,250,50);

    animation(30,400);



    ui->label->setPixmap(QPixmap::fromImage(img));
}

