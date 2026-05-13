#include "stdafx.h"
#include "WorldObject.h"
#include "GameFramework.h"

GameFramework game_framework;

int main()
{
    wcout.imbue(locale("korean"));

    char server_ip[32];

    cout << "Input server IP: ";
    cin.getline(server_ip, 32);
    if (strlen(server_ip) == 0) strcpy_s(server_ip, "127.0.0.1");

    game_framework.Initialize(server_ip);
    game_framework.Run();
    
    return 0;
}