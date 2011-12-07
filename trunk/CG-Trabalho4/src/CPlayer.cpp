#include "CPlayer.h"

#include "CGameDirector.h"

double CPlayer::JUMP_FORCE = 400;
double CPlayer::MOVE_SPEED = 40;
double CPlayer::ROTATION_SPEED = 3;

int CPlayer::MAX_LIFE = 100;
int CPlayer::START_AMMO = 5;
int CPlayer::MAX_AMMO = 10;

CPlayer::CPlayer(CGameDirector* gd , double x , double y , double z):Camera(Camera::FIRST_PERSON) , lanterna()
{
    m_gameDirector = gd;

    m_loadedBullets = new std::vector<CBullet*>;
    m_flyingBullets = new std::vector<CBullet*>;

    position(x , y , z);
    type() = CGameDirector::K_PLAYER;

    m_isJumping = false;
    this->points=0;
    controller().disableMouse();

    this->linearSpeed() = MOVE_SPEED;
    this->rotationSpeed() = ROTATION_SPEED;
    this->activeBody();
    this->body->scale(5);
    this->body->gravityScale() = 1.2;

    this->lanterna.setColor(255,255,255);
    this->lanterna.spot();
    this->lanterna.setIntensity(0);
    this->lanterna.setSpotAngle(20);
    this->lanterna.setSpotAttenuation(120);

    m_life = MAX_LIFE;
    m_ammo = START_AMMO;

    CreateBullets();
}

CPlayer::~CPlayer()
{
    //dtor
}

void CPlayer::CreateBullets()
{
    for (int i = 0; i < 10; ++i)
    {
        CBullet* bullet = new CBullet(this);
        m_loadedBullets->push_back(bullet);
    }
}

/*ENGINE FUNCTIONS*/

void CPlayer::act()
{
    if (behavior() == 2) return;

    if (m_life <= 0)
    {
        Die();
    }

    if(Input::Keyboard::hit(KEYBOARD_SPACE))
    {
        Jump();
    }

    /*if (Input::Keyboard::check(KEYBOARD_A))
    {
        body->vel -= this->frustum->right * linearSpeed()/2;
    }

    if (Input::Keyboard::check(KEYBOARD_D))
    {
        body->vel += this->frustum->right * linearSpeed()/2;
    }*/

    if (Mouse::hit(MOUSE_LEFT))
    {
        Shoot();
    }

    if (Mouse::check(MOUSE_RIGHT))
    {
        TurnOnLight();
    }
    else
    {
        TurnOffLight();
    }

    //std::cout << "Loaded " << m_loadedBullets->size() << " / " << m_flyingBullets->size() << std::endl;

    ClearBullets();
}

int CPlayer::collide(Object& obj)
{
    if (obj.type() == CGameDirector::K_FLOOR)
    {
        if (m_isJumping) m_isJumping = false;
    }
    else if (obj.type() == CGameDirector::K_DROP)
    {
        ChangeAmmo(3);
        m_gameDirector->AmmoPicked();
        obj.inactiveBody();
    }

    // Depois da sua ação, chame a collide() padrão.
    return Object::collide(obj);
}

/*ACTIONS*/

void CPlayer::Jump()
{
    if (m_isJumping) return;

    this->body->vel = this->frustum->top * CPlayer::JUMP_FORCE;
    m_isJumping = true;
}

void CPlayer::Shoot()
{
    if (HasAmmo())
    {
        CBullet* bullet = GetBullet();

        if (bullet != NULL)
        {
            bullet->Fly(position() , Mouse::ray());
            ChangeAmmo(-1);
        }
    }
}

void CPlayer::Die()
{
    m_gameDirector->PlayerDied();
    inactiveBody();
}

void CPlayer::ClearBullets()
{
    for (std::vector<CBullet*>::iterator it = m_flyingBullets->begin() ; it < m_flyingBullets->end(); it++ )
    {
        if (((*it)->position() - position()).length() > CGameDirector::K_FLOOR_SIZE_Z)
        {
            CBullet* bullet = (*it);
            m_flyingBullets->erase(it);

            bullet->Stop();

            m_loadedBullets->push_back(bullet);
        }
    }
}

/*GETTERS & SETTERS*/

CBullet* CPlayer::GetBullet()
{
    if (m_loadedBullets->size() <= 0) return NULL;

    CBullet* bullet = m_loadedBullets->back();
    m_loadedBullets->pop_back();
    m_flyingBullets->push_back(bullet);

    return bullet;
}

void CPlayer::ChangeAmmo(int ammount)
{
    m_ammo += ammount;
    m_ammo = max(m_ammo , 0);
    m_ammo = min(m_ammo , MAX_AMMO);
}

void CPlayer::ChangeLife(int ammount)
{
    m_life += ammount;
    m_life = max(m_life , 0);
    m_life = min(m_life , MAX_LIFE);
}

void CPlayer::Reload(CBullet* bullet)
{
    std::vector<CBullet*>::iterator it;

    for (it = m_flyingBullets->begin(); it != m_flyingBullets->end(); ++it)
    {
        if ((*it) == bullet)
        {
            CBullet* bullet = (*it);
            m_flyingBullets->erase(it);

            m_loadedBullets->push_back(bullet);
            break;
        }
    }
}

void CPlayer::TurnOnLight()
{
    this->lanterna.setIntensity(5);
    this->lanterna.position() = position();
    this->lanterna.direction(Mouse::ray());
}

void CPlayer::TurnOffLight()
{
    this->lanterna.setIntensity(0);
}

Light* CPlayer::GetLanterna()
{
    return &lanterna;
}

int CPlayer::getPoints(){
    return this->points;
}
int CPlayer::changePoints(int mudanca){
    this->points+=mudanca;
    return this->points;
};

