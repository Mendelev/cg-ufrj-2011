#include <URGE/URGE.h>
#include <stdio.h>
#include "src\CGameDirector.h"

USING_URGE;

void InitializeLevel(Scenario* scene)
{

}

URGE_BEGIN
{
    //new window:RX, RY, FPS, PARAMS,  WINDOW TITTLE,      RENDER QUALITY LEVEL
    gimme_window(800,600,60, WINDOWED, "URGE Application", NO_SHADER | RENDER_QUALITY_AVERAGE);

    CGameDirector gameDirector;
    gameDirector.InitializeLevel();

    do
    {
        if (Keyboard::hit(KEYBOARD_ESC))  break;

        Mouse::render();

        gameDirector.Update();

        next_frame();
    }while(true);


    thanks_byebye();
}
URGE_END

