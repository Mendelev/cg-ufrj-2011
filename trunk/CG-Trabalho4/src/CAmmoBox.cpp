#include "CAmmoBox.h"

#include "CGameDirector.h"

CAmmoBox::CAmmoBox()
{
    box();
    createBoundingVolume(Solid::BOX);
    this->scale(5);
    this->activeBody();

    type() = CGameDirector::K_DROP;
}

CAmmoBox::~CAmmoBox()
{
    //dtor
}
