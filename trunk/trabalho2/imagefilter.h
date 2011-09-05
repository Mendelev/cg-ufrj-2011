#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include <QRgb>
#include <QImage>
#include <cor.h>

class ImageFilter
{
private:
    int alpha;
    uchar * newData;
    uchar * vetor;
    int oldHeight, oldWidth;
    int newHeight ,newWidth;
    double razao;
    double scaleAToBHeight, scaleAToBWidth;
    QImage newImage;
    QImage oldImage;

public:
   void transform();

   ImageFilter(QImage image, int newWidth, int newHeight, int alpha);
   ImageFilter();
   int acessaPosicao(int x, int y);
    int acessaPosicaoNew(int x, int y);
   void aplicaCor(Cor cor,int i,int j);

   Cor funcaoDeEscolha(int x,int y);



};

#endif // IMAGEFILTER_H
