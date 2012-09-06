#include "myglwidget.h"
#include <QDebug>

MyGLWidget::MyGLWidget(QGLWidget *parent) :
    QGLWidget(parent)
{
    frames = 0;
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
    setAutoFillBackground(false);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start(10);

    time.start();
    time2.start();
}

void MyGLWidget::initializeGL()
{
    float cubePositionData[] = {
        //Front face
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,

        //Right face
        1.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,

        //Back face
        1.0f, 1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f,-1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,

        //Left face
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,

        //Top face
        -1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, -1.0f,

        //Bottom face
        1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f
    };
    for (int i = 0; i < 3 * 6 * 6; i+=3)
        mCubePositions.append(QVector3D(cubePositionData[i], cubePositionData[i+1], cubePositionData[i+2]));

    //R, G, B, A
    float cubeColorData[] = {
        //Front face(red)
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,

        //Right face(green)
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,

        //Back face(blue)
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,

        //Left face(yellow)
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,

        //Top face(cyan)
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,

        //Bottom face(magenta)
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 1.0f,
    };
    for (int i = 0; i < 4 * 6 * 6; i += 4)
        mCubeColors.append(QVector4D(cubeColorData[i], cubeColorData[i+1], cubeColorData[i+2], cubeColorData[i+3]));

    //X, Y, Z
    float cubeNormalData[] = {
        //Front face
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,

        //Right face
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        //Back face
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,
        0.0f, 0.0f, -1.0f,

        //Left face
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,

        //Top face
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,

        //Bottom face
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
    };
    for (int i = 0; i < 3 * 6 * 6; i += 3)
        mCubeNormals.append(QVector3D(cubeNormalData[i], cubeNormalData[i+1], cubeNormalData[i+2]));

    QGLShader *vshader = new QGLShader(QGLShader::Vertex, this);
    const char *vsrc =
            "uniform mat4 u_MVPMatrix; \n"
            "uniform mat4 u_MVMatrix; \n"
            "uniform vec3 u_LightPos; \n"
            "attribute vec4 a_Position; \n"
            "attribute vec4 a_Color; \n"
            "attribute vec3 a_Normal; \n"
            "varying vec4 v_Color; \n"
            "void main() \n"
            "{ \n"
            "vec3 modelViewVertex = vec3(u_MVMatrix * a_Position); \n"
            "vec3 modelViewNormal = vec3(u_MVMatrix * vec4(a_Normal, 0.0)); \n"
            "float distance = length(u_LightPos - modelViewVertex); \n"
            "vec3 lightVector = normalize(u_LightPos - modelViewVertex); \n"
            "float diffuse = max(dot(modelViewNormal, lightVector), 0.1); \n"
            "diffuse = diffuse * (1.0/(1.0 + (0.25 * distance * distance))); \n"
            "v_Color = a_Color * diffuse; \n"
            "gl_Position = u_MVPMatrix * a_Position; \n"
            "} \n";
    vshader->compileSourceCode(vsrc); //glShaderSource && glCompileShader

    QGLShader *fshader = new QGLShader(QGLShader::Fragment, this);
    const char *fsrc =
            "varying vec4 v_Color; \n"
            "void main(void) \n"
            "{ \n"
            " gl_FragColor = v_Color;\n"
            "} \n";
    fshader->compileSourceCode(fsrc);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
 //   glDepthRange(0, 5);
    glDepthFunc(GL_LEQUAL);
    mViewMatrix.lookAt(QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));

    program.addShader(vshader);//glAttachShader
    program.addShader(fshader);
    program.bindAttributeLocation("a_Position", 0);//glBindAttribLocation
    program.bindAttributeLocation("a_Color", 1);
    program.bindAttributeLocation("a_Normal", 2);
    program.link();//glLinkProgram


    QGLShader *pvshader = new QGLShader(QGLShader::Vertex, this);
    const char *pvsrc =
            "uniform mat4 u_MVPMatrix; \n"
            "attribute vec4 a_Position; \n"
            "void main() \n"
            "{ \n"
            "gl_Position = u_MVPMatrix * a_Position; \n"
            "gl_PointSize = 10.0; \n"
            "} \n";
    pvshader->compileSourceCode(pvsrc);

    QGLShader *pfshader = new QGLShader(QGLShader::Fragment, this);
    const char *pfsrc =
            "void main() \n"
            "{ \n"
            " gl_FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); \n"
            "} \n";
    pfshader->compileSourceCode(pfsrc);
    pointProgram.addShader(pvshader);
    pointProgram.addShader(pfshader);
    pointProgram.bindAttributeLocation("a_Position", 0);
    pointProgram.link();

    mLightPosInModelSpace = QVector4D(0.0f, 0.0f, 0.0f, 1.0f);
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    float ratio = (float)w/h;
    float left = -ratio;
    float right = ratio;
    float bottom = -1.0f;
    float top = 1.0f;
    float n = 1.0f;
    float f = 10.0f;

    mProjectionMatrix.frustum(left, right, bottom, top, n, f);
}

