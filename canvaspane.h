#ifndef CANVASPANE_H
#define CANVASPANE_H

#include <QObject>
#include <QPoint>
#include <QSize>


class  CanvasPane : public QObject
{


Q_OBJECT

public:
    explicit CanvasPane(QObject *parent = 0);

    qreal size() const;
    void setSize(const qreal &size);

    qreal zoomLevel() const;
    int integerZoomLevel() const;
    void setZoomLevel(qreal zoomLevel);
    int maxZoomLevel() const;

    QSize zoomedSize(const QSize &size) const;

    QPoint offset() const;
    void setOffset(const QPoint &offset);

    QPoint zoomedOffset() const;

    bool isSceneCentered() const;
    void setSceneCentered(bool isSceneCentered);



    void reset();



private:
    qreal mSize;
    qreal mZoomLevel;
    int mMaxZoomLevel;

    QPoint mOffset;

    bool mSceneCentered;



};



#endif // CANVASPANE_H
