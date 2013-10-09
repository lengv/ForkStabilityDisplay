#ifndef CANVAS_H
#define CANVAS_H

#include <QGLWidget>

class canvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = 0);
    
signals:
    
public slots:
    

protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();

    bool event(QEvent *event);

    void exposeEvent(QExposeEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    double xMin, xMax, yMin, yMax;
//    const int v1x;
//    const int v1y;
//    const int v2x;
//    const int v2y;
//    const int v3x;
//    const int v3y;
};

#endif // CANVAS_H
