#include "CGameDirector.h"

unsigned int CGameDirector::K_FLOOR = 0;
unsigned int CGameDirector::K_PLAYER = 1;
unsigned int CGameDirector::K_DROP = 2;
unsigned int CGameDirector::K_ENEMY = 3;

int CGameDirector::K_FLOOR_SIZE_X = 100;
int CGameDirector::K_FLOOR_SIZE_Z = 250;

int CGameDirector::MAX_ENEMIES = 1;
int CGameDirector::MAX_AMMO = 1;

CGameDirector::CGameDirector():m_player(this , 0 , 20 , -100) , m_floor() , m_sky() , m_light() , m_scene(1000) , m_ammoSpawners()
{
    srand(time(NULL));
}

CGameDirector::~CGameDirector()
{
    //dtor
}

void CGameDirector::InitializeLevel()
{
    Mouse::cursor.masked();
    Mouse::cursor.load("data/cross.png");
    Mouse::blocked() = false;

    m_floor.box();
    m_floor.scale(CGameDirector::K_FLOOR_SIZE_X , 0.5 , CGameDirector::K_FLOOR_SIZE_Z);
    m_floor.setColor(40 , 30 , 30);
    m_floor.createBoundingVolume(Solid::BOX);
    m_floor.staticBody();
    m_floor.type() = CGameDirector::K_FLOOR;

    m_sky.loadTexture( "data/sky.jpg");

    m_light.directional();
    m_light.direction(0.5,0.5,0);

    m_actualEnemyCount = 0;
    m_actualAmmoCount = 0;

    m_ammoSpawners.push_back(new CAmmoSpawner(40 , 20 , -110));
    //m_ammoSpawners.push_back(new CAmmoSpawner(-40 , 20 ,-110));

    m_scene.insert(&m_player);
    m_scene.insert(&m_light);
    m_scene.insert(&m_floor);
    m_scene.insert(&m_sky);

    std::vector<CBullet*>* bullets = m_player.GetAllBullets();

    for (unsigned int i = 0; i < bullets->size(); ++i)
    {
        m_scene.insert(bullets->at(i));
    }

    m_scene.prepare();
}

void CGameDirector::Update()
{
    SpawnAmmo();

    //SpawnEnemy();
    UI();

    m_scene.update();
}

void CGameDirector::SpawnEnemy()
{
    if (m_actualEnemyCount < MAX_ENEMIES)
    {
      //  m_scene->insert(new CEnemy(20 , 20 , 20));

        m_actualEnemyCount++;
    }
}

void CGameDirector::SpawnAmmo()
{
    if (m_ammoSpawners.size() <= 0) return;

    if (m_actualAmmoCount < MAX_AMMO)
    {
        m_ammoSpawners[RandomRange(0 , m_ammoSpawners.size() - 1)]->Activate(&m_scene);

        m_actualAmmoCount++;
    }
}

void CGameDirector::UI()
{
    Text::write(10 , 10 , "Life : %d/%d" , m_player.GetLife() , m_player.GetMaxLife());
    Text::write(10 , 30 , "Ammo : %d/%d" , m_player.GetAmmo() , m_player.GetMaxAmmo());
}

int CGameDirector::RandomRange(int minVal , int maxVal)
{
    return minVal + rand() * (maxVal - minVal);
}

double CGameDirector::RandomRange(double minVal , double maxVal)
{
    return minVal + rand() * (maxVal - minVal);
}

