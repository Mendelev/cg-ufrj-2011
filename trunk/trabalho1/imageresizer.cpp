#include "imageresizer.h"
#include <QDebug>
#include <cor.h>

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

Cor ImageResizer::funcaoDeEscolha(int x,int y){
    int escolhidoX,escolhidoY;
   escolhidoX = (int) x * scaleAToBWidth;
   escolhidoY = (int) y * scaleAToBHeight;
   Cor a=Cor(vetor[acessaPosicao(escolhidoX,escolhidoY)],vetor[acessaPosicao(escolhidoX,escolhidoY)+1],vetor[acessaPosicao(escolhidoX,escolhidoY)+2],vetor[acessaPosicao(escolhidoX,escolhidoY)+3]);
   return a;
}

void ImageResizer::aplicaCor(Cor cor,int i,int j){

    newData[acessaPosicao(i,j)+0]=cor.R;
    newData[acessaPosicao(i,j)+1]=cor.G;
    newData[acessaPosicao(i,j)+2]=cor.B;
    newData[acessaPosicao(i,j)+3]=cor.A;


}

int ImageResizer::acessaPosicao(int x, int y){
    return  (y*oldWidth+x)*4;

}

void ImageResizer::transform(){

    vetor = oldImage.bits();
    qDebug()<<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+0]<<" red " <<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+1]<<" green "<< vetor[acessaPosicao(oldWidth-1,oldHeight-1)+2] <<" blue " << vetor[acessaPosicao(oldWidth-1,oldHeight-1)+3] <<" alpha ";
    qDebug()<<this->newHeight;
    qDebug()<<this->newWidth;

    newData =new uchar[newWidth*newHeight*4];
    for(int j=0;j<newHeight;j++){
        for(int i=0;i<newWidth;i++){
            Cor cor=funcaoDeEscolha(i,j);
            aplicaCor(cor,i,j);

        }
    }
    this->newImage = QImage(newData, newWidth,newHeight,QImage::Format_RGB32);

    //qDebug()<< vetor[3];



//    QImage newImage = QImage();
//    this->newImage = newImage;
}
ImageResizer::ImageResizer()
{

}
