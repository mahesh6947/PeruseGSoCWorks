#ifndef PROJECT_H
#define PROJECT_H

#include <QImage>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QObject>
#include <QSize>
#include <QTemporaryDir>
#include <QUrl>

#include <QtUndo/undostack.h>

Q_DECLARE_LOGGING_CATEGORY(lcProject)
Q_DECLARE_LOGGING_CATEGORY(lcProjectLifecycle)

class ApplicationSettings;

class Project : public QObject
{
    Q_OBJECT

public:
    enum Type {
        UnknownType,
        TilesetType,
        ImageType,
        LayeredImageType

    };

    Q_ENUM(Type)

    Project();


    virtual Type type() const;
    QString typeString() const;
    static QString typeToString(Project::Type type);
    bool hasLoaded() const;
    bool isNewProject() const;
    void setNewProject(bool newProject);
    bool hasUnsavedChanges() const;
    bool canSave() const;

    QUrl url() const;
    void setUrl(const QUrl &url);
    QString displayUrl() const;
    QUrl dirUrl() const;
    QString fileBaseName() const;

    virtual QSize size() const;
    virtual void setSize(const QSize &size);


    virtual int widthInPixels() const;
    virtual int heightInPixels() const;

    QVector<Guide> guides() const;
    virtual void addGuide(const Guide &guide);
    virtual void moveGuide(const Guide &guide, int to);
    virtual void removeGuide(const Guide &guide);

    virtual int currentLayerIndex() const;


    Q_INVOKABLE virtual QImage exportedImage() const;

    UndoStack *undoStack();

    bool isComposingMacro() const;
    void beginMacro(const QString &text);
    void endMacro();
    void addChange(UndoCommand *undoCommand);
    void clearChanges();

    ApplicationSettings *settings() const;
    void setSettings(ApplicationSettings *settings);

    QJsonObject *cachedProjectJson();


signals:
    void projectCreated();
    void projectLoaded();
    void projectClosed();
    void loadedChanged();
    void newProjectChanged();
    void unsavedChangesChanged();
    void canSaveChanged();
    void urlChanged();
    void sizeChanged();
    void errorOccurred(const QString &errorMessage);
    void settingsChanged();
    void guidesChanged();
    void readyForWritingToJson(QJsonObject *projectJson);



public slots:
    virtual void load(const QUrl &url);
    virtual void close();
    virtual void save();
    virtual void saveAs(const QUrl &url);
    virtual void revert();

protected:
    void error(const QString &message);

    void setComposingMacro(bool composingMacro);

    QUrl createTemporaryImage(int width, int height, const QColor &colour);

    void readGuides(const QJsonObject &projectJson);
    void writeGuides(QJsonObject &projectJson) const;


    ApplicationSettings *mSettings;

    bool mFromNew;
    QUrl mUrl;
    QTemporaryDir mTempDir;
    bool mUsingTempImage;

    QJsonObject mCachedProjectJson;

    UndoStack mUndoStack;
    bool mComposingMacro;
    bool mHadUnsavedChangesBeforeMacroBegan;

    QVector<Guide> mGuides;


};










