#ifndef IMAGECANVAS_H
#define IMAGECANVAS_H


#include "include/QtCore/QObject"
#include"include/QtCore/QStack"
#include"include/QtCore/QBasicTimer"
#include"include/QtQuick/QQuickPaintedItem"
#include"include/QtCore/QLoggingCategory"


Q_DECLARE_LOGGING_CATEGORY(lcImageCanvas);
class ImageProject;
class Project;
class Tile;
class Tileset;

class ImageCanvas : public QQuickPaintedItem
{
    QOBJECT_H


public:
  enum   Tools {
        PenTool,
      EraserTool,
      SelectionTool,
      CropTool

    };

  Q_ENUM(Tools);

  ImageCanvas();
  ~ImageCanvas();

  Project *project() const;
  void setProject(Project *project);

  int cursorX() const;
  void setCursorX(int cursorX);

  int cursorY() const;
  void setCursorY(int cursorY);

  QColor cursorPixelColour() const;

  CanvasPane *firstPane();
  CanvasPane *secondPane();

  Tools tool();
  void setTool(const Tool &tool);

  void penForegroundColour() const  ;
  void setPenForegroundColour(const QColor &penForegroundColour);

  QColor penBackgroundColour() const ;
  void setPenBackgroundColour(const QColor &PenBackgroundColour);

signals:
  void penForegroundColourChanged();
  void penBackgroundColourChanged();

  class ApplyPixelPenCommand;
  class ApplyPixelEraserCommand;



 void applyCurrentTool();
 void applyPixelPenTool(int layerIndex, const QPoint &scenePos, const QColor &colour, bool markAsLastRelease = false);

 QColor penColour();
 QColor mPenForegroundColour;
 QColor mPenBackgroundColour;
  QPoint mLastPixelPenPressScenePosition;




};


#endif // IMAGECANVAS_H
