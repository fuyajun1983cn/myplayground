#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QVector>
#include <QVector3D>
#include <QTime>
#include <QTimer>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QGLWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();

private:
        QGLShaderProgram program;
        QVector<QVector3D> vertices;
        int frames;
        int vertexAttr;
        int normalAttr;
        int matrixUniform;

        QTime time;
        QTimer *timer;
};

#endif // MYGLWIDGET_H
