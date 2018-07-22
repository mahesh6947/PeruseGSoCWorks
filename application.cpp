#include "application.h"

#include <QApplication>
#include <QFontDatabase>
#include <QLoggingCategory>
#include <QQmlFileSelector>


#include"canvaspane.h"
#include"addlayercommand.h"
#include"changeimagesizecommand.h"
#include"changelayerordercommand.h"
#include"imagecanvas.h"
#include "imagelayer.h"
#include "layeredimagecanvas.h"
#include "projectmanager.h"
#include "projectimageprovider.h"


Q_LOGGING_CATEGORY(lcApplication, "app.application")

static QGuiApplication *createApplication(int &argc, char **argv, const QString &applicationName)
{
    QLoggingCategory::setFilterRules("app.* = False");
    QGuiApplication::setAttribute(Qt::EnableHighDpiScaling);
    QApplication *app = new QApplication(argc, argv);
    app->setApplicationName(applicationName);
    return app;
}

Application::Application(int &argc, char **argv, const QString &applicationName) :
    mApplication(createApplication(argc, argv, applicationName)),
    mSettings(new ApplicationSettings),
    mEngine(new QQmlApplicationEngine)
{

    mEngine->addImageProvider("ProjectImage", new ProjectImageProvider(&mProjectManager));
    mEngine->rootContext()->setContextProperty("projectManager", &mProjectManager);
    mEngine->rootContext()->setContextProperty("settings", mSettings.data());

    qCDebug(lcApplication) << "Loading main.qml...";
    mEngine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    qCDebug(lcApplication) << "... loaded main.qml";
    Q_ASSERT(!mEngine->rootObjects().isEmpty());

}
Application::~Application()
{

    mEngine.reset();
}

int Application::run()
{
    return mApplication->exec();
}

ApplicationSettings *Application::settings() const
{
    return mSettings.data();
}

QQmlApplicationEngine *Application::qmlEngine() const
{
    return mEngine.data();
}

ProjectManager *Application::projectManager()
{
    return &mProjectManager;
}
