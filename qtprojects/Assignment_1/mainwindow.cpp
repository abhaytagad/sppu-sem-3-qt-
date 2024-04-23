#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<qmath.h>
#include<QImage>
#include<QMouseEvent>
#include<qvector.h>
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

        img.setPixel(x,y,qRgb(0,0,255));
        x = x + xinc;
        y = y + yinc;
        i++;

    }
}
 void MainWindow::dda_line(float x1,float y1,float x2, float y2){
        float dx = x2-x1;
        float dy = y2-y1;

        float steps = abs(dx);

        if(abs(dy)>abs(dx)){
            steps = abs(dy);
        }

        float xinc = dx/steps;
        float yinc = dy/steps;

        float x = x1;
        float y = y1;

        for(int i = 0;i<steps;i++){
            img.setPixel(x,y,qRgb(0,255,0));
            x = x+xinc;
            y = y+yinc;
        }
}

 void MainWindow:: breh(int x1, int y1, int x2, int y2){

        int dx = x2 - x1;
        int dy  = y2 -y1;
        float m;
        if (dx != 0){
            float m = dy/dx;

        }

        float p = (2*dy)- dx;
        float  x = x1;
        float y = y1;
        img.setPixel(x,y,qRgb(255,0,0));
        if (m <1){

            while (x != x2){
                if (p < 0){
                    x++;
                    p += (2*dy);
                    img.setPixel(x,y,qRgb(255,0,0));
                }
                else{
                    x++;
                    y++;
                    p = p + 2*(dy - dx);
                    img.setPixel(x,y,qRgb(255,0,0));
                }
            }
        }
        else if (dx == 0){
            while (x != x2){
                if (p < 0){
                    y++;
                    p += (2*dx);
                    img.setPixel(x,y,qRgb(255,0,0));
                }
                else{
                    x++;
                    y++;
                    p = p + 2*(dx - dy);
                    img.setPixel(x,y,qRgb(255,0,0));
                }
            }
        }

 }

 void MainWindow:: circle(int c1, int c2,int radius){

        float x = 0;
        float y = radius;
        int n = 0;
        while (true){
            if (pow(2,n) > radius){

                break;
            }
            n++;
        }

        float E = (1/pow(2,n));
        int i = 0;

        do{
            i++;
            img.setPixel(x+c1,y+c2,qRgb(255,0,0));
            //img.setPixel(y+c1,x+c2,qRgb(0,255,0));
            img.setPixel(-x+c1,y+c2,qRgb(255,0,0));
            img.setPixel(-x+c1,-y+c2,qRgb(255,0,0));
            img.setPixel(x+c1,-y+c2,qRgb(255,0,0));
            //img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
            //img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
            //img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));
            //img.setPixel(x,y,qRgb(0,255,0));
            x = x + (E*y) ;
            y = y - (E*x) ;
        }while (y >0 );

        return ;
 }

 void MainWindow:: Bcircle(int c1 , int c2 , int R){

        int x = 0;
        int y =  R;
        int p = 3 - (2*R);
        img.setPixel(c1,c2,qRgb(0,255,0));
        while (not(y< x)){

            if (p >= 0){

                if (x != y){
                    img.setPixel(x+c1,y+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(-x+c1,y+c2,qRgb(0,255,0));
                    img.setPixel(-x+c1,-y+c2,qRgb(0,255,0));
                    img.setPixel(x+c1,-y+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));

                }
                else{
                    img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));
                }
                x = x + 1;
                y = y - 1;
                p = p + (4*(x-y)) + 10;

            }
            else{

                if (x != y){

                    img.setPixel(x+c1,y+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(-x+c1,y+c2,qRgb(0,255,0));
                    img.setPixel(-x+c1,-y+c2,qRgb(0,255,0));
                    img.setPixel(x+c1,-y+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));

                }
                else{
                    img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                    img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                    img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));
                }
                x = x + 1;
                p = p + (4*x) + 6;
            }
        }
        return ;
 }


 void MainWindow:: midpt(int c1, int c2, int r){

        if (r == 0){
            return ;
            }
        float d = (5/4)-r;
        int x = 0;
        int y = r;
        img.setPixel(c1,c2,qRgb(255,0,0));
        img.setPixel(x+c1,y+c2,qRgb(0,255,0));
        img.setPixel(-x+c1,y+c2,qRgb(0,255,0));
        img.setPixel(-x+c1,-y+c2,qRgb(0,255,0));
        img.setPixel(x+c1,-y+c2,qRgb(0,255,0));

        while (x < y){

            if (d >0){
                d = d + (2*x) - (2*y) + 5;
                x = x + 1;
                y = y -1;

                img.setPixel(x+c1,y+c2,qRgb(0,255,0));
                img.setPixel(-x+c1,y+c2,qRgb(0,255,0));
                img.setPixel(-x+c1,-y+c2,qRgb(0,255,0));
                img.setPixel(x+c1,-y+c2,qRgb(0,255,0));
                img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));

            }
            else {
                d = d + (2*x) +3;
                x = x + 1;

                img.setPixel(x+c1,y+c2,qRgb(0,255,0));
                img.setPixel(-x+c1,y+c2,qRgb(0,255,0));
                img.setPixel(-x+c1,-y+c2,qRgb(0,255,0));
                img.setPixel(x+c1,-y+c2,qRgb(0,255,0));
                img.setPixel(y+c1,x+c2,qRgb(0,255,0));
                img.setPixel(-y+c1,x+c2,qRgb(0,255,0));
                img.setPixel(y+c1,-x+c2,qRgb(0,255,0));
                img.setPixel(-y+c1,-x+c2,qRgb(0,255,0));

            }
        }
       midpt(c1, c2, r-1);

 }

 void MainWindow:: drawBresenhamLine(int x1, int y1, int x2, int y2) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        //int sx = (x1 < x2) ? 1 : -1;
        //int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;
        int x = x1;
        int y = y1;
        while (true) {
            img.setPixel(x, y, qRgb(255, 0, 0));

            if (x == x2 && y == y2) {
                break;
            }

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                if (x1 < x2){
                   x += 1;
                }
                else{
                   x  -= 1;
                }
            }
            if (e2 < dx) {
                err += dx;
                if (y1 < y2){
                     y += 1;

                }
                else{
                     y -= 1;
                }

            }
        }
 }

 void MainWindow:: flood(int x, int y, int bcolor, int fillcolr){


        if ((x > 400) or (y > 400)){
            return;
        }

        if ((x <0) or (y < 0) ){
            return;
        }

        if ((img.pixelColor(x, y) != bcolor) and (img.pixelColor(x,y)) != fillcolr){

            img.setPixel(x,y,qRgb(0,255,0));


            flood(x+1,y,bcolor , fillcolr);
            flood(x,y+1,bcolor , fillcolr);
            flood(x-1,y,bcolor , fillcolr);
            flood(x,y-1,bcolor , fillcolr);


        }

        return;



 }



