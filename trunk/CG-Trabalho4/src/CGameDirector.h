#ifndef CGAMEDIRECTOR_H
#define CGAMEDIRECTOR_H

#include "CEnemy.h"
#include "CAmmoSpawner.h"
#include "CEnemySpawner.h"
#include "CPlayer.h"

class CPlayer;
class CEnemySpawner;

USING_URGE;
//using namespace std;

class CGameDirector
{
    public:

        static unsigned int K_FLOOR;
        static unsigned int K_PLAYER;
        static unsigned int K_DROP;
        static unsigned int K_ENEMY;
        static unsigned int K_BULLET;

        static int K_FLOOR_SIZE_X;
        static int K_FLOOR_SIZE_Z;

        static int WINDOWN_X;
        static int WINDOWN_Y;

        static int MAX_ENEMIES;
        static int MAX_AMMO;

        CGameDirector();
        virtual ~CGameDirector();

        inline Scenario* getScene(){return &m_scene;};
        inline CPlayer* GetPlayer(){return &m_player;};
        inline void AmmoPicked(){m_actualAmmoCount--;};
        void EnemyDied();
        void PlayerDied();

        void InitializeLevel();
        void Update();

        int RandomRange(int min , int max);
        double RandomRange(double min , double max);
        int Round(double val);

    protected:

    private:

        void SpawnAmmo();
        void SpawnEnemy();
        void UI();

        CPlayer m_player;

        Generic m_floor;
        Sky m_sky;
        Light m_light;
        Scenario m_scene;

        std::vector<CAmmoSpawner*> m_ammoSpawners;
        std::vector<CEnemySpawner*> m_enemySpawners;

        int m_actualAmmoCount;
        int m_actualEnemyCount;

        bool m_endGame;
};

#endif // CGAMEDIRECTOR_H
