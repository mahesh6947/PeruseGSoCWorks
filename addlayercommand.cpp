
#include"addlayercommand.h"
#include"include/QtCore/QLoggingCategory"

Q_LOGGING_CATEGORY(lcAddLayerCommand,"app.undo.addLayerCommand")

AddLayerCommand::AddLayerCommand(LayeredImageProject *project, ImageLayer *layer, int index, UndoCommand *parent)
    :UndoCommand(parent),
      mProject(project),
      mIndex(index),
      mLayer(layer)

{
    qCDebug(lcAddLayerCommand())<<"constructed"<<this;
}

void    AddLayerCommand::undo()
{
    qCDebug(lcAddLayerCommand())<<"undoing"<<this;
    mProject->takeLayer(mIndex);
    mLayer->setParent(this);

}

void    AddLayerCommand::redo()
{
    qCDebug(lcAddLayerCommand())<<"redoing"<<this;
    mProject->addLayer(mLayer,mIndex);
}

int AddLayerCommand::id() const
{
    return -1;
}

QDebug operator<<(QDebug debug, const AddLayerCommand *command)
{
    debug.nospace() << "(AddLayerCommand index=" << command->mIndex
        << " layer=" << command->mLayer << ")";
    return debug.space();
}

