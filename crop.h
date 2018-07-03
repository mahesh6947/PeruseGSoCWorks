#ifndef CROP_H
#define CROP_H

#include <QObject>
#include <QRect>


class QMouseEvent;
class Project;

class Crop : public QObject
{
public:
    Crop();
    ~Crop();

    QRect cropArea() const;
    void setCropArea(const QRect &selectionArea);

signals:
    void cropAreaChanged();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


public:
    Project *mProject;
    QRect mCropArea;
};





#endif // CROP_H
