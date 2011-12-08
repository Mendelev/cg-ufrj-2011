#include "CBullet.h"

#include "CGameDirector.h"

int CBullet::BULLET_SPEED = 200;

CBullet::CBullet(CPlayer* owner) : m_particle()
{
    m_particle.generate(Particle::GLOW);
    m_particle.setColor(255,200,60);
    m_particle.stop();

    box();
    createBoundingVolume(Solid::BOX);
    this->scale(1.5);
    this->body->scale(1.5);
    this->inactiveBody();
    this->body->gravityScale() = 0.000001;

    type() = CGameDirector::K_BULLET;

    m_owner = owner;
}

CBullet::~CBullet()
{
    //dtor
}

void CBullet::act()
{
    m_particle.position() = position();
}

int CBullet::collide(Object& obj)
{
    if (obj.type() == CGameDirector::K_ENEMY)
    {
        ((CEnemy&)obj).ChangeLife(-100);

        m_owner->Reload(this);
        Stop();
        return 0;
    }
    else if (obj.type() == CGameDirector::K_WALL)
    {
        m_owner->Reload(this);
        Stop();
    }

    return Object::collide(obj);
}

void CBullet::Fly(Array p_position , Array direction)
{
    m_particle.start();
    this->activeBody();
    position() = p_position + direction * 10;
    this->body->vel = direction * BULLET_SPEED;
}

void CBullet::Stop()
{
    this->inactiveBody();
    m_particle.stop();
}
