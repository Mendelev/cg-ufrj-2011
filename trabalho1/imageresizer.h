#ifndef IMAGERESIZER_H
#define IMAGERESIZER_H
#include <QRgb>
#include <QImage>
#include <cor.h>

class ImageResizer
{
private:
    uchar * newData;
    uchar * vetor;
    int oldHeight, oldWidth;
    int newHeight ,newWidth;
    double scaleAToBHeight, scaleAToBWidth;
    QImage newImage;
    QImage oldImage;

public:
   void transform();

   ImageResizer(QImage image, int newWidth, int newHeight);
   ImageResizer();
   int acessaPosicao(int x, int y);
    int acessaPosicaoNew(int x, int y);
   void aplicaCor(Cor cor,int i,int j);

   Cor funcaoDeEscolha(int x,int y);



};

#endif // IMAGERESIZER_H
