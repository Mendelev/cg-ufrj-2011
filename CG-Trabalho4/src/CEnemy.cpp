#include "CEnemy.h"
USING_URGE;
#include "CGameDirector.h"

double CEnemy::MOVE_SPEED = 10;
int CEnemy::MAX_LIFE = 100;
int CEnemy::DAMAGE = 20;

CEnemy::CEnemy(CGameDirector* gd ,Array startPosition)
{
    //this->box();

    //this->setRefractiveIndex(gd->RandomRange(0,1));
    //this->setReflectivity(1);

    this->load("data/enemy.md2");

    //Texture t;
    //t.load("data/enemy.png");

    //this->setTexture(t);

    this->createBoundingVolume(Solid::BOX);
    this->activeBody();

    this->setColor(80 , 20 , 20);

    this->graphic->normalize(0,-2,0);

    this->scale(4);
    this->body->scale(4);

    position(startPosition);

    m_life = MAX_LIFE;

    m_gameDirector = gd;

    type() = CGameDirector::K_ENEMY;
}

CEnemy::~CEnemy()
{
    //dtor
}

int CEnemy::collide(Object& obj)
{
    if (obj.type() == CGameDirector::K_PLAYER)
    {
        AutoDestroy();
    }

    // Depois da sua ação, chame a collide() padrão.
    return Object::collide(obj);
}

void CEnemy::act()
{
    this->body->vel = (m_gameDirector->GetPlayer()->position()-this->position()).getNormalized() * MOVE_SPEED;
    if (behavior() == 2) return;

    GLfloat angulo = this->position().angle(m_gameDirector->GetPlayer()->position() - position());
    this->body->rot.set(-angulo, 0, 1, 0);


    if (m_life <= 0)
    {
        Die();
        m_gameDirector->GetPlayer()->changePoints(+1);
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
    m_gameDirector->m_enemyHitSound.play();
    m_gameDirector->EnemyDied();
    inactiveBody();
}

void CEnemy::ChangeLife(int ammount)
{
    m_life += ammount;
    m_life = max(m_life , 0);
    m_life = min(m_life , MAX_LIFE);
}
