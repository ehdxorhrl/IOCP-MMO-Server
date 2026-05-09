#pragma once
#include "stdafx.h"

class WorldObject
{
private:
    bool showing_{ false };

    sf::Sprite sprite_;
    sf::Text nameText_;
    sf::Text chatText_;

    std::chrono::steady_clock::time_point messageEndTime_;

public:
    int id{ -1 };
    int x{ 0 };
    int y{ 0 };
    char name[NAME_SIZE]{};

public:
    WorldObject() = delete;

    WorldObject(
        sf::Texture& texture,
        const sf::Font& font,
        int textureX,
        int textureY,
        int width,
        int height
    );

    void Show();
    void Hide();

    void A_Move(int x, int y);
    void A_Draw(sf::RenderWindow& window);

    void Move(int x, int y);
    void Draw(sf::RenderWindow& window, int leftX, int topY);

    void SetName(const char str[]);
    void SetChat(const char str[]);
};