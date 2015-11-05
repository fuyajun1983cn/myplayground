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
    void keyReleaseEvent(QKeyEvent *);
    void closeEvent(QCloseEvent *);

private:

    void loadTextures();

    QTimer *timer;

    bool fullscreen;
};

#endif // MYGLWIDGET_H
