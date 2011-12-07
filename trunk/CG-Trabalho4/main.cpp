#include <URGE/URGE.h>
#include <stdio.h>
#include "src\CGameDirector.h"
#include <iostream>

USING_URGE;

void InitializeLevel(Scenario* scene)
{

}

URGE_BEGIN
{
    //new window:RX, RY, FPS, PARAMS,  WINDOW TITTLE,      RENDER QUALITY LEVEL
    gimme_window(CGameDirector::WINDOWN_X , CGameDirector::WINDOWN_Y, CGameDirector::GAME_FPS , WINDOWED, "URGE Application", RENDER_QUALITY_HIGH);

    CGameDirector gameDirector;
    gameDirector.InitializeLevel();

    do
    {
        if (Keyboard::hit(KEYBOARD_ESC))  break;

        gameDirector.Update();

        next_frame();
    }while(true);


    thanks_byebye();
}
URGE_END

