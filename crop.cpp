
#include "crop.h"

Crop::Crop() : mProject(nullptr)
{

}
QRect CropHelper::cropArea() const
{
    return mCropArea;
}

void Crop::setCropArea(const QRect &cropArea)
{
    if (cropArea == mCropArea)
        return;

    mCropArea = cropArea;
    emit cropAreaChanged();
}

