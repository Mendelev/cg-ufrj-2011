#ifndef IMAGECROPPER_H
#define IMAGECROPPER_H
#include <QPoint>

class imageCropper
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

   ImageResizer(QImage image, int newWidth, int newHeight);
   ImageResizer();
   int acessaPosicao(int x, int y);
    int acessaPosicaoNew(int x, int y);
   void aplicaCor(Cor cor,int i,int j);

   Cor funcaoDeEscolha(int x,int y);


};

#endif // IMAGECROPPER_H
