#include "device.h"

#include <QApplication>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>

//Test
#include <QPushButton>
#include <QVBoxLayout>

#include <QStaticText>
struct DrawingItem
{
    enum ItemType {
        RECT,
        TEXT,
        IMG,
        ItemType_NUM,
    } eType;

    union {
        struct {
            int x, y;
            int width, height;
            struct {
                int r,g,b,a;
            } backgroundColor;
        }eRect;

        struct {
            const char *text;
            int x, y;
        }eText;

        struct {
            const char *path;
            int x,y;
        }eImage;
    };
};

static QWidget *pMainScreen = 0;

Device::Device()
{
    pMainScreen = new QWidget(0, Qt::FramelessWindowHint
                              | Qt::WindowSystemMenuHint);
    pMainScreen->setAttribute(Qt::WA_TranslucentBackground, true);


    QPushButton *btn = new QPushButton(0);
    btn->setText("Test");
    QVBoxLayout *layout = new QVBoxLayout(pMainScreen);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(test()));


    QFont ft = pMainScreen->font();
    ft.setPointSize(20);
    pMainScreen->setFont(ft);
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

 //       qDebug()<<"Screen Width: "<<pMainScreen->geometry().width();
 //       qDebug()<<"Screen Height: "<<pMainScreen->geometry().height();

        QPainter p(pMainScreen);
        p.fillRect(pMainScreen->rect(), QColor(0,0xff,0,60));

        drawStuff(&p);

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

void Device::test()
{
#if 1
    {
    DrawingItem *rect = new DrawingItem();
    rect->eType = DrawingItem::RECT;
    rect->eRect = {300, 300, 300, 400, {0,0,0xff,0xff}};
    addDrawingItem(rect);
    }
#endif

#if 1
    {
    DrawingItem *rect = new DrawingItem();
    rect->eType = DrawingItem::RECT;
    rect->eRect = {100, 100, 300, 400, {0xff, 0, 0, 0xff}};
    addDrawingItem(rect);
    }
#endif
}

void Device::addDrawingItem(struct DrawingItem*item)
{
    if (item != NULL) {
        items.push_back(item);
        qDebug("Adding Drawing Item");
        pMainScreen->update();
    }
}

void Device::drawStuff(QPainter *p)
{
    qDebug()<<"Drawing Stuffs";
    while (!items.empty()) {
        DrawingItem *item = items.front();
        switch (item->eType) {
        case DrawingItem::RECT:
            qDebug("Drawing Rect");
            p->fillRect(item->eRect.x, item->eRect.y,
                                        item->eRect.width, item->eRect.height,
                                        QColor(item->eRect.backgroundColor.r,
                                               item->eRect.backgroundColor.g,
                                               item->eRect.backgroundColor.b,
                                               item->eRect.backgroundColor.a));
            break;t
        case DrawingItem::TEXT:
            p->drawStaticText(item->eText.x,
                                                item->eText.y,
                                                QStaticText(item->eText.text));
            break;
        case DrawingItem::IMG:

            break;
        default:
            break;
        }
         items.pop_front();
        free(item);
        item = NULL;
    }
}
