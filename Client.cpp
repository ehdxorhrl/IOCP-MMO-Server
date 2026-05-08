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


//sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "MMORPG");
//g_window = &window;
//
//while (window.isOpen())
//{
//    while (std::optional<sf::Event> event = window.pollEvent())
//    {
//        if (event->is<sf::Event::Closed>())
//            window.close();
//    }
//
//    window.clear(sf::Color::Black);
//    window.display();
//}