#include "CEnemy.h"
USING_URGE;
#include "CGameDirector.h"

double CEnemy::MOVE_SPEED = 15;
int CEnemy::MAX_LIFE = 100;
int CEnemy::DAMAGE = 20;

CEnemy::CEnemy(CGameDirector* gd ,Array startPosition , Array endPosition)
{
    this->box();

    //this->setRefractiveIndex(gd->RandomRange(0,1));
    this->setReflectivity(1);

    this->createBoundingVolume(Solid::BOX);
    this->activeBody();

    this->scale(5);

    this->setColor(80 , 20 , 20);

    position(startPosition);

    this->body->vel = (endPosition - startPosition).getNormalized() * MOVE_SPEED;
    //this->body->vel = (gd->GetPlayer->ge);

    m_life = MAX_LIFE;
    m_endPosition = endPosition;

    m_gameDirector = gd;

    type() = CGameDirector::K_ENEMY;
}

CEnemy::~CEnemy()
{
    //dtor
}

void CEnemy::act()
{
    this->body->vel = (m_gameDirector->GetPlayer()->position()-this->position()).getNormalized() * MOVE_SPEED;
    if (behavior() == 2) return;

    if (m_life <= 0)
    {
        Die();
        m_gameDirector->GetPlayer()->changePoints(+1);
    }

    if (  position().dist(m_gameDirector->GetPlayer()->position()) < 10)
    {
        AutoDestroy();
    }
}

void CEnemy::AutoDestroy()
{
    m_gameDirector->EnemyDied();
    m_gameDirector->GetPlayer()->ChangeLife(-DAMAGE);
    inactiveBody();
}

void CEnemy::Die()
{
    m_gameDirector->EnemyDied();
    inactiveBody();
}

void CEnemy::ChangeLife(int ammount)
{
    m_life += ammount;
    m_life = max(m_life , 0);
    m_life = min(m_life , MAX_LIFE);

}
