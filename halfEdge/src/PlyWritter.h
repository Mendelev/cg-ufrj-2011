#ifndef PLYWRITTER_H
#define PLYWRITTER_H

#include <QObject>
#include "Interface.h"
#include <QTextStream>
#include <QFile>
#include "Face.h"
#include "Vertex.h"

class PlyWritter:QObject
{
    Q_OBJECT

public:
   QString caminho;
   PlyWritter();
   Interface * interface;
   void setFileName(QString filename);
   void save();

};

#endif // PLYWRITTER_H
