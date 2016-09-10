#include "device.h"

#include <QApplication>
#include "message.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#if 1
    Device *virtual_phone = Device::getInstance();
    app.installEventFilter(virtual_phone);
#endif

    return app.exec();
}
