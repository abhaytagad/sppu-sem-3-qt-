#include<GL/glut.h>
#include<math.h>
#include <iostream>


float radius = 0.1;
float a1 = 0.7;
float a2 = 0.7;
float c1 = -0.7;
float b2 = -0.7;
float d1 = -0.7;
GLfloat xspeed = 0.02, yspeed = 0.007;
float x1 = -0.2, x2 = 0.2;
float x = 0, y = 0, z = 0;
bool flag = true;
int score = 0;



void Window() {

    

    glBegin(GL_LINE_LOOP);

    glColor3f(0, 1, 0);

    glVertex2f(a1, a2);

    glColor3f(0, 1, 0);

    glVertex2f(a1, b2);

    glColor3f(0, 1, 0);

    glVertex2f(c1, b2);

    glColor3f(0, 1, 0);

    glVertex2f(d1, a2);

    glEnd();
    glFlush();
}



void keyPress(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT) {

        if (x2 >= a1) {

            return;
        }

        x1 += 0.05f;
        x2 += 0.05f;

    }
       
    if (key == GLUT_KEY_LEFT) {

         if (x1 <= d1) {

            return;
        }


        x1 -= 0.05f;
        x2 -= 0.05f;

    }

    if (key == GLUT_KEY_END) {

        flag = true;

        xspeed = 0.02;
        yspeed = 0.007;
        x = 0;
        y = 0;
        z = 0;


    }



    glutPostRedisplay();
}


void line() {

    glLineWidth(3);
    glBegin(GL_LINES);


    glColor3f(0, 1, 0);

    glVertex2f(x1, -0.4);
    glVertex2f(x2, -0.4);

    glEnd();
    glFlush();
  
}





void ball() {

    glColor3f(1, 0, 0);
    if (flag) {

        glTranslated(x, y, z);
    }
    
    glutSolidSphere (radius, 30, 30);
    glFlush();

}

void scor() {


    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);  // Set up a 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();


    glColor3f(1.0f, 1.0f, 1.0f); 
    glRasterPos2f(0.0, 0);

    std::string scoreString = "Score: " + std::to_string(score);

    // Display each character of the string
    for (char c : scoreString) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

}

void draw() {

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    
    glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();


    glPushMatrix();
        ball();
    glPopMatrix();
        
    glPushMatrix();
        Window();
    glPopMatrix();

    glPushMatrix();
        line();
    glPopMatrix();
   

}




void update(int value) {



    if (xspeed < 0) {

        xspeed -= 0.000001;
    }
    else {
        xspeed += 0.000001;
    }

    if (yspeed < 0) {

        yspeed -= 0.000001;
    }
    else {
        yspeed += 0.000001;
    }


    y += yspeed;
    x += xspeed;

   

    if (x + radius > a1) {
            
        xspeed = -xspeed;
    }
    else if (x - radius < d1) {
       
        xspeed = -xspeed;
    }

    if (y + radius > a2) {
        
        yspeed = -yspeed;
    }
   

    if (x <= x2 + 0.1 && x >= x1 - 0.1 ) {

        if (y - 0.1 <= -0.4) {

            yspeed = -yspeed;
        }
    }

    if (y - 0.1 < -0.42) {

        flag = false;
    }


    glutPostRedisplay(); //Tell GLUT that the display has change

        //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);

}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
   
    glutInitDisplayMode(GL_COLOR_BUFFER_BIT);
   
    glutInitWindowSize(700,700);
   
    glutCreateWindow("Abhay");

    glutDisplayFunc(draw);
    glutFullScreen();
    glutSpecialFunc(keyPress);
    
    glutTimerFunc(30, update, 0);

    glutMainLoop();
   
    return(0);
}