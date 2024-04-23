#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qvector.h>
#include<QMouseEvent>


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







//QList<int> xsort;
//QList<int> ysort;

//void MainWindow:: scline(){

//    for (int i = 0; i <= y_max ; i++){

//        for (int j = 0; j < ypts.size(); j++){

//            if (i == j){
//                xsort.append(xpts[j]);
//                ysort.append(i);
//            }
//        }
//    }

//    int ptr = 0;

//    for (int i = 0; i <= y_max; i++){

//        if (i == ysort[ptr]){


//        }

//    }

//}










bool flag = true;

void MainWindow:: flood(int x, int y, int bcolor, int fillcolr){


    for (int i = 0; i < xpts.size(); i++){

        if ((x == xpts[i]) and (y == ypts[i])){


            return;

        }
    }


    if (y >= y_max-2){
        flag = false;
        x = temp1 ;
        y = temp2 ;
    }

    if ((img.pixelColor(x, y) == bcolor) and (img.pixelColor(x,y)) != fillcolr){


        img.setPixel(x,y,qRgb(0,255,0));

        flood(x+1,y,bcolor , fillcolr);


        if (flag){

            flood(x,y+1,bcolor , fillcolr);

        }
        else{

            flood(x,y-1,bcolor , fillcolr);

        }

        flood(x-1,y,bcolor , fillcolr);


    }
    else if (img.pixelColor(x,y) == fillcolr){

        return  ;
    }

}


QString MainWindow:: Code(int x, int y){

    QString  code;

    if (y > y_max){

        code = "10";
    }
    else if (y < y_min){

        code = "01";
    }
    else{
        code = "00";
    }



    if (x> x_max){

        code += "10";
    }
    else if (x < x_min){

        code += "01";
    }
    else{
        code += "00";
    }

    return code;

}


int a = 0;
int b = 0;

void MainWindow:: sutherland(int x1, int y1, int x2, int y2){


    QString code1 = Code(x1,y1);
    QString code2 = Code(x2,y2);

    bool f = true;

    for (int i = 0; i < 4; i++){

        if (code1[i] == '0' || code2[i] == '0'){
            f = true;
        }
        else {
            f = false;
            break;
        }
    }

    if (!f){

        //return;
    }


    float slope = (y2 - y1)/(x2 - x1);

    if (x1 < x2 & y1 < y2){

        for (int i = y1; i <= y2; i++){


            for (int j = x1; j < x2; j++){

                if (j == (slope * (i - x1) ) + y1){

                    if (img.pixelColor(i,j) == 10){

                        if (a != 0){

                            a = i;
                            b = j;
                        }
                        else {

                            DDA_line(a,b,i,j);

                            return;
                        }


                    }
                }
            }


        }
    }


}





void MainWindow::on_pushButton_clicked()
{
    //DDA_line(50,50,50,300);
    //flood(250,250,0,10);
    //scanline(400, 400,10,0);
     sutherland(50,300,300,50);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

