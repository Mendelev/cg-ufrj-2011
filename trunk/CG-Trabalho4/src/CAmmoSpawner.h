#ifndef CAMMOSPAWNER_H
#define CAMMOSPAWNER_H

#include "CAmmoBox.h"

class CAmmoSpawner
{
    public:
        CAmmoSpawner(double x , double y , double z);
        virtual ~CAmmoSpawner();

        void Activate(Scenario* scene);
    protected:

    private:

        Array m_position;
};

#endif // CAMMOSPAWNER_H
