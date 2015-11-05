#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H

#include <QString>

class EchoInterface
{
public:
    virtual ~EchoInterface() {}
    virtual QString echo(const QString &message) = 0;
};

#define EchoInterface_iid "org.qt-project.Qt.Examples.EchoInterface"

Q_DECLARE_INTERFACE(EchoInterface, EchoInterface_iid)

#endif
