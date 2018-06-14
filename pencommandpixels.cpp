#include"include/QtCore/QLoggingCategory"
#include "PencommandPixels.h"

Q_LOGGING_CATEGORY(lcApplyPixelPenCommand, "app.undo.applyPixelPenCommand")
ApplyPixelPenCommand::ApplyPixelPenCommand(ImageCanvas *canvas, int layerIndex, const QVector<QPoint> &scenePositions, const QVector<QColor> &previousColours, const QColor &colour, UndoCommand *parent)
    :
      UndoCommand(parent),
    mCanvas(canvas),
    mLayerIndex(layerIndex),
         mColour(colour)

{
    mScenePositions = scenePositions;
    mPreviousColours =previousColours;

    qCDebug(lcApplyPixelPenCommand()) << "Constructed" << this;
}

void ApplyPixelPenCommand::undo()
{
   qCDebug(lcApplyPixelPenCommand()) <<"undo" << this;

   for (int i=0;i<mScenePositions.size();i++)
   {
       mCanvas->applyPixelPenTool(mLayerIndex,mScenePositions.at(i),mPreviousColours.at(i),i == mScenePositions.size() - 1  );

   }
 }

void ApplyPixelPenCommand::redo()
{
    qCDebug(lcApplyPixelPenCommand()) << "redo" << this;
    for (int i = 0; i < mScenePositions.size(); ++i) {
        mCanvas->applyPixelPenTool(mLayerIndex, mScenePositions.at(i), mColour, i == mScenePositions.size() - 1);
    }

}

int ApplyPixelPenCommand::id() const
{
    return ApplyPixelPenCommandId;
}

bool ApplyPixelPenCommand::mergeWith(const UndoCommand *other)
{
    ApplyPixelPenCommand *otherCommand = qobject_cast<const ApplyPixelPenCommand*>(other);
    if(!otherCommand)
    {
        return false;
    }

    if (otherCommand->mColour != mColour)
    {
        return false;
    }


    return false;
}

QDebug operator<<(QDebug debug, const ApplyPixelPenCommand *command)
{
    debug.nospace() << "ApplyPixelPencommand scenePositions=" << command->mScenePositions
                    << ", PreviousColours=" << command->mPreviousColours
                    <<",colour= "<< command->mColour
                   << ")";
                      return debug.space();
}



