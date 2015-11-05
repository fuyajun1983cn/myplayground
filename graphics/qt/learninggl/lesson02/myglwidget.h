#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QVector>
#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
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
    void resizeGL(int w, int h);

private:
    void drawCube();
    void drawLight();

    QGLShaderProgram pointProgram;
    QGLShaderProgram program;

    int mMVPMatrixHandle;
    int mMVMatrixHandle;
    int mPositionHandle;
    int mLightPosHandle;
    int mColorHandle;
    int mNormalHandle;

    QVector<QVector3D> mCubePositions;
    QVector<QVector3D> mCubeNormals;
    QVector<QVector4D> mCubeColors;

    QMatrix4x4 mModelMatrix;
    QMatrix4x4 mViewMatrix;
    QMatrix4x4 mProjectionMatrix;
    QMatrix4x4 mMVPMatrix;
    QMatrix4x4 mLightModelMatrix;

    QVector4D mLightPosInWorldSpace;
    QVector4D mLightPosInEyeSpace;
    QVector4D mLightPosInModelSpace;

    int frames;
    QTime time;
    QTime time2;
    QTimer *timer;
    
};

#endif // MYGLWIDGET_H
