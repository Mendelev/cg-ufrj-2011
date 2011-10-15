#include "PlyWritter.h"
#include <QDebug>
#include <iostream>
#include <QHash>
using namespace std;


PlyWritter::PlyWritter(){

}

void PlyWritter::setFileName(QString filename){
    this->caminho=filename;
}


void PlyWritter::save(){

    //stream.setString(&caminho);
   // stream<<"oi";
   // QFile *file=new QFile(caminho);
    QFile file(caminho);
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
          exit(15);

      QTextStream out(&file);
      QString line = "ply\nformat ascii 1.0\nobj_info malha 2D\n";
      out<<line;

    //QMap<QPair<QPointF,QPointF>, HalfEdge *> & mapHalfEdge = interface->getMap();

    QVector<Face *> & vetorFaces = interface->getFaces();

    QMap<Vertex *,int> mapPontos= QMap<Vertex *,int>();



    for(int i=0;i<vetorFaces.size();i++){
        HalfEdge * inicio;
        HalfEdge * it;
        inicio = vetorFaces.at(i)->getOuterComp();
        it=inicio;
        do{
            mapPontos[it->getOrigem()]=0;
            it=it->getProx();

        }
        while(it!=inicio);
    }
    out<<"element vertex "<<mapPontos.size()<<"\n";
    out<<"property float x\nproperty float y\n";
    out<<"element face "<<vetorFaces.size()<<"\n";
    out<<"property list uchar int vertex_indices\nend_header\n";

    QMapIterator<Vertex *,int> it(mapPontos);
    //imprime pontos
    int j = 0;
    while(it.hasNext()){

        Vertex * chave = it.next().key();
        out<<chave->getPoint().x()<<" "<<chave->getPoint().y()<<"\n";
        mapPontos.insert(chave,j);
        //out<<mapPontos[chave]<<"\n";
        j++;
    }

    //imprime faces
    for(int i=0;i<vetorFaces.size();i++){
        HalfEdge * inicio;
        HalfEdge * it;
        inicio = vetorFaces.at(i)->getOuterComp();
        int j=0;
        QVector<int> vetor=QVector<int>();
        it=inicio;
        do{
            vetor.append(mapPontos[it->getOrigem()]);
            it=it->getProx();
            j++;
        }
        while(it!=inicio);
        out<<j<<" ";
        foreach(int value,vetor){
            out<<value<<" ";
        }
        out<<"\n";
        vetor.clear();
    }


}
