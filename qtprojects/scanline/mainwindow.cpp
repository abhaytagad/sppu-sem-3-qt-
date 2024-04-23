#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
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


void delay(float milliSecond){

    QTime wait = QTime:: currentTime().addMSecs(milliSecond);

    while (QTime::currentTime() < wait){

        QCoreApplication :: processEvents(QEventLoop :: AllEvents, 100);
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

        img.setPixel(x,y,qRgb(0,250,0));
        x += xinc;
        y += yinc;


        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));


}


QList<int> xpts;
QList<int> ypts;

int x_max = 0,y_max = 0,x_min = 500,y_min = 500;
bool fla = true;
int temp1 = 0;
int temp2 = 0;

void MainWindow:: mousePressEvent(QMouseEvent *event){

    int x = event->pos().x();
    int y = event->pos().y();

    if (! fla){

        fla = true;
        temp1 = x;
        temp2 = y;
        //scanline(y_max, x_max,10,0);
        //flood(x,y,0,10);

        return;
    }
    if (x > x_max){
        x_max = x;
    }
    if (y > y_max){

        y_max = y;
    }

    if (x < x_min){

        x_min = x;
    }

    if(y < y_min){

        y_min = y;
    }

    if (event->button() == Qt::RightButton){

        DDA_line(xpts[0], ypts[0] , xpts[xpts.size() - 1], ypts[ypts.size() - 1]);

        fla = false;


        return;
    }
    else {

        if (xpts.size() > 0){
            xpts.append(x);
            ypts.append(y);

            DDA_line(xpts[xpts.size() - 2], ypts[ypts.size() - 2] , x,y);


        }
        else{

            xpts.append(x);
            ypts.append(y);

        }

    }



}


QList<int> xi;
QList<int> yi;

void MainWindow :: sc(){

    xpts.append(xpts[0]);
    ypts.append(ypts[0]);

    for (int y = 0; y < 500; y++){

        for (int i = 0; i < ypts.size() - 1; i++){

            if (ypts[i] <= y && ypts[i + 1] >= y || ypts[i + 1] <= y && ypts[i] >= y ){

                float dx = xpts[i + 1] - xpts[i];
                float dy =ypts[i + 1] - ypts[i];
                float slope;

                if (dx == 0){
                    slope = 0;

                }
                else if (dy == 0){
                    slope = 1;
                }
                else{

                    slope = dx/dy;
                }

                xi.append(int(xpts[i]+slope*(y-ypts[i])));
                yi.append(y);

            }
        }

        for (int i = 0; i < xi.size(); i++){

            for (int j = 0; j < xi.size() - 1; j++){

                if (xi[j] > xi[j + 1]){

                    int temp = xi[j];
                    xi[j] = xi[j +1];
                    xi[j +1] = temp;
                }
            }
        }

        if (xi.size() >= 2){

            for (int i = 0 ; i < xi.size()-1; i+=2){

                DDA_line(xi[i],yi[i], xi[i+1], yi[i+1]);
            }


        }

        xi.clear();
        yi.clear();
        delay(5);
        ui->label->setPixmap(QPixmap::fromImage(img));
    }

}


void MainWindow::on_pushButton_clicked()
{
    sc();

    ui->label->setPixmap(QPixmap::fromImage(img));

}

