#ifndef CENEMY_H
#define CENEMY_H

#include <URGE/URGE.h>

class CGameDirector;

USING_URGE;

class CEnemy : public Generic
{
    public:

        CEnemy(CGameDirector* gd , Array startPosition , Array endPosition);
        virtual ~CEnemy();

        void act();
        void ChangeLife(int ammount);

    protected:

    private:

        static int MAX_LIFE;
        static double MOVE_SPEED;
        static int DAMAGE;

        void Die();
        void AutoDestroy();

        int m_life;
        Array m_endPosition;
        CGameDirector* m_gameDirector;
};

#endif // CENEMY_H
