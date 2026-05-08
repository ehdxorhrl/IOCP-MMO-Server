#include "stdafx.h"
#include "WorldObject.h"

int main()
{
    wcout.imbue(locale("korean"));

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "MMORPG");

    while (window.isOpen())
    {
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }
    return 0;
}