void MainWindow::on_pushButton_clicked()
{
    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int R = ui->textEdit_5->toPlainText().toInt();

//    dda_line(x1,y1,x2,y2);
//    dda(x1,y1,x2,y2);
//    breh(x1,y1,x2,y2);
//    Bcircle(265,230,R);
//    circle(250,250,100);

//    drawBresenhamLine(x1,y1,x2,y2);

//    midpt(x1,y1,R);
    flood(250,250,0,10);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow:: heart(){

    for (int x = -200; x< 200; x++){

            for (int y = -200; y<200 ; y++ ){

                float a ,d;

                // a = (x*x) + (y*y) - 10000;
                 //a = (x*x) + (y*y) + (100*x);
                a = x;
                //a = a*a*a ;
                //a = y + pow(a,2);
                a = a*a;

                //d  = x*x*y*y*y;

                d = (9/4)*y*y;
                float c;

                c= a + d -10000;

                c = c*c*c;

                // d = 10000 * ((x*x) + (y*y));

                if (c == 0){

                     img.setPixel(x+250,y+250, qRgb(0,0,255));

                }
                else if (c < 0 ){

                    img.setPixel(x+250,y+250, qRgb(255,0,0));

                }

            }
    }



}



void MainWindow::on_pushButton_2_clicked()
{

    int x1 = ui->textEdit->toPlainText().toInt();
    int y1 = ui->textEdit_2->toPlainText().toInt();
    int x2 = ui->textEdit_3->toPlainText().toInt();
    int y2 = ui->textEdit_4->toPlainText().toInt();
    dda_line(x1,y1,x2,y2);
    //heart();

   //ui->label->setPixmap(QPixmap::fromImage(img));
}

