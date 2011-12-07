#include "CGameDirector.h"

unsigned int CGameDirector::K_FLOOR = 0;
unsigned int CGameDirector::K_PLAYER = 1;
unsigned int CGameDirector::K_DROP = 2;
unsigned int CGameDirector::K_ENEMY = 3;
unsigned int CGameDirector::K_BULLET = 4;
unsigned int CGameDirector::K_WALL = 5;

int CGameDirector::K_FLOOR_SIZE_X = 150;
int CGameDirector::K_FLOOR_SIZE_Z = 150;
int CGameDirector::K_WALL_HEIGHT = 10;

int CGameDirector::START_MAX_ENEMIES = 3;
int CGameDirector::MAX_AMMO = 1;

int CGameDirector::WINDOWN_X = 800;
int CGameDirector::WINDOWN_Y = 600;
int CGameDirector::GAME_FPS = 60;


CGameDirector::CGameDirector():m_player(this , 0 , 20 , 0) , m_floor() , m_terrain() , m_sky() , m_light() , m_scene(1000) , m_ammoSpawners() , m_enemySpawners() ,
                               m_walls() , m_onAmmoPickSound() , m_onShootSound() , m_onLoseLifeSound() , m_enemyHitSound() , m_enemyExplosionSound() , m_bgm()
{
    srand(time(NULL));

    m_endGame = false;
    t = 0;

    m_maxEnemies = START_MAX_ENEMIES;
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
    //Mouse::x() = WINDOWN_X/2;
    //Mouse::x() = WINDOWN_Y/2;'

    m_onAmmoPickSound.load("data/ammoPick.wav");
    m_onShootSound.load("data/shoot.wav");
    m_onLoseLifeSound.load("data/playerHit.wav");
    m_enemyHitSound.load("data/enemyHit.wav");
    m_bgm.load("data/kiss.ogg");

    //m_bgm.play();

    Texture t;
    t.load("data/terrainTEX.jpg");

    //m_terrain.load("data/heightmap.jpg" , 1 , 10 , K_FLOOR_SIZE_X , K_FLOOR_SIZE_Z , "");

    m_floor.box();
    m_floor.scale(CGameDirector::K_FLOOR_SIZE_X , 0.5 , CGameDirector::K_FLOOR_SIZE_Z);
    m_floor.createBoundingVolume(Solid::BOX);
    m_floor.staticBody();
    m_floor.type() = CGameDirector::K_FLOOR;
    m_floor.setTexture(t);

    for (int i = 0; i < 4; ++i)
    {
        m_walls.push_back(new Generic());

        m_walls[i]->box();
        m_walls[i]->setColor(40 , 30 , 30);
        m_walls[i]->createBoundingVolume(Solid::BOX);
        m_walls[i]->staticBody();
        m_walls[i]->type() = K_WALL;
        m_walls[i]->setTexture(t);
    }

    //SOUTH
    m_walls[0]->scale(K_FLOOR_SIZE_X , K_WALL_HEIGHT , 0.5);
    m_walls[0]->position(0 , 0 , -K_FLOOR_SIZE_Z/2);

    //NORTH
    m_walls[1]->scale(K_FLOOR_SIZE_X , K_WALL_HEIGHT , 0.5);
    m_walls[1]->position(0 , 0 , K_FLOOR_SIZE_Z/2);

    //EAST
    m_walls[2]->scale(0.5 , K_WALL_HEIGHT , K_FLOOR_SIZE_Z);
    m_walls[2]->position(K_FLOOR_SIZE_X/2 , 0 , 0);

    //WEST
    m_walls[3]->scale(0.5 , K_WALL_HEIGHT , K_FLOOR_SIZE_Z);
    m_walls[3]->position(-K_FLOOR_SIZE_X/2 , 0 , 0);

    m_sky.loadTexture( "data/sky.jpg");

    m_light.directional();
    m_light.direction(0.5,0.5,0);

    m_actualEnemyCount = 0;
    m_actualAmmoCount = 0;

    m_ammoSpawners.push_back(new CAmmoSpawner(-(K_FLOOR_SIZE_X/2 - 10) , 10 , 0));
    m_ammoSpawners.push_back(new CAmmoSpawner((K_FLOOR_SIZE_X/2 - 10) , 10 ,0));
    m_ammoSpawners.push_back(new CAmmoSpawner(0 , 10 , (K_FLOOR_SIZE_Z/2 - 10)));
    m_ammoSpawners.push_back(new CAmmoSpawner(0 , 10 ,-(K_FLOOR_SIZE_Z/2 - 10)));

    m_enemySpawners.push_back(new CEnemySpawner(this , -(K_FLOOR_SIZE_X/2 - 10) , 10 , -(K_FLOOR_SIZE_Z/2 - 10)));
    m_enemySpawners.push_back(new CEnemySpawner(this , (K_FLOOR_SIZE_X/2 - 10) , 10 , -(K_FLOOR_SIZE_Z/2 - 10)));
    m_enemySpawners.push_back(new CEnemySpawner(this , -(K_FLOOR_SIZE_X/2 - 10) , 10 , (K_FLOOR_SIZE_Z/2 - 10)));
    m_enemySpawners.push_back(new CEnemySpawner(this , (K_FLOOR_SIZE_X/2 - 10) , 10 , (K_FLOOR_SIZE_Z/2 - 10)));

    for (int i = 0; i < 4; ++i)
    {
        m_scene.insert(m_walls[i]);
    }

    m_scene.insert(&m_player);
    m_scene.insert(&m_light);
    m_scene.insert(&m_floor);
    m_scene.insert(&m_terrain);
    m_scene.insert(&m_sky);
    m_scene.insert(m_player.GetLanterna());

    std::vector<CBullet*>* bullets = m_player.GetAllBullets();

    for (unsigned int i = 0; i < bullets->size(); ++i)
    {
        m_scene.insert(bullets->at(i));
    }

    m_scene.prepare();
}

