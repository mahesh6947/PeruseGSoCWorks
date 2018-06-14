
#include "imagecanvas.h"

ImageCanvas::ImageCanvas() :

    mTool(PenTool),
    mPenForegroundColour(Qt::black), mPenBackgroundColour(Qt::white)


{


 //the code for creating the canvas with other attributes//

}


QColor ImageCanvas::penForegroundColour() const
{
    return mPenForegroundColour;
    }

void ImageCanvas::setpenForegroundColour(const QColor &penForegroundColour)
{
 if(!penForegroundColour.isValid())
 {
     qWarning() << "Invalid PenForegroundColour";
     return;
 }
  QColor fcolour = penForegroundColour.toRGB();
  if (fcolour == mPenForegroundColour)
      return;

  mPenForegroundColour = fcolour;
  emit penForegroundColourChanged();

}



QColor ImageCanvas ::penBackgroundColour() const
{
    return mPenBackgroundColour;

 }

void ImageCanvas::setPenBackgroundColour(const QColor &penBackgroundColour)
{
    if(!penBackgroundColour.isValid())
    {
        qWarning() << "Invalid PenBackgroundColour";
        return;
    }

    QColor bcolour =penBackgroundColour.toRGB();
    if(bcolour == mPenBackgroundColour)
    {
        return;
    }
    mPenBackgroundColour = bcolour;
    emit penBackgroundColourChanged();
}

    void ImageCanvas::applyPixelPenTool(int layerIndex, const QPoint &scenePos, const QColor &colour, bool markAsLastRelease)
    {
        imageForLayerAt(layerIndex)->setPixelColor(scenePos, colour);
        if (markAsLastRelease)
            mLastPixelPenPressScenePosition = scenePos;
        update();
    }


    QPointF ImageCanvas::linePoint1() const
    {
        return mLastPixelPenPressScenePosition;
    }
