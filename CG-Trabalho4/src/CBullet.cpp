#include "CBullet.h"

#include "CGameDirector.h"

int CBullet::BULLET_SPEED = 30;

CBullet::CBullet()
{
    sphere();
    createBoundingVolume(Solid::SPHERE);
    this->scale(2);
    this->inactiveBody();
}

CBullet::~CBullet()
{
    //dtor
}

void CBullet::act()
{
    std::cout << behavior() << std::endl;
}

int CBullet::collide(Object& obj)
{
    std::cout << "Colidiu foda" << std::endl;

    if (obj.type() == CGameDirector::K_PLAYER)
    {
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
