#include "imagelayer.h"



ImageLayer::ImageLayer(QObject *parent, const QImage &image) :
QObject(parent),
mVisible(true),
mOpacity(1.0),
mImage(image)
{
}



ImageLayer::~ImageLayer()
{
}

QString ImageLayer::name() const
{
    return mName;
}

void ImageLayer::setName(const QString &name)
{
    if (name == mName)
        return;

    mName = name;
    setObjectName(mName);
    emit nameChanged();
}
