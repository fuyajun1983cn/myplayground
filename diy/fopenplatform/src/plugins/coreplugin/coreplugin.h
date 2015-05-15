#ifndef COREPLUGIN_H
#define COREPLUGIN_H

#include <extensionsystem/iplugin.h>

namespace Core {

namespace Internal {

class MainWindow;

class CorePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.fyj.test.CorePlugin" /*FILE "Core.json"*/)

public:
    CorePlugin();
    ~CorePlugin();

    bool initialize(const QStringList &arguments, QString *errorMessage = 0);
    void extensionsInitialized();
    bool delayedInitialize();
    ExtensionSystem::IPlugin::ShutdownFlag aboutToShutdown();
    QObject *remoteCommand(const QStringList & /* options */, const QStringList &args);

private:
    MainWindow *m_mainWindow;
};

}

}
#endif // COREPLUGIN_H
