#ifndef ERASERCOMMANDPIXELS_H
#define ERASERCOMMANDPIXELS_H

#include"tools/undo/commands.h"
#include"tools/undoframework/commands.h"
#include "imagecanvas.h"
#include"include/QtGui/QColor"
#include"include/QtCore/QDebug"
#include"include/QtCore/QVector"
#include"include/QtCore/QPoint"



class ApplyPixelEraserCommand:  public  UndoCommand
{
    Q_OBJECT
    public:
    ApplyPixelEraserCommand(ImageCanvas *canvas, int layerIndex, const QVector<QPoint> &scenePositions, const QVector<QColor> &previousColours,
        UndoCommand *parent = nullptr);

    void undo();
    void redo();


    int id();
    bool meregeWith(const UndoCommand *other) ;

     QDebug operator<<(QDebug debug, const ApplyPixelEraserCommand *command);

     ImageCanvas *mCanvas;
     int mLayerIndex;
     QVector<QPoint> mScenePositions;
     QVector<QPoint> mPreviousColours;


};



#endif // ERASERCOMMANDPIXELS_H