void MyGLWidget::drawCube()
{
    program.enableAttributeArray(mPositionHandle);
    program.setAttributeArray(mPositionHandle, mCubePositions.constData());
    program.enableAttributeArray(mColorHandle);
    program.setAttributeArray(mColorHandle, mCubeColors.constData());
    program.enableAttributeArray(mNormalHandle);
    program.setAttributeArray(mNormalHandle, mCubeNormals.constData());
    mMVPMatrix = mViewMatrix * mModelMatrix;
    program.setUniformValue(mMVMatrixHandle, mMVPMatrix);
    mMVPMatrix = mProjectionMatrix * mMVPMatrix;
    program.setUniformValue(mMVPMatrixHandle, mMVPMatrix);
    program.setUniformValue(mLightPosHandle, mLightPosInEyeSpace);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void MyGLWidget::drawLight()
{
    int pointMVPMatrixHandle = pointProgram.uniformLocation("u_MVPMatrix");
    int pointPositionHandle = pointProgram.attributeLocation("a_Position");
    pointProgram.setAttributeArray(pointPositionHandle, &mLightPosInModelSpace);
    mMVPMatrix = mViewMatrix * mLightModelMatrix;
    mMVPMatrix = mProjectionMatrix * mMVPMatrix;
    pointProgram.setUniformValue(pointMVPMatrixHandle, mMVPMatrix);
    glDrawArrays(GL_POINTS, 0, 1);
}

void MyGLWidget::paintGL()
{
    QPainter painter;
    painter.begin(this);

    painter.beginNativePainting();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Do a complete rotation every 10 seconds
    long t = time2.elapsed() % 10000L;
    float angleInDegrees = (float)(360.0f / 10000.0f) * (int)t;

    mMVPMatrixHandle = program.uniformLocation("u_MVPMatrix");//glGetUniformLocation
    mMVMatrixHandle = program.uniformLocation("u_MVMatrix");
    mLightPosHandle = program.uniformLocation("u_LightPos");
    mPositionHandle = program.attributeLocation("a_Position");//glGetAttribLocation
    mColorHandle = program.attributeLocation("a_Color");
    mNormalHandle = program.attributeLocation("a_Normal");

    mLightModelMatrix.setToIdentity();
    mLightModelMatrix.translate(0.0f, 0.0f, -10.0f);
    mLightModelMatrix.rotate(angleInDegrees, 0.0f, 1.0f, 0.0f);
    mLightModelMatrix.translate(0.0f, 0.0f, 3.0f);
    mLightPosInWorldSpace = mLightModelMatrix * mLightPosInModelSpace;
    mLightPosInEyeSpace = mViewMatrix * mLightPosInWorldSpace;


qDebug()<<mLightPosInEyeSpace;
    program.bind();//glUseProgram

    //Draw some cubes
    mModelMatrix.setToIdentity();
    mModelMatrix.translate(4.0f, 0.0f, -7.0f);
    mModelMatrix.rotate(angleInDegrees, 1.0f, 0.0f, 0.0f);
    drawCube();

    mModelMatrix.setToIdentity();
    mModelMatrix.translate(-4.0f, 0.0f, -7.0f);
    mModelMatrix.rotate(angleInDegrees, 0.0f, 1.0f, 0.0f);
    drawCube();

    mModelMatrix.setToIdentity();
    mModelMatrix.translate(0.0f, 4.0f, -7.0f);
    mModelMatrix.rotate(angleInDegrees, 0.0f, 0.0f, 1.0f);
    drawCube();

    mModelMatrix.setToIdentity();
    mModelMatrix.translate(0.0f, -4.0f, -7.0f);
    drawCube();

    mModelMatrix.setToIdentity();
    mModelMatrix.translate(0.0f, 0.0f, -5.0f);
    mModelMatrix.rotate(angleInDegrees, 1.0f, 1.0f, 0.0f);
    drawCube();

    program.release();//glUseProgram(0)

    pointProgram.bind();

    drawLight();

    pointProgram.release();


    painter.endNativePainting();

    QString framesPerSecond;
    framesPerSecond.setNum(frames/(time.elapsed()/1000.0), 'f', 2);

    painter.setPen(Qt::white);
    painter.drawText(20, 40, framesPerSecond + "fps");


    painter.end();

    swapBuffers();

    if (!(frames%100)) {
        time.start();
        frames = 0;
    }
    frames++;

}
