#include "stdafx.h"
#include "WorldObject.h"
#include "GameFramework.h"

GameFramework game_framework;

int main()
{
    wcout.imbue(locale("korean"));

    game_framework.Initialize();
    game_framework.Run();
    
    return 0;
}