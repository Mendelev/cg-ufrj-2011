#ifndef CENEMY_H
#define CENEMY_H

#include <URGE/URGE.h>

USING_URGE;

class CGameDirector;

class CEnemy : public Generic
{
    public:

        CEnemy(CGameDirector* gd , Array startPosition);
        virtual ~CEnemy();

        void act();
        int collide(Object& obj);
        void ChangeLife(int ammount);

    protected:

    private:

        static int MAX_LIFE;
        static double MOVE_SPEED;
        static int DAMAGE;

        void Die();
        void AutoDestroy();

        int m_life;
        CGameDirector* m_gameDirector;
};

#endif // CENEMY_H
