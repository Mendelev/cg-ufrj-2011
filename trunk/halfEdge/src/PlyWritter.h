#ifndef PLYWRITTER_H
#define PLYWRITTER_H

#include <QObject>
#include "Interface.h"


class PlyWritter : public QObject
{
    Q_OBJECT

public slots:
    void arquivoDestino (const QString &);

public:
    PlyWritter();



private:
    Interface interface;
};

#endif // PLYWRITTER_H
