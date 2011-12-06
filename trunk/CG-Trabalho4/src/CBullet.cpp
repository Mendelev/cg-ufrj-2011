#include "CBullet.h"

#include "CGameDirector.h"

int CBullet::BULLET_SPEED = 400;

CBullet::CBullet(CPlayer* owner)
{
    box();
    createBoundingVolume(Solid::BOX);
    this->scale(1.5);
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
    //std::cout << behavior() << std::endl;
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

    return Object::collide(obj);
}

void CBullet::Fly(Array p_position , Array direction)
{
    this->activeBody();
    position() = p_position + direction * 10;
    this->body->vel = direction * BULLET_SPEED;
}

void CBullet::Stop()
{
    this->inactiveBody();
}
