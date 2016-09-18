#include "device.h"

#include <QApplication>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPushButton>
#include <QLayout>
#include <QDebug>

//http://blog.csdn.net/vince025/article/details/17552497

#ifdef Q_OS_LINUX
#include <X11/extensions/shape.h>
#endif
#ifdef Q_OS_WIN
#include <windows.h>
#endif

static QWidget *pMainScreen = 0;

Device::Device()
{
    pMainScreen = new QWidget(0, Qt::FramelessWindowHint
                              | Qt::WindowSystemMenuHint);
    pMainScreen->setAttribute(Qt::WA_InputMethodEnabled);
    QPushButton *btn = new QPushButton(pMainScreen);
    btn->setText("This is a Button");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(btn);
    pMainScreen->setLayout(layout);
#if 0
    QPalette pal = pMainScreen->palette();
    pal.setColor(QPalette::Background, QColor(100,100,100,0));
    pMainScreen->setPalette(pal);
    pMainScreen->setAutoFillBackground(true);
#endif
    pMainScreen->setAttribute(Qt::WA_TranslucentBackground, true);
#ifdef Q_OS_LINUX
    XShapeCombineRectangles(QX11Info::display(), winId(), ShapeInput, 0,
                                0, NULL, 0, ShapeSet, YXBanded);
#endif
#ifdef Q_OS_WIN
        SetWindowLong(winId(), GWL_EXSTYLE, GetWindowLong(winId(), GWL_EXSTYLE) |
                      WS_EX_TRANSPARENT | WS_EX_LAYERED);
#endif
//    pMainScreen->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    QFont ft = pMainScreen->font();
    ft.setPointSize(20);
    pMainScreen->setFont(ft);
//    pMainScreen->resize(300, 460);
 //   pMainScreen->show();
    pMainScreen->showFullScreen();
}

Device::~Device()
{

}

Device* Device::getInstance()
{
    static Device instance;
    return &instance;
}

bool Device::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Paint && object == pMainScreen) {

        qDebug()<<"Screen Width: "<<pMainScreen->geometry().width();
        qDebug()<<"Screen Height: "<<pMainScreen->geometry().height();

        QPainter p(pMainScreen);
        p.fillRect(pMainScreen->rect(), QColor(0,0xff,0,60));

        return true;
    } else if (event->type() == QEvent::KeyRelease) {
        int key = ((QKeyEvent*)event)->key();
        if (key == Qt::Key_Escape) {
            qApp->quit();
            return true;
        }
    }
    return false;
}
