#include"changeimagesizecommand.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(lcChangeImageSizeCommand, "app.undo.ChangeImageSizeCommand")
ChangeImageSizeCommand::ChangeImageSizeCommand(ImageProject *project, const QImage &previousImage,const QImage &newImage, UndoCommand *parent)
    :UndoCommand(parent),
      mProject(project),
      mPreviousImage(previousImage),
      mNewImage(newImage)
{
    qCDebug(lcChangeImageSizeCommand) << "constructed" << this;
}
void ChangeImageSizeCommand::undo()
{
    qCDebug(lcChangeImageSizeCommand) << "undoing" << this;
    mProject->doSetImageSize(mPreviousImage);
}

QDebug operator<<(QDebug debug, const ChangeImageSizeCommand *command)
{
    debug.nospace() << "(ChangeImageSizeCommand new size=" << command->mNewImage.size()
        << "previous size=" << command->mPreviousImage.size()
        << ")";
    return debug.space();
}
