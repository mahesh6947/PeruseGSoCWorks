#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>>
#include <QScopedPointer>

class ProjectManger : public QObject
{


public:
    explicit ProjectManager(QObject *parent = 0);
    ~ProjectManager();

  //  Project *project() const;

   // Project *temporaryProject() const;


    bool isReady() const;
    void setReady(bool ready);

signals:
    void projectChanged();

    void temporaryProjectChanged();


    void creationFailed(const QString &errorMessage);

public slots:
    void onCreationFailed(const QString &errorMessage);
    void projectUrlChanged();


}


#endif // PROJECTMANAGER_H
