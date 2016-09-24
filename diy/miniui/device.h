#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QList>

class QPainter;
struct DrawingItem;

class Device : public QObject
{
    Q_OBJECT
public:
    static Device *getInstance();
    void addDrawingItem(struct DrawingItem*);

protected:
    virtual bool eventFilter(QObject *, QEvent *);

protected slots:
    void test();

private:
    Device();
    ~Device();
    void drawStuff(QPainter*);

private:
    QList<DrawingItem*> items;
};

#endif // DEVICE_H
