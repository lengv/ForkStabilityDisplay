#ifndef STABILITYBARCANVAS_H
#define STABILITYBARCANVAS_H

#include <QGLWidget>

class stabilityBarCanvas : public QGLWidget
{
    Q_OBJECT
public:
    explicit stabilityBarCanvas(QWidget *parent = 0);
    void set_db(double _db);

signals:
    
public slots:
    
protected:
    void initializeGL();
    void resizeGL(int x, int h);
    void paintGL();

private:
    double xMin, xMax, yMin, yMax;

    double db;
};

#endif // STABILITYBARCANVAS_H
