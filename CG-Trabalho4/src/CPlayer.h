class CGameDirector;

#ifndef CPLAYER_H
#define CPLAYER_H

#include <URGE/URGE.h>
#include <cmath>
#include "CBullet.h"
#include <URGE/Environment/light.h>

USING_URGE;

class CPlayer : public Camera
{
    public:

        CPlayer();
        CPlayer(CGameDirector* gd , double x , double y , double z);
        virtual ~CPlayer();

        void act();
        int collide(Object& obj);

        inline int GetLife(){return m_life;};
        inline int GetMaxLife(){return MAX_LIFE;};
        inline int GetAmmo(){return m_ammo;};
        inline int GetMaxAmmo(){return MAX_AMMO;};
        inline bool HasAmmo(){return m_ammo > 0;};

        inline std::vector<CBullet*>* CPlayer::GetAllBullets(){return m_loadedBullets;};

        void ChangeAmmo(int ammount);
        void ChangeLife(int ammount);

        void Reload(CBullet* bullet);
        Light* GetLanterna();
        int getPoints();
        int changePoints(int);

    protected:

    private:

        static double MOVE_SPEED;
        static double ROTATION_SPEED;
        static double JUMP_FORCE;
        static int MAX_LIFE;
        static int START_AMMO;
        static int MAX_AMMO;

        void Die();
        void Jump();
        void Shoot();
        void TurnOnLight();

        void CreateBullets();
        void ClearBullets();

        CBullet* GetBullet();


        int m_life;
        int m_ammo;
        bool m_isJumping;
        Light lanterna;
        int points;

        CGameDirector *m_gameDirector;

        std::vector<CBullet*>* m_loadedBullets;
        std::vector<CBullet*>* m_flyingBullets;
};

#endif // CPLAYER_H
