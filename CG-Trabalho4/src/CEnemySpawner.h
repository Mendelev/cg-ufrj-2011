#ifndef CENEMYSPAWNER_H
#define CENEMYSPAWNER_H

#include "CEnemy.h"

class CEnemySpawner
{
    public:
        CEnemySpawner(CGameDirector* gd , double startX , double startY , double startZ ,double endX , double endY , double endZ);
        virtual ~CEnemySpawner();

        void Activate(Scenario* scene);
    protected:
    private:

        Array m_position;
        Array m_destination;
        CGameDirector* m_gameDirector;
};

#endif // CENEMYSPAWNER_H
