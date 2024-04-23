#include "mainwindow.h"
#include "./ui_mainwindow.h"



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





QList<int> temp1;
QList<int> temp2;


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




void MainWindow::reset(int x1, int y1, int x2, int y2){

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

        img.setPixel(x,y,qRgb(0,0,0));
        x = x + xinc;
        y = y + yinc;
        i++;

    }
}




QList<int> xpts;
QList<int> ypts;
int x_min = 501,y_min = 501,x_max = 0,y_max = 0;


void MainWindow:: rectangle(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4){

    dda(x1,y1,x2,y2);
    dda(x1,y1,x4,y4);
    dda(x3,y3,x2,y2);
    dda(x4,y4,x3,y3);



    xpts.append(x1);
    xpts.append(x2);
    xpts.append(x3);
    xpts.append(x4);
    ypts.append(y1);
    ypts.append(y2);
    ypts.append(y3);
    ypts.append(y4);

}


QString MainWindow:: Code(int x, int y){

    QString  code;

    for (int i = 0; i < xpts.size(); i++){

        if (x_max < xpts[i]){
            x_max = xpts[i];
        }
        if (x_min > xpts[i]){
            x_min = xpts[i];
        }
        if (y_max < ypts[i]){
            y_max = ypts[i];
        }
        if (y_min > ypts[i]){
            y_min = ypts[i];
        }

    }


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









void MainWindow:: sutherland(int x1, int  y1, int x2, int y2,int bcolor){
    int a = 0, b = 0;

    QString c1 = Code(x1,y1);
    QString c2 = Code(x2, y2);
    bool fla = true;
    for (int i = 0; i < c1.length(); i++){

        if (c1[i] != '0' && c2[i] != '0'){

            return;

        }
    }



    if (x1 == x2){

        int y = ypts[0];

        for (int i = 1; i < ypts.size(); i++){

            if (ypts[i] != y){

                //dda(x1, y, x1,ypts[i]);
                temp1.append(x1);
                temp1.append(x1);
                temp2.append(y);
                temp2.append(ypts[i]);
                return;

            }

        }
    }



    double dy = y2-y1;

    double slope = (dy)/(x2-x1);


    for (int i = 0; i < xpts.size(); i++){

        float y = (slope * (xpts[i] - x1)) + y1;



        if (y >0 and y < 500){

            if (img.pixelColor(xpts[i], y) != bcolor){

                if (a == 0 && b == 0){

                    a = xpts[i];
                    b = y;

                    temp1.append(xpts[i]);
                    temp2.append(y);
                }
                else {

                    //dda(a,b ,xpts[i], y);
                    temp1.append(xpts[i]);
                    temp2.append(y);
                }
            }
        }
    }



    for (int i = 0; i < ypts.size(); i++){

        int x = x1 + ((ypts[i] - y1)/slope);

        if (x >0 and x < 500){

            if (img.pixelColor(x, ypts[i]) != bcolor){

                if (a == 0 && b == 0){

                    a = x;
                    b = ypts[i];

                    temp1.append(x);
                    temp2.append(ypts[i]);
                }
                else {

                    //dda(a,b ,x,ypts[i]);

                    temp1.append(x);
                    temp2.append(ypts[i]);
                }
            }
        }

    }
}



void MainWindow::on_pushButton_clicked()
{

    int x1,x2,x3,x4,y1,y2,y3,y4;

    x1 = ui->textEdit->toPlainText().toInt();
    x2 = ui->textEdit_2->toPlainText().toInt();
    x3 = ui->textEdit_3->toPlainText().toInt();
    x4 = ui->textEdit_4->toPlainText().toInt();
    y1 = ui->textEdit_5->toPlainText().toInt();
    y2 = ui->textEdit_6->toPlainText().toInt();
    y3 = ui->textEdit_7->toPlainText().toInt();
    y4 = ui->textEdit_8->toPlainText().toInt();

    rectangle(50,50,400,50,400,400,50,400);

    ui->label->setPixmap(QPixmap::fromImage(img));


}


void MainWindow::on_pushButton_2_clicked()
{

    int  x2,y2;

    int x1 = ui->textEdit->toPlainText().toInt();
    x2 = ui->textEdit_2->toPlainText().toInt();
    int y1 = ui->textEdit_5->toPlainText().toInt();
    y2 = ui->textEdit_6->toPlainText().toInt();

   dda(x1,y1 ,x2,y2);

   sutherland(x1,y1,x2,y2,0);

   ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked()
{
    int  x2,y2;

    int x1 = ui->textEdit->toPlainText().toInt();
    x2 = ui->textEdit_2->toPlainText().toInt();
    int y1 = ui->textEdit_5->toPlainText().toInt();
    y2 = ui->textEdit_6->toPlainText().toInt();

    reset(x1,y1,x2,y2);


    for (int i = 0; i< temp1.size(); i++){

        for(int j = 0; j < temp1.size(); j++){

            dda(temp1[i],temp2[i],temp1[j],temp2[j]);
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(img));

}

