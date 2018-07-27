#include <QDebug>
#include <QFile>
#include <QKeySequence>
#include <QLoggingCategory>
#include <QVector>

Q_LOGGING_CATEGORY(lcApplicationSettings, "Applicationsettings")

ApplicationSettings::ApplicationSettings(QObject *parent) :
    QSettings(parent)
{
    qCDebug(lcApplicationSettings) << "Loading settings from" << fileName();
}


bool ApplicationSettings::loadLastOnStartup() const
{
    return contains("loadLastOnStartup") ? value("loadLastOnStartup").toBool() : defaultLoadLastOnStartup();
}



