#ifndef ACBFFRAME_H
#define ACBFFRAME_H


#include "AcbfPage.h"

#include <QPoint>
#include <QtCore>

namespace AdvancedComicBookFormat {
class Frame;
class ACBF_EXPORT Frame : public QObject
{
    Q_OBJECT
public:
    explicit Frame(Page* parent = nullptr);
    ~Frame() override;


    QSize framesize;
    void setFrameSize(QSize framesize);

    Int frameIndex;
    void setFrameIndex(int frameIndex );

    QList<Frame*> Frames();
    Frame* frame(int frameIndex);
    int FrameIndex(Frame* frame);


    void addFrame(Frame* frame, int index = -1);
    void removeFrame(Frame* frame);


}

#endif // ACBFFRAME_H
