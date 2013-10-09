#ifndef STABILITYBARCANVAS_H
#define STABILITYBARCANVAS_H

#include <QGLWidget>

class stabilityBarCanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit stabilityBarCanvas(QWidget *parent = 0);
    
signals:
    
public slots:
    
protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();

private:
    double xMin, xMax, yMin, yMax;


};

#endif // STABILITYBARCANVAS_H
