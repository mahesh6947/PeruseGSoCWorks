
#include "AcbfFrame.h"

#include<QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using namespace AdvancedComicBookFormat;

class Frame
{

public:

    QSize framesize;
    Int  frameIndex;
    QList<Frame*> frames;
};

