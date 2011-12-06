#ifndef CBULLET_H
#define CBULLET_H

#include <URGE/URGE.h>

class CPlayer;

USING_URGE;

class CBullet : public Generic
{
    public:

        static int BULLET_SPEED;

        CBullet(CPlayer* owner);
        virtual ~CBullet();

        inline CPlayer* GetOwner(){return m_owner;};

        void act();
        int collide(Object& obj);

        void Fly(Array position , Array direction);
        void Stop();

    protected:

    private:

        CPlayer* m_owner;

};

#endif // CBULLET_H