void CGameDirector::Update()
{
    AtualizaTempo();

    if (!m_endGame)
    {
        Mouse::render();
    }

    SpawnAmmo();
    SpawnEnemy();
    AtualizaLuz();

    UI();

    m_scene.update();
}
void CGameDirector::AtualizaLuz()
{
    m_light.direction(sin(t),cos(t),0);
}

void CGameDirector::AtualizaTempo()
{
    t += 1.0/CGameDirector::GAME_FPS  ;
}

void CGameDirector::SpawnEnemy()
{
    m_maxEnemies = START_MAX_ENEMIES + m_player.getPoints()/5;

    if (m_enemySpawners.size() <= 0) return;

    if (m_actualEnemyCount < m_maxEnemies)
    {
        m_enemySpawners[RandomRange(0 , m_enemySpawners.size() - 1)]->Activate(&m_scene);

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
    if (!m_endGame)
    {
        Text::write(10 , 10 , "Life : %d/%d" , m_player.GetLife() , m_player.GetMaxLife());
        Text::write(10 , 30 , "Ammo : %d/%d" , m_player.GetAmmo() , m_player.GetMaxAmmo());
        Text::write(10 , 50 , "Points : %d" , m_player.getPoints());
    }
    else
    {
        Text::write(WINDOWN_X/2 - 50 , WINDOWN_Y/2 , "You Got Screwed !!");
        Text::write(WINDOWN_X/2 - 50 , WINDOWN_Y/2 + 20 , "You Made %d points" , m_player.getPoints());
    }
}

int CGameDirector::RandomRange(int minVal , int maxVal)
{
    return minVal + Round(((rand() % 100)/100.0) * (maxVal - minVal));
}

double CGameDirector::RandomRange(double minVal , double maxVal)
{
    return minVal + ((rand() % 100)/100.0) * (maxVal - minVal);
}

int CGameDirector::Round(double val)
{
    double floatPart = val - floor(val);

    if ( floatPart >= 0.5 ) return (int)ceil(val);
    return (int)floor(val);
}

void CGameDirector::EnemyDied()
{
    m_actualEnemyCount--;
}

void CGameDirector::PlayerDied()
{
    m_endGame = true;
}

