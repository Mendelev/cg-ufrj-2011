#include "CEnemySpawner.h"

CEnemySpawner::CEnemySpawner(CGameDirector* gd ,double startX , double startY , double startZ):m_position(startX , startY , startZ , 1)
{
    m_gameDirector = gd;
}

CEnemySpawner::~CEnemySpawner()
{
    //dtor
}

void CEnemySpawner::Activate(Scenario* scene)
{
    CEnemy* enemy = new CEnemy(m_gameDirector , m_position);

    scene->insert(enemy);
    scene->prepare();
}
