#include "canvas.h"
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

canvas::canvas(QWidget *parent) :
    QGLWidget(parent)
{
    xMin = 0;
    xMax = 10;
    yMin = 0;
    yMax = 10;
    xZMP = 0;
    yZMP = 0;
}


void canvas::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);   // Clear colour buffer
    glClearDepth(1.0f);                     // Clear Depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void canvas::resizeGL(int width, int height)
{

    glViewport(0,0,(GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
    if (width > height){
    height = height?height:1;
    double newWidth = (xMax - xMin) * width / height;
    double difWidth = newWidth - (xMax - xMin);
    xMin = 0.0 + difWidth / 2.0;
    xMax = 10 + difWidth / 2.0;
    } else {
    width = width?width:1;
    double newHeight = (yMax - yMin) * width / height;
    double difHeight = newHeight - (yMax - yMin);
    yMin = 0.0 + difHeight / 2.0;
    yMax = 10 + difHeight / 2.0;
    }
    glOrtho(xMin, xMax, yMin, yMax,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(5.0, 5.0, 0.0);
    glLineWidth(3);

    double db = 0.5;

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f+(1-db), db, 0.0f);
    glVertex2f(-3,3);
    glColor3f(0.0f+(1-db), db, 0.0f);
    glVertex2f(3,3);
    glColor3f(0.0f+(1-db), db, 0.0f);
    glVertex2f(0,-3);
    glEnd();

    glLineWidth(2);
    glColor3f(0, 1, 0);

    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(xZMP,yZMP);
    glEnd();

//    glBegin(GL_LINE_LOOP);
    //GL_POLYGON

//            glVertex2f(-3,3);
//    glEnd();
}
