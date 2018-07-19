#include "projectmanager.h"
#include <QLoggingCategory>

#include "layeredimagecanvas.h"

Q_LOGGING_CATEGORY(lcProjectManger, "projectmanager")

ProjectManger::ProjectManager(QObject *parent) :QObject(parent)
{}

ProjectManager::~ProjectManager()
{
    qCDebug(lcProjectManager) << "destroying ProjectManager";
}

Project *ProjectManager::project() const
{
    return mProject.data();
}
