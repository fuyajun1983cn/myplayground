#include <extensionsystem/iplugin.h>
#include <extensionsystem/pluginerroroverview.h>
#include <extensionsystem/pluginmanager.h>
#include <extensionsystem/pluginspec.h>


#include <QDebug>
#include <QDir>
#include <QList>
#include <QApplication>

using namespace ExtensionSystem;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PluginManager pluginManager;
    QStringList pluginPaths;
    PluginManager::setPluginPaths(pluginPaths<<"plugins");

    const QList<PluginSpec*> plugins = PluginManager::plugins();
    PluginSpec *coreplugin = 0;
    foreach(PluginSpec *spec, plugins) {
        if (spec->name() == QLatin1String("Core")) {
                coreplugin = spec;
                break;
        }
    }

    if (!coreplugin) {
        QString nativePaths = QDir::toNativeSeparators(pluginPaths.join(QLatin1String(",")));
        const QString reason = QCoreApplication::translate("Application", "Could not find 'Core.xml' in %1").arg(nativePaths);
        qCritical("%s", qPrintable(reason));
        return 1;
    }
    if (coreplugin->hasError()) {
        qCritical("%s", qPrintable(coreplugin->errorString()));
        return 1;
    }
    qDebug("loading Plugins...");
    PluginManager::loadPlugins();
    if (coreplugin->hasError()) {
       qCritical("Error: %s", qPrintable(coreplugin->errorString()));
        return 1;
    }
    if (PluginManager::hasError()) {
        PluginErrorOverview *errorOverview = new PluginErrorOverview(QApplication::activeWindow());
        errorOverview->setAttribute(Qt::WA_DeleteOnClose);
        errorOverview->setModal(true);
        errorOverview->show();
    }

    QObject::connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    // shutdown plugin manager on the exit
    QObject::connect(&app, SIGNAL(aboutToQuit()), &pluginManager, SLOT(shutdown()));

    return app.exec();
}
