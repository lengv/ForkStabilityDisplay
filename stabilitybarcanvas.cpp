#include "stabilitybarcanvas.h"

stabilityBarCanvas::stabilityBarCanvas(QWidget *parent) :
    QGLWidget(parent)
{
    xMin = 0;
    xMax = 4;
    yMin = 0;
    yMax = 10;
    db = 1;
}

void stabilityBarCanvas::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);   // Clear colour buffer
    glClearDepth(1.0f);                     // Clear Depth buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void stabilityBarCanvas::resizeGL(int width, int height)
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
    close();
}

void stabilityBarCanvas::paintGL()
{
    float mult = 0.8;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(0.0, -4.0, 0.0);
    glLineWidth(1);
    glColor3f(1.0f*(1-mult), 1.0f*mult, 0.05f);

    glBegin(GL_POLYGON);
        glVertex2f(1,1);
        glVertex2f(3,1);
        glVertex2f(3,9*mult+1);
        glVertex2f(1,9*mult+1);
    glEnd();

    glLineWidth(2);
    glColor3f(0, 1, 0);



//    glBegin(GL_LINE_LOOP);

//            glVertex2f(-3,3);
//    glEnd();
}

void stabilityBarCanvas::set_db(double _db)
{
    db = _db;
}
