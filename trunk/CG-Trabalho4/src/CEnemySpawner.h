#ifndef CENEMYSPAWNER_H
#define CENEMYSPAWNER_H

#include "CEnemy.h"

class CEnemySpawner
{
    public:
        CEnemySpawner(CGameDirector* gd , double startX , double startY , double startZ);
        virtual ~CEnemySpawner();

        void Activate(Scenario* scene);
    protected:
    private:

        Array m_position;
        CGameDirector* m_gameDirector;
};

#endif // CENEMYSPAWNER_H
