#include "imageresizer.h"
#include <QDebug>

using namespace std;
ImageResizer::ImageResizer(QImage image, int newWidth, int newHeight)
{
    this->oldImage = image;
    this->oldHeight = image.height();
    this->oldWidth = image.width();
    this->newHeight = newHeight;
    this->newWidth = newWidth;
    this->scaleAToBHeight = oldHeight/newHeight;
    this->scaleAToBWidth = oldWidth/newWidth;

}
void ImageResizer::transform(){

    uchar * vetor = oldImage.bits();
    //qDebug()<< vetor[3];
    qDebug()<<"ate aqui ruahuhau";




//    QImage newImage = QImage();
//    this->newImage = newImage;
}
ImageResizer::ImageResizer()
{

}
