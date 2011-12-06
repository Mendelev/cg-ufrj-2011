#ifndef CBULLET_H
#define CBULLET_H

#include <URGE/URGE.h>

USING_URGE;

class CBullet : public Generic
{
    public:

        static int BULLET_SPEED;

        CBullet();
        virtual ~CBullet();

        void act();
        int collide(Object& obj);

        void Fly(Array position , Array direction);
        void Stop();

    protected:

    private:

};

#endif // CBULLET_H
