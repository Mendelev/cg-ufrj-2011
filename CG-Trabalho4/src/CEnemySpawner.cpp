#include "CEnemySpawner.h"

CEnemySpawner::CEnemySpawner(CGameDirector* gd ,double startX , double startY , double startZ ,double endX , double endY , double endZ):m_position(startX , startY , startZ , 1) ,
                                                                                                                     m_destination(endX , endY , endZ , 1)
{
    m_gameDirector = gd;
}

CEnemySpawner::~CEnemySpawner()
{
    //dtor
}

void CEnemySpawner::Activate(Scenario* scene)
{
    CEnemy* enemy = new CEnemy(m_gameDirector , m_position , m_destination);

    scene->insert(enemy);
    scene->prepare();
}
