#ifndef CHANGEIMAGESIZECOMMAND_H
#define CHANGEIMAGESIZECOMMAND_H

#include <QDebug>
#include <QImage>
#include <QtUndo/undocommand.h>

class ImageProject;

class ChangeImageSizeCommand : public UndoCommand
{
    Q_OBJECT

public:
    ChangeImageSizeCommand(ImageProject *project, const QImage &previousImage, const QImage &newImage,
        UndoCommand *parent = nullptr);

    void undo() override;
    void redo() override;

    int id() const override;

private:
    friend QDebug operator<<(QDebug debug, const ChangeImageSizeCommand *command);

    ImageProject *mProject;
    QImage mPreviousImage;
    QImage mNewImage;
};



#endif // CHANGEIMAGESIZECOMMAND_H
