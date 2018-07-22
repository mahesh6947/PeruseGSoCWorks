#ifndef PROJECTIMAGEPROVIDER_H
#define PROJECTIMAGEPROVIDER_H

#include <QImage>
#include <QString>
#include <QQuickImageProvider>

class ProjectManager;

class ProjectImageProvider : public QQuickImageProvider
{
public:
    ProjectImageProvider(ProjectManager *projectManager);
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

private:
    ProjectManager *mProjectManager;
};

#endif // PROJECTIMAGEPROVIDER_H
