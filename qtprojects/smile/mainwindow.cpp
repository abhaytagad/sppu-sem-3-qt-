#include "mainwindow.h"
#include "ui_mainwindow.h"


QImage img(500,500,QImage :: Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

        img.setPixel(x,y,qRgb(0,0,0));
        x += xinc;
        y += yinc;


        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));


}


void MainWindow:: bres(int c1,int c2, int r){


    if (r == 0){

        return;
    }
    float x = 0, y = r, d;

    d = 3 - (2*r);

    while (x <= y){



        img.setPixel(x + c1,y + c2,qRgb(0,255,0));
        img.setPixel(-x + c1,y + c2,qRgb(0,255,0));
        img.setPixel(-x + c1,-y + c2,qRgb(0,255,0));
        img.setPixel(x + c1,-y + c2,qRgb(0,255,0));
        img.setPixel(y + c1,x + c2,qRgb(0,255,0));
        img.setPixel(-y + c1,x + c2,qRgb(0,255,0));
        img.setPixel(-y + c1,-x + c2,qRgb(0,255,0));
        img.setPixel(y + c1,-x + c2,qRgb(0,255,0));


        x++;
        if (d > 0){

            d = d + 4*(x-y) +10;
            y--;
        }
        else{

            d = d+ 4*x + 6;
        }
    }

    bres(c1,c2,r-1);

}

void MainWindow:: smile(int c1,int c2, int r){


    float x = 0, y = r, d;

    d = 3 - (2*r);

    while (x <= y){



        img.setPixel(x + c1,y + c2,qRgb(0,0,0));
        img.setPixel(-x + c1,y + c2,qRgb(0,0,0));
//        img.setPixel(-x + c1,-y + c2,qRgb(0,255,0));
//        img.setPixel(x + c1,-y + c2,qRgb(0,255,0));
//        img.setPixel(y + c1,x + c2,qRgb(0,255,0));
//        img.setPixel(-y + c1,x + c2,qRgb(0,255,0));
//        img.setPixel(-y + c1,-x + c2,qRgb(0,255,0));
//        img.setPixel(y + c1,-x + c2,qRgb(0,255,0));


        x++;
        if (d > 0){

            d = d + 4*(x-y) +10;
            y--;
        }
        else{

            d = d+ 4*x + 6;
        }
    }

}


void MainWindow:: eye(int c1,int c2, int r){


    if (r == 0){

        return;
    }
    float x = 0, y = r, d;

    d = 3 - (2*r);

    while (x <= y){



        img.setPixel(x + c1,y + c2,qRgb(0,0,0));
        img.setPixel(-x + c1,y + c2,qRgb(0,0,0));
        img.setPixel(-x + c1,-y + c2,qRgb(0,0,0));
        img.setPixel(x + c1,-y + c2,qRgb(0,0,0));
        img.setPixel(y + c1,x + c2,qRgb(0,0,0));
        img.setPixel(-y + c1,x + c2,qRgb(0,0,0));
        img.setPixel(-y + c1,-x + c2,qRgb(0,0,0));
        img.setPixel(y + c1,-x + c2,qRgb(0,0,0));


        x++;
        if (d > 0){

            d = d + 4*(x-y) +10;
            y--;
        }
        else{

            d = d+ 4*x + 6;
        }
    }

    eye(c1,c2,r-1);

}



void MainWindow::on_pushButton_clicked()
{

    bres(250,250,75);
    smile(250,220,60);
     smile(250,220,61);
     smile(250,220,62);

    eye(230,230,5);
    eye(270,230,5);
//    DDA_line(250,250,250,285);
//    DDA_line(249,250,249,285);
//    DDA_line(251,250,251,285);


    ui->label->setPixmap(QPixmap::fromImage(img));
}

