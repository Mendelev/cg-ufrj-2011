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
        inline ParticleEmitter* GetParticle(){return &m_particle;};


        void act();
        int collide(Object& obj);

        void Fly(Array position , Array direction);
        void Stop();

    protected:

    private:

        ParticleEmitter m_particle;

        CPlayer* m_owner;

};

#endif // CBULLET_H
