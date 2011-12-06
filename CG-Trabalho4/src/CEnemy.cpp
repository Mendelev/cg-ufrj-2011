#include "CEnemy.h"

int CEnemy::MAX_LIFE = 100;

CEnemy::CEnemy(double x , double y , double z):Generic()
{
    this->sphere();
    this->createBoundingVolume(Solid::SPHERE);

    //position(x , y , z);
    //this->scale(5);

    //this->activeBody();
    //this->body->scale(5);

    m_life = MAX_LIFE;

    type() = CGameDirector::K_ENEMY;
}

CEnemy::~CEnemy()
{
    //dtor
}
