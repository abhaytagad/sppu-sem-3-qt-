#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMouseEvent>
#include<QtMath>

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


void MainWindow:: mousePressEvent(QMouseEvent *event){

    int x = event->pos().x();
    int y = event->pos().y();



    if (event->button() == Qt::RightButton){

        DDA_line(xpts[xpts.size() -1],ypts[ypts.size() -1],xpts[0],ypts[0]);
        return;
    }
    else{

        if(xpts.size() > 0){

            DDA_line(x,y,xpts[xpts.size() -1],ypts[ypts.size() -1]);

            xpts.append(x);
            ypts.append(y);
        }
        else{

            xpts.append(x);
            ypts.append(y);
        }
    }

}

void MainWindow:: reset(){

    for (int i = 0; i<= 500; i++){

        for (int j = 0; j <= 500; j++){

            img.setPixel(i,j,qRgb(0,0,0));
        }
    }

    xpts.clear();
    ypts.clear();
    return;
}

void MainWindow:: axesess(int x0, int y0){

    DDA_line(x0,0,x0,500);
    DDA_line(0,y0,500,y0);

    return;
}


void MainWindow:: trans(QList<int> &l1,QList<int> &l2 , float tx, float ty , int x0 , int y0){


    for (int i = 0 ; i < l1.size(); i++){

        int dx = l1[i] - x0;
        int dy = l2[i] - y0;
        dy *= -1;

        dx += tx;
        dy += ty;

        l1[i] = x0 + dx ;
        l2[i] = abs(y0 - dy);

    }


    //reset();

    DDA_line(l1[0],l2[0], l1[l1.size() - 1], l2[l2.size() - 1]);

    for (int i = 1; i < l1.size(); i++ ){

        DDA_line(l1[i],l2[i], l1[i - 1], l2[i - 1]);
    }
    return;

}



void MainWindow:: scaling(QList<int> &l1, QList<int> &l2, float sx, float sy , int x0, int y0){


    for (int i = 0; i < l1.size(); i++){

        int dx = l1[i] - x0;
        int dy = l2[i] - y0;
        dy *= -1;

        dx *= sx;
        dy *= sy;

        l1[i] = x0 + dx ;
        l2[i] = abs(y0 - dy);

    }


    DDA_line(l1[0],l2[0], l1[l1.size() - 1], l2[l2.size() - 1]);

    for (int i = 1; i < l1.size(); i++ ){

        DDA_line(l1[i],l2[i], l1[i - 1], l2[i - 1]);
    }
    return;

}



void MainWindow:: rotate(QList<int> &l1, QList<int> &l2, double angle , int x0 ,int y0){

    double radian = qDegreesToRadians(angle);

    for (int i = 0; i < l1.size(); i++){


        float dx = l1[i] - x0;
        float dy = l2[i] - y0;
        dy *= -1;
        float temp ;
        float temp1 ;
        temp = (dx*qCos(radian)) - (dy * qSin(radian));
        temp1 = (dx*qSin(radian)) + (dy*qCos(radian));
        dx = temp;
        dy = temp1;
        l1[i] = abs(x0 + dx) ;
        l2[i] = abs(y0 - dy);

    }


    DDA_line(l1[0],l2[0], l1[l1.size() - 1], l2[l2.size() - 1]);

    for (int i = 1; i < l1.size(); i++ ){

        DDA_line(l1[i],l2[i], l1[i - 1], l2[i - 1]);
    }
    return;

}


void MainWindow:: shearing(QList<int> &l1, QList<int> &l2, float shr, QString axis, int x0, int y0 ){


    if (axis == 'x'){

        for (int i = 0; i < l2.size(); i++){

            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;

            dx = dx + (shr*dy);

            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }

    }
    else{

        for (int i = 0; i < l2.size(); i++){

            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;

            dy = dy + (shr*dy);

            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }

    }

    DDA_line(l1[0],l2[0], l1[l1.size() - 1], l2[l2.size() - 1]);

    for (int i = 1; i < l1.size(); i++ ){

        DDA_line(l1[i],l2[i], l1[i - 1], l2[i - 1]);
    }
    return;

}



