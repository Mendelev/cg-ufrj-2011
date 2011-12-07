#include "CAmmoBox.h"

#include "CGameDirector.h"

CAmmoBox::CAmmoBox()
{
    box();
    createBoundingVolume(Solid::BOX);

    this->body->scale(3);
    this->scale(3);
    this->activeBody();

    this->setShininess(200);
    this->setSpecular(200 ,20 , 100);

    type() = CGameDirector::K_DROP;
}

CAmmoBox::~CAmmoBox()
{
    //dtor
}
