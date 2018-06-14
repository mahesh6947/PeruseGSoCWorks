#include "ErasercommandPixels.h"


#include"include/QtCore/QLoggingCategory"


Q_LOGGING_CATEGORY(lcApplyPixelEraserCommand, "app.undo.applyPixelEraserCommand")

ApplyPixelEraserCommand::ApplyPixelPenCommand(ImageCanvas *canvas, int layerIndex)
    :
      mCanvas(canvas), mLayerIndex(layerIndex)
{
    mScenePositions =scenePositions;
    mPreviousColours = previousColours;

    qCDebug(lcApplyPixelEraserCommand()) << "constructed" <<this;
}
void ApplyPixelEraserCommand::undo()
{
    qCDebug(lcApplyPixelEraserCommand()) << "undoing" <<this;
    for(int i=0; i< mScenePositions.size(); i++)
    {
        mCanvas->applyPixelPenTool(mLayerIndex,mScenePositions,mPreviousColours.at(i));
    }
}

void ApplyPixelEraserCommand::redo()
{
    qCDebug(lcApplyPixelEraserCommand()) << "redoing" << this;
    for(int i=0; i< mScenePositions.size(); i++)
    {
        mCanvas->applyPixelPenTool(mLayerIndex,mScenePositions.at(i),QColor(Qt::transparent));
    }
}
 int ApplyPixelEraserCommand::id()
 {
     return ApplyPixelEraserCommandId;
 }


 bool  ApplyPixelEraserCommand ::meregeWith(const UndoCommand *other)
 {
      ApplyPixelEraserCommand*otherCommand = qobject_cast<const ApplyPixelEraserCommand*>(other);
  {
      if(!otherCommand)
          return false;
 }

      qCDebug(lcApplyPixelEraserCommand)<< "Merging:" << otherCommand << "with: " << this;
      mScenePositions.append(otherCommand->mScenePositions);
      mPreviousColours.append(otherCommand->mPreviousColours);
      return true;
 }



 QDebug operator<<(QDebug debug, const ApplyPixelEraserCommand *command)
 {
     debug.nospace() << "(ApplyPixelEraserCommand"
         << " LayerIndex=" << command->mLayerIndex
         << ", ScenePositions=" << command->mScenePositions
         << ", PreviousColours=" << command->mPreviousColours
         << ")";
     return debug.space();
 }




