#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class QTimer;
class QKeyEvent;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void keyPressEvent(QKeyEvent *);
    void closeEvent(QCloseEvent *);

private:
    QTimer *timer;

    bool fullscreen;

    GLfloat     rtri;                       // Angle For The Triangle ( NEW )
    GLfloat     rquad;                      // Angle For The Quad     ( NEW )
};

#endif // MYGLWIDGET_H
