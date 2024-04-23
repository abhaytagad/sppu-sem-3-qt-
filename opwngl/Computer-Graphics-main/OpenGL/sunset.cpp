#include<iostream>
#include<stdlib.h>
 
#include<GL/glut.h>

using namespace std;

float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
float colR=1;
float colG=0;
float colB = 0;
float G = 0;
float bgColR = 0.0;
float bgColG=0.0;
float bgColB=0.0;

static int flag=1;

void drawBall(void) {

        glColor3f(colR,colG,colB); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.1, 30, 30); //create ball.

}

void drawAv(void) {

        glBegin(GL_POLYGON);
        
        glColor3f(0,G,0);
   
        glVertex3f(-0.9,-0.7,-1.0);

        glVertex3f(-0.7,-0.1,-1.0);

        glVertex3f(-0.2,-1.0,-1.0);

        glVertex3f(-0.3,0.0,-1.0);

        glVertex3f(0.5, -0.7, -1.0);


        glVertex3f(1.5, -0.7, -1.0);
        glVertex3f(0.5, 0.0, -1.0);
        glVertex3f(0.5,-0.6,-1.0);


    glEnd();

}





//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}



void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // it will clear the output of previous window
    glClearColor(bgColR,bgColG,bgColB,0.0);
    glMatrixMode(GL_MODELVIEW); // it will gives the info about current matrix 
   
   
    //drawing the SUN

    glPushMatrix(); //The glPushMatrix function pushes the current matrix stack down by one, duplicating the current matrix
        drawBall();
    glPopMatrix();  // The glPopMatrix function pops the current matrix stack, replacing the current matrix with the one below it on the stack
        
    //drawing the Mount Avarest
    glPushMatrix();
        drawAv();
    glPopMatrix();

    glutSwapBuffers();
}


void update(int value) {
   
    if(ballX>0.9f)
    {
        ballX = -0.8f;
        ballY = -0.3f;

        colR=1;
        colG = 0;
        G = 0;
        colB = 0;
        bgColR=0.0;
        bgColG=0.0;
        bgColB = 0.0;
        
    }
   
    if(flag)
    {
        
        ballX += 0.001f;
        ballY +=0.0007f;
        colG += 0.001;
        G += 0.001;
        bgColB += 0.001;
        

       if(ballX>0.01)
       {
           flag=0;

       }

    }
    if (!flag)
    {

        ballX += 0.001f;
        ballY -=0.0007f;
        colG -= 0.001;
        G -= 0.001;
        bgColB-=0.001;

        if(ballX<-0.3)
       {
            flag = 1;
        }

        
    }
   
    glutPostRedisplay(); //Tell GLUT that the display has changed
   
    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(30, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
   
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   
    glutInitWindowSize(400,400);
   
    glutCreateWindow("Sun");
   
    glutDisplayFunc(drawScene);

    glutFullScreen();
    glutReshapeFunc(handleResize);

    glutTimerFunc(30, update, 0);

    glutMainLoop();
   
    return(0);
}