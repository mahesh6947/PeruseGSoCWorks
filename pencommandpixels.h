#ifndef PENCOMMANDPIXELS_H
#define PENCOMMANDPIXELS_H

#include "imagecanvas.h"

#include"tools/undo/commands.h"
#include"tools/undoframework/commands.h"
#include"include/QtGui/QColor"
#include"include/QtCore/QDebug"
#include"include/QtCore/QVector"
#include"include/QtCore/QPoint"

class ApplyPixelPenCommand : public  UndoCommand
{

    Q_OBJECT

   public:
    ApplyPixelPenCommand(ImageCanvas *canvas, int layerIndex, const QVector<QPoint> &scenePositions, const QVector<QColor> &previousColours,
        const QColor &colour, UndoCommand *parent = nullptr);

    void undo() ;
    void redo();



    int id() const;
    bool mergeWith(const UndoCommand *other) ;

   QDebug operator<<(QDebug debug, const ApplyPixelPenCommand *command);




    ImageCanvas *mCanvas;
    int mLayerIndex;
    QVector<QPoint> mScenePositions;
    QVector<QColor> mPreviousColours;
    QColor mColour;

};

#endif // PENCOMMANDPIXELS_H