void MainWindow:: reflection(QList<int> &l1,QList<int> &l2, QString line, int x0, int y0){


    if (line == "y=x"){

        for (int i = 0; i < l1.size(); i++){

            int temp;
            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;

            temp = dx;
            dx = dy;
            dy = temp;

            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);


        }
    }
    else if ( line == "y=-x"){

        for (int i = 0; i < l1.size(); i++){

            int temp;
            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;

            temp = -dx;
            dx = -dy;
            dy = temp;

            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }
    }
    else if ( line == "x=0"){

        for (int i = 0; i < l1.size(); i++){

            int temp;
            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;

            dx *= -1;


            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }
    }
    else if ( line == "y=0"){

        for (int i = 0; i < l1.size(); i++){

            int temp;
            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;
            dy *= -1;
            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }
    }
    else{

        for (int i = 0; i < l1.size(); i++){

            int temp;
            int dx = l1[i] - x0;
            int dy = l2[i] - y0;
            dy *= -1;
            dy *= -1;
            dx *= -1;
            l1[i] = x0 + dx ;
            l2[i] = abs(y0 - dy);
        }
    }

    DDA_line(l1[0],l2[0], l1[l1.size() - 1], l2[l2.size() - 1]);

    for (int i = 1; i < l1.size(); i++ ){

        DDA_line(l1[i],l2[i], l1[i - 1], l2[i - 1]);
    }
    return;

}



void MainWindow::on_pushButton_clicked()
{
    float tx, ty;

    tx = ui->textEdit->toPlainText().toFloat();
    ty = ui->textEdit_2->toPlainText().toFloat();

    int x0,y0;

    x0 = ui->textEdit_3->toPlainText().toInt();
    y0 = ui->textEdit_4->toPlainText().toInt();


    trans(xpts, ypts,tx,ty,x0,y0);

     ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_2_clicked()
{
     int x0,y0;

     x0 = ui->textEdit_3->toPlainText().toInt();
     y0 = ui->textEdit_4->toPlainText().toInt();


     axesess(x0,y0);
     ui->label->setPixmap(QPixmap::fromImage(img));


}


void MainWindow::on_pushButton_3_clicked()
{
     float sx, sy;

     sx = ui->textEdit_5->toPlainText().toFloat();
     sy = ui->textEdit_6->toPlainText().toFloat();
     int x0,y0;

     x0 = ui->textEdit_3->toPlainText().toInt();
     y0 = ui->textEdit_4->toPlainText().toInt();

     scaling(xpts, ypts, sx,sy,x0,y0);

     ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_4_clicked()
{

     reset();
      ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_5_clicked()
{

    double theta;

    theta = ui->textEdit_7->toPlainText().toDouble();

    int x0,y0;

    x0 = ui->textEdit_3->toPlainText().toInt();
    y0 = ui->textEdit_4->toPlainText().toInt();

    rotate(xpts,ypts,theta,x0,y0);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_6_clicked()
{
    float shr;

    shr = ui->textEdit_9->toPlainText().toFloat();

    QString axis;

    axis = ui->textEdit_8->toPlainText();

    int x0,y0;

    x0 = ui->textEdit_3->toPlainText().toInt();
    y0 = ui->textEdit_4->toPlainText().toInt();

    shearing(xpts,ypts,shr, axis,x0,y0);

    ui->label->setPixmap(QPixmap::fromImage(img));


}


void MainWindow::on_pushButton_7_clicked()
{
    QString line;

    line = ui->textEdit_10->toPlainText();

    int x0,y0;

    x0 = ui->textEdit_3->toPlainText().toInt();
    y0 = ui->textEdit_4->toPlainText().toInt();

    reflection(xpts,ypts,line,x0,y0);

    ui->label->setPixmap(QPixmap::fromImage(img));


}

