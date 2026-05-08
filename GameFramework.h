#pragma once
#include "stdafx.h"

class GameFramework
{
public:
    void Initialize();
    void Run();

    sf::RenderWindow& GetWindow();
private:
    void ProcessEvents();
    void Update();
    void Render();

    sf::RenderWindow g_window;

    sf::Texture* board;
    sf::Texture* pieces;
    sf::Font g_font;


};