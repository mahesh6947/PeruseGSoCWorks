#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H



#include <QColor>
#include <QSettings>
#include <QUrl>



class ApplicationSettings : public QSettings
{
    Q_OBJECT
public:
    ApplicationSettings(QObject *parent = 0);


    bool loadLastOnStartup() const;
    void setLoadLastOnStartup(bool loadLastOnStartup);
    bool defaultLoadLastOnStartup() const;

    bool isGridVisible() const;
    void setGridVisible(bool isGridVisible);
    bool defaultGridVisible() const;

    QString defaultUndoShortcut() const;
    QString undoShortcut() const;
    void setUndoShortcut(const QString &shortcut);

    QString defaultRedoShortcut() const;
    QString redoShortcut() const;
    void setRedoShortcut(const QString &shortcut);

    QString defaultResizeCanvasShortcut() const;
    QString resizeCanvasShortcut() const;
    void setResizeCanvasShortcut(const QString &shortcut);

    QString defaultResizeImageShortcut() const;
    QString resizeImageShortcut() const;
    void setResizeImageShortcut(const QString &shortcut);

    QString defaultPenToolShortcut() const;
    QString penToolShortcut() const;
    void setPenToolShortcut(const QString &shortcut);

    QString defaultEraserToolShortcut() const;
    QString eraserToolShortcut() const;
    void setEraserToolShortcut(const QString &shortcut);

    QString defaultSelectionToolShortcut() const;
    QString selectionToolShortcut() const;
    void setSelectionToolShortcut(const QString &shortcut);

signals:
    void loadLastOnStartupChanged();
    void recentFilesChanged();
    void gridVisibleChanged();
    void rulersVisibleChanged();
    void guidesVisibleChanged();
    void guidesLockedChanged();
    void scrollZoomChanged();
    void checkerColour1Changed();
    void checkerColour2Changed();

    void quitShortcutChanged();
    void newShortcutChanged();
    void openShortcutChanged();
    void saveShortcutChanged();
    void saveAsShortcutChanged();
    void exportShortcutChanged();
    void closeShortcutChanged();
    void revertShortcutChanged();
    void undoShortcutChanged();
    void redoShortcutChanged();
    void flipHorizontallyShortcutChanged();
    void flipVerticallyShortcutChanged();
    void resizeCanvasShortcutChanged();
    void resizeImageShortcutChanged();
    void moveContentsShortcutChanged();
    void gridVisibleShortcutChanged();
    void rulersVisibleShortcutChanged();
    void guidesVisibleShortcutChanged();
    void centreShortcutChanged();
    void zoomInShortcutChanged();
    void zoomOutShortcutChanged();
    void splitScreenShortcutChanged();
    void splitterLockedShortcutChanged();
    void animationPlaybackShortcutChanged();
    void penToolShortcutChanged();
    void optionsShortcutChanged();
    void eyeDropperToolShortcutChanged();
    void fillToolShortcutChanged();
    void eraserToolShortcutChanged();
    void selectionToolShortcutChanged();
    void toolModeShortcutChanged();
    void decreaseToolSizeShortcutChanged();
    void increaseToolSizeShortcutChanged();
    void swatchLeftShortcutChanged();
    void swatchRightShortcutChanged();
    void swatchUpShortcutChanged();
    void swatchDownShortcutChanged();
};

#endif // APPLICATIONSETTINGS_H
