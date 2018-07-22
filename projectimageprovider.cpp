#include "projectimageprovider.h"

#include "projectmanager.h"

ProjectImageProvider::ProjectImageProvider(ProjectManager *projectManager) :
    QQuickImageProvider(QQmlImageProviderBase::Image),
    mProjectManager(projectManager)
{
}

QImage ProjectImageProvider::requestImage(const QString &, QSize *size, const QSize &)
{
    const QImage image = mProjectManager->project()->exportedImage();
    *size = image.size();
    return image;
}
