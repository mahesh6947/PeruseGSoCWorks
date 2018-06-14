
#include"changelayerordercommand.h"
#include"include/QtCore/QLoggingCategory"

Q_LOGGING_CATEGORY(lcChangeLayerOrderCommand, "app.undo.changeLayerOrderCommand")

ChangeLayerOrderCommand(LayeredImageProject *project, int previousIndex, int newIndex, UndoCommand *parent)
   :
    UndoCommand(parent),
    mProject(project),
    mPreviousIndex(previousIndex),
    mNewIndex(newIndex)
{
    qCDebug(lcChangeLayerOrderCommand) << "constructed" << this;
}

void ChangeLayerOrderCommand::undo()
{
    qCDebug(lcChangeLayerOrderCommand) << "undoing" << this;
    mProject->moveLayer(mNewIndex, mPreviousIndex);
}

void ChangeLayerOrderCommand::redo()
{
    qCDebug(lcChangeLayerOrderCommand) << "redoing" << this;
    mProject->moveLayer(mPreviousIndex, mNewIndex);
}

int ChangeLayerOrderCommand::id() const
{
    return -1;
}

QDebug operator<<(QDebug debug, const ChangeLayerOrderCommand *command)
{
    debug.nospace() << "(ChangeLayerOrderCommand newIndex=" << command->mNewIndex
        << "previousIndex=" << command->mPreviousIndex
        << ")";
    return debug.space();
}
