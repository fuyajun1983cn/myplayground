#include "myglwidget.h"
#include <QDebug>

MyGLWidget::MyGLWidget(QGLWidget *parent) :
    QGLWidget(parent)
{
        frames = 0;
        setAttribute(Qt::WA_PaintOnScreen);
        setAttribute(Qt::WA_NoSystemBackground);
        setAutoBufferSwap(false);

        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
        timer->start(10);
}

void MyGLWidget::initializeGL()
{
    QGLShader *vshader = new QGLShader(QGLShader::Vertex, this);
    const char *vsrc =
            "attribute vec4 vPosition; \n"
            "uniform mediump mat4 matrix;\n"
            "void main()  \n"
            "{   \n"
            "  gl_Position = matrix*vPosition; \n"
            "} \n";
    vshader->compileSourceCode(vsrc); //glShaderSource && glCompileShader

    QGLShader *fshader = new QGLShader(QGLShader::Fragment, this);
    const char *fsrc =
        "precision mediump float;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
        "}\n";
    fshader->compileSourceCode(fsrc);//glShaderSource && glCompileShader

    program.addShader(vshader); //glAttachShader
    program.addShader(fshader); //glAttachShader
    program.link(); //glLinkProgram

    vertexAttr = program.attributeLocation("vPosition"); //glGetAttribLocation
    matrixUniform = program.uniformLocation("matrix");//glGetUniformLocation

    vertices<<QVector3D(0.0f, 0.5f, 0.0f)
            <<QVector3D(-0.5f, -0.5f, 0.0f)
            <<QVector3D(0.5f, -0.5f, 0.0f);
}

void MyGLWidget::paintGL()
{
    QPainter painter;
    painter.begin(this);

    painter.beginNativePainting();
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT );

    QMatrix4x4 modelview;
    modelview.rotate(frames, 0.0f, 0.0f, 1.0f); //glRotate

    program.bind(); //glUseProgram
    program.setUniformValue(matrixUniform, modelview);//glUniform1fv
    program.enableAttributeArray(vertexAttr); //glEnableVertexAttribArray
    program.setAttributeArray(vertexAttr, vertices.constData());//glVertexAttribPointer
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    program.disableAttributeArray(vertexAttr);//glDisableVertexAttribArray
    program.release();//glUseProgram(0)

    painter.endNativePainting();

    QString framesPerSecond;
    framesPerSecond.setNum(frames /(time.elapsed() / 1000.0), 'f', 2);

    painter.setPen(Qt::white);

    painter.drawText(20, 40, framesPerSecond + " fps");

    painter.end();

    swapBuffers();

    if (!(frames % 100)) {
        time.start();
        frames = 0;
    }
    frames ++;
}
