#ifndef LAYEREDIMAGECANVAS_H
#define LAYEREDIMAGECANVAS_H

#include <QtUndo/undostack.h>
#include "imagecanvas.h"

class LayeredImageProject;


class LayeredImageCanvas :public ImageCanvas

{
    Q_OBJECT

public:
    LayeredImageCanvas();
    ~LayeredImageCanvas();





   public slots:
        void onPostLayerAdded(int index);
        void onPreLayerRemoved(int index);
        void onPostLayerRemoved();
        void onPostLayerMoved();
        void onPostLayerImageChanged();
        void onLayerVisibleChanged();
        void onLayerOpacityChanged();
        void onPreCurrentLayerChanged();
        void onPostCurrentLayerChanged();

    protected:
        void connectSignals();
        void disconnectSignals() ;
        QImage *currentProjectImage() ;
        const QImage *currentProjectImage();
        QImage contentImage() ;

        void replaceImage(int layerIndex, const QImage &replacementImage) override;

        bool areToolsForbidden() ;



         LayeredImageProject *mLayeredImageProject;
    };


#endif // LAYEREDIMAGECANVAS_H
