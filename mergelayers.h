#ifndef MERGELAYERS_H
#define MERGELAYERS_H

#include <QDebug>
#include <QImage>
#include <QtUndo/undocommand.h>

class ImageLayer;
class LayeredImageProject;

class MergeLayers : public UndoCommand
{
    Q_OBJECT

public:
    MergeLayers(LayeredImageProject *project,
        int sourceIndex, ImageLayer *sourceLayer,
        int targetIndex, ImageLayer *targetLayer, UndoCommand *parent = nullptr);

    QDebug operator<<(QDebug debug, const MergeLayersCommand *command);

    LayeredImageProject *mProject;
    int mSourceIndex;
    ImageLayer *mSourceLayer;
    int mTargetIndex;
    ImageLayer *mTargetLayer;
    QImage mPreviousTargetLayerImage;
};



#endif // MERGELAYERS_H
