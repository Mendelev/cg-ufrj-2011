#include "CAmmoSpawner.h"

CAmmoSpawner::CAmmoSpawner(double x , double y , double z):m_position(x , y , z , 1)
{

}

CAmmoSpawner::~CAmmoSpawner()
{
    //dtor
}

void CAmmoSpawner::Activate(Scenario* scene)
{
    CAmmoBox* ammo = new CAmmoBox();
    ammo->position() = m_position;

    scene->insert(ammo);
    scene->prepare();
}
