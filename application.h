#ifndef APPLICATION_H
#define APPLICATION_H

#include<QGuiApplication>
#include <QScopedPointer>
#include <QtQml>

#include "projectmanager.h"

class Application
{
public:
    Application(int &argc, char **argv, const QString &applicationName);
    ~Application();

    int run();

    //ApplicationSettings *settings() const;
     QQmlApplicationEngine *qmlEngine() const;
     ProjectManger *projectManager();

private:
    QScopedPointer<QGuiApplication> mApplication;
   // QScopedPointer<ApplicationSettings> mSettings;
    QScopedPointer<QQmlApplicationEngine> mEngine;
    ProjectManager mProjectManager;
};
