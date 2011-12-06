#include "CPlayer.h"

#include "CGameDirector.h"

double CPlayer::JUMP_FORCE = 400;
double CPlayer::MOVE_SPEED = 30;
double CPlayer::ROTATION_SPEED = 3;

int CPlayer::MAX_LIFE = 100;
int CPlayer::START_AMMO = 5;
int CPlayer::MAX_AMMO = 10;

CPlayer::CPlayer(CGameDirector* gd , double x , double y , double z):Camera(Camera::FIRST_PERSON)
{
    m_gameDirector = gd;

    m_loadedBullets = new std::vector<CBullet*>;
    m_flyingBullets = new std::vector<CBullet*>;

    position(x , y , z);
    type() = CGameDirector::K_PLAYER;

    m_isJumping = false;

    controller().disableMouse();

    this->linearSpeed() = MOVE_SPEED;
    this->rotationSpeed() = ROTATION_SPEED;
    this->activeBody();
    this->body->scale(5);
    this->body->gravityScale() = 0.8;

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
    for (int i = 0; i < 1; ++i)
    {
        CBullet* bullet = new CBullet();
        m_loadedBullets->push_back(bullet);
    }
}

/*ENGINE FUNCTIONS*/

void CPlayer::act()
{
    if(Input::Keyboard::hit(KEYBOARD_SPACE))
    {
        Jump();
    }

    if (Mouse::hit(MOUSE_LEFT))
    {
        Shoot();
    }

    std::cout << "Loaded " << m_loadedBullets->size() << " / " << m_flyingBullets->size() << std::endl;

    //ClearBullets();
}

int CPlayer::collide(Object& obj)
{
    if (obj.type() == CGameDirector::K_FLOOR)
    {
        if (m_isJumping) m_isJumping = false;
    }
    else if (obj.type() == CGameDirector::K_DROP)
    {
        ChangeAmmo(1);
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
        Text::write(400,300,"TIRO:  X:%d,  Y:%d",Mouse::x(),Mouse::y());

        CBullet* bullet = GetBullet();

        if (bullet != NULL)
        {
            std::cout << " Passei  2"  << std::endl;

            bullet->Fly(position() , Mouse::ray());
            ChangeAmmo(-1);

            std::cout << " Passei 3"  << std::endl;
        }
    }
}

void CPlayer::ClearBullets()
{
    for (std::vector<CBullet*>::iterator it = m_flyingBullets->begin() ; it < m_flyingBullets->end(); it++ )
    {
        if (((*it)->position() - position()).length() > 10)
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

void CPlayer::TakeDamage(int ammount)
{
    m_life += ammount;
    m_life = max(m_life , 0);
    m_life = min(m_life , MAX_LIFE);
}
