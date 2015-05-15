#include "coreplugin.h"
#include "mainwindow.h"

#include <QDebug>

using namespace Core;
using namespace Core::Internal;

CorePlugin::CorePlugin()
{
    m_mainWindow = new MainWindow;
}

CorePlugin::~CorePlugin()
{
    delete m_mainWindow;
}

bool CorePlugin::initialize(const QStringList &arguments, QString *errorMessage )
{
    qDebug()<<"Arguments: "<<arguments;

    const bool success = m_mainWindow->init(errorMessage);
    if (success) {
        qDebug("init mainwindow successfully!");
        m_mainWindow->resize(600, 480);
        m_mainWindow->show();
    }

    return success;
}

void CorePlugin::extensionsInitialized()
{
    m_mainWindow->extensionsInitialized();
}

bool CorePlugin::delayedInitialize()
{
    return true;
}

ExtensionSystem::IPlugin::ShutdownFlag CorePlugin::aboutToShutdown()
{
    return ExtensionSystem::IPlugin::aboutToShutdown();
}

QObject *CorePlugin::remoteCommand(const QStringList & options , const QStringList &args)
{
    return ExtensionSystem::IPlugin::remoteCommand(options, args);
}
