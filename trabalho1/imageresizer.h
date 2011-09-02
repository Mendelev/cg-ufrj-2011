#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H
#include <QRgb>
#include <QImage>

class ImageResizer
{
private:

    int oldHeight, oldWidth;
    int newHeight ,newWidth;
    float scaleAToBHeight, scaleAToBWidth;
    QImage newImage;
    QImage oldImage;

public:
   void transform();

   ImageResizer(QImage image, int newWidth, int newHeight);
   ImageResizer();


};

#endif // IMAGERESIZER_H
