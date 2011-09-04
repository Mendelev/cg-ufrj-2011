#include "imagecropper.h"
#include <QDebug>
#include <cor.h>
#include <cmath>
#include <iostream>
#include <QPoint>

using namespace std;
ImageCropper::ImageCropper(QImage image, int newWidth, int newHeight,QPoint pontoInicial=QPoint(0,0))
{

    this->oldImage = image;
    this->oldHeight = image.height();
    this->oldWidth = image.width();
    this->newHeight = newHeight;
    this->newWidth = newWidth;
    this->scaleAToBHeight = (1.0* oldHeight)/newHeight;
    this->scaleAToBWidth =(1.0* oldWidth)/newWidth;
    this->pontoInicial = pontoInicial;

}

Cor ImageCropper::funcaoDeEscolha(int x,int y){
    int escolhidoX,escolhidoY;

//   float parteInteira;
//   float parteFracionaria;

//   parteInteira = floor(x*1.0* scaleAToBWidth);
//   parteFracionaria =(x*1.0* scaleAToBWidth)- parteInteira;


   escolhidoX = (int) x;
   escolhidoY = (int) y;

   Cor a=Cor(vetor[acessaPosicao(escolhidoX,escolhidoY)],vetor[acessaPosicao(escolhidoX,escolhidoY)+1],vetor[acessaPosicao(escolhidoX,escolhidoY)+2],vetor[acessaPosicao(escolhidoX,escolhidoY)+3]);
   return a;
}

void ImageCropper::aplicaCor(Cor cor,int i,int j){

    newData[acessaPosicaoNew(i-pontoInicial.x,j-pontoInicial.y)+0]=cor.R;
    newData[acessaPosicaoNew(i-pontoInicial.x,j-pontoInicial.y)+1]=cor.G;
    newData[acessaPosicaoNew(i-pontoInicial.x,j-pontoInicial.y)+2]=cor.B;
    newData[acessaPosicaoNew(i-pontoInicial.x,j-pontoInicial.y)+3]=cor.A;


}

int ImageCropper::acessaPosicao(int x, int y){
    return  (y*oldWidth+x)*4;

}
int ImageCropper::acessaPosicaoNew(int x, int y){
    return  (y*newWidth+x)*4;

}

void ImageCropper::transform(){

    vetor = oldImage.bits();
    //qDebug()<<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+0]<<" red " <<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+1]<<" green "<< vetor[acessaPosicao(oldWidth-1,oldHeight-1)+2] <<" blue " << vetor[acessaPosicao(oldWidth-1,oldHeight-1)+3] <<" alpha ";

    //qDebug()<<this->newHeight;
    //qDebug()<<this->newWidth;

    newData =new uchar[newWidth*newHeight*4];
    for(int j=pontoInicial.y;j<newHeight;j++){
        for(int i=pontoInicial.x;i<newWidth;i++){
            Cor cor=funcaoDeEscolha(i,j);
            aplicaCor(cor,i,j);

        }
    }
    this->newImage = QImage(newData, newWidth,newHeight,QImage::Format_RGB32);
    this->newImage.save("resultado.png");

    //qDebug()<< vetor[3];



//    QImage newImage = QImage();
//    this->newImage = newImage;
}
ImageCropper::ImageCropper()
{

}
