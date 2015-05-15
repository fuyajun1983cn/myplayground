#include "device.h"

#include <QApplication>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

static QWidget *pMainScreen = 0;

Device::Device()
{
    pMainScreen = new QWidget(0, Qt::FramelessWindowHint
                              | Qt::WindowSystemMenuHint);
    pMainScreen->setAttribute(Qt::WA_InputMethodEnabled);
    QFont ft = pMainScreen->font();
    ft.setPointSize(20);
    pMainScreen->setFont(ft);
    pMainScreen->resize(300, 460);
    pMainScreen->show();
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
