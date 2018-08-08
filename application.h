
#define APPLICATION_H

#include<QGuiApplication>
#include <QScopedPointer>
#include <QtQml>

#include "projectmanager.h"
#include "applicationsettings.h"

class Application
{
public:
    Application(int &argc, char **argv, const QString &applicationName);
    ~Application();

    int run();

   ApplicationSettings *settings() const;
     QQmlApplicationEngine *qmlEngine() const;
     ProjectManager *projectManager();

private:
    QScopedPointer<QGuiApplication> mApplication;
    QScopedPointer<ApplicationSettings> mSettings;
    QScopedPointer<QQmlApplicationEngine> mEngine;
    ProjectManager mProjectManager;
};
