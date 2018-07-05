#include "layeredimagecanvas.h"

#include <QLoggingCategory>
#include <QPainter>

#include "imagelayer.h"


LayeredImageCanvas::LayeredImageCanvas() :
    mLayeredImageProject(nullptr)
{
    qCDebug(lcImageCanvasLifecycle) << "constructing LayeredImageCanvas" << this;
}

LayeredImageCanvas::~LayeredImageCanvas()
{
    qCDebug(lcImageCanvasLifecycle) << "destructing LayeredImageCanvas" << this;
}

void LayeredImageCanvas::onPostLayerAdded(int index)
{
    ImageLayer *layer = mLayeredImageProject->layerAt(index);

    connect(layer, &ImageLayer::visibleChanged, this, &LayeredImageCanvas::onLayerVisibleChanged);

    connect(layer, &ImageLayer::opacityChanged, this, &LayeredImageCanvas::onLayerOpacityChanged);
    update();
}

void LayeredImageCanvas::onPreLayerRemoved(int index)
{
    ImageLayer *layer = mLayeredImageProject->layerAt(index);
    disconnect(layer, &ImageLayer::visibleChanged, this, &LayeredImageCanvas::onLayerVisibleChanged);
    disconnect(layer, &ImageLayer::opacityChanged, this, &LayeredImageCanvas::onLayerOpacityChanged);
}

void LayeredImageCanvas::onPostLayerRemoved()
{
    update();
}

void LayeredImageCanvas::onPostLayerMoved()
{
    update();
}

void LayeredImageCanvas::onPostLayerImageChanged()
{
    update();
}

void LayeredImageCanvas::onLayerVisibleChanged()
{
    update();

    ImageLayer *layer = qobject_cast<ImageLayer*>(sender());
    if (layer == mLayeredImageProject->currentLayer())
        updateWindowCursorShape();
}

void LayeredImageCanvas::replaceImage(int layerIndex, const QImage &replacementImage)
{
    *mLayeredImageProject->layerAt(layerIndex)->image() = replacementImage;
    update();
}
