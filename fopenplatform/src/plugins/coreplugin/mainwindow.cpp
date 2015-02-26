#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plugindialog.h"

using namespace Core;
using namespace Core::Internal;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->AboutPlugin, SIGNAL(triggered()), this, SLOT(on_AboutPlugin_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init(QString *errorMessage)
{
    Q_UNUSED(errorMessage);
    qDebug("in MainWindow init method");

    return true;
}

void MainWindow::extensionsInitialized()
{

}

void MainWindow::aboutToShutdown()
{

}

void MainWindow::on_AboutPlugin_triggered()
{
    PluginDialog dlg(this);
    dlg.show();
}
