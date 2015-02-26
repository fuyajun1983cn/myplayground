#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

class Device : public QObject
{
    Q_OBJECT
public:
    static Device *getInstance();

protected:
    virtual bool eventFilter(QObject *, QEvent *);

private:
    Device();
    ~Device();
};

#endif // DEVICE_H
