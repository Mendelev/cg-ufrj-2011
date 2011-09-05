#ifndef IMAGECROPPER_H
#define IMAGECROPPER_H
#include <QPoint>

#include <QPoint>
#include <QImage>
#include <imageresizer.h>

class ImageCropper
{
private:
    uchar * newData;
    uchar * vetor;
    int oldHeight, oldWidth;
    int newHeight ,newWidth;
    double scaleAToBHeight, scaleAToBWidth;
    QImage newImage;
    QImage oldImage;
    QPoint pontoInicial;

public:
   void transform();

   ImageCropper(QImage image, int newWidth, int newHeight,QPoint pontoInicial);
   ImageCropper();
   int acessaPosicao(int x, int y);
    int acessaPosicaoNew(int x, int y);
   void aplicaCor(Cor cor,int i,int j);

   Cor funcaoDeEscolha(int x,int y);


};

#endif // IMAGECROPPER_H
