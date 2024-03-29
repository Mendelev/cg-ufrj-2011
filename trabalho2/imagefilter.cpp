#include "imagefilter.h"
#include <QDebug>
#include <cor.h>
#include <cmath>
#include <iostream>

using namespace std;

ImageFilter::ImageFilter()
{

}

ImageFilter::ImageFilter(QImage image, int newWidth, int newHeight,int alpha)
{
    this->alpha = alpha;
    this->oldImage = image;
    this->oldHeight = image.height();
    this->oldWidth = image.width();
    this->razao = 1.0 * oldWidth / oldHeight ;
    if (newHeight!=0){
        this->newHeight = newHeight;
    }
    else{
        this->newHeight = (int) (1.0*newWidth)/razao;
    }
    if (newWidth!=0){
        this->newWidth = newWidth;
    }
    else{
        this->newWidth = (int) (1.0*newHeight)*razao;
    }
    this->scaleAToBHeight = (1.0* oldHeight)/this->newHeight;
    this->scaleAToBWidth =(1.0* oldWidth)/this->newWidth;

}

Cor ImageFilter::funcaoDeEscolha(int x,int y){
    int escolhidoX,escolhidoY;

//   float parteInteira;
//   float parteFracionaria;

//   parteInteira = floor(x*1.0* scaleAToBWidth);
//   parteFracionaria =(x*1.0* scaleAToBWidth)- parteInteira;


   escolhidoX = (int) x*1.0* scaleAToBWidth;
   escolhidoY = (int) y*1.0* scaleAToBHeight;

   Cor a=Cor(vetor[acessaPosicao(escolhidoX,escolhidoY)],vetor[acessaPosicao(escolhidoX,escolhidoY)+1],vetor[acessaPosicao(escolhidoX,escolhidoY)+2],vetor[acessaPosicao(escolhidoX,escolhidoY)+3]);
   return a;
}

void ImageFilter::aplicaCor(Cor cor,int i,int j){

    int media=(cor.R+cor.G+cor.B)/3;
    //newData[acessaPosicaoNew(i,j)+3]=cor.A;
    newData[acessaPosicaoNew(i,j)+0]=media;
    newData[acessaPosicaoNew(i,j)+1]=media;
    newData[acessaPosicaoNew(i,j)+2]=media;
    newData[acessaPosicaoNew(i,j)+3]=this->alpha;


}

int ImageFilter::acessaPosicao(int x, int y){
    return  (y*oldWidth+x)*4;

}
int ImageFilter::acessaPosicaoNew(int x, int y){
    return  (y*newWidth+x)*4;

}

void ImageFilter::transform(){

    vetor = oldImage.bits();
    //qDebug()<<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+0]<<" red " <<vetor[acessaPosicao(oldWidth-1,oldHeight-1)+1]<<" green "<< vetor[acessaPosicao(oldWidth-1,oldHeight-1)+2] <<" blue " << vetor[acessaPosicao(oldWidth-1,oldHeight-1)+3] <<" alpha ";

    //qDebug()<<this->newHeight;
    //qDebug()<<this->newWidth;

    newData =new uchar[newWidth*newHeight*4];
    for(int j=0;j<newHeight;j++){
        for(int i=0;i<newWidth;i++){
            Cor cor=funcaoDeEscolha(i,j);
            aplicaCor(cor,i,j);

        }
    }
    this->newImage = QImage(newData, newWidth,newHeight,QImage::Format_RGB32);
    this->newImage.save("resultadoGrayScale.png");
    qDebug() << "Resized image saved as: resultadoGrayScale.png"<< endl;


    //qDebug()<< vetor[3];



//    QImage newImage = QImage();
//    this->newImage = newImage;
}
