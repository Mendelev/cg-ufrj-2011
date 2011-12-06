#ifndef CENEMY_H
#define CENEMY_H

#include <URGE/URGE.h>
#include "CGameDirector.h"

USING_URGE;

class CEnemy : public Generic
{
    public:

        CEnemy(double x , double y , double z);
        virtual ~CEnemy();

    protected:

    private:

        static int MAX_LIFE;

        int m_life;
};

#endif // CENEMY_H
