#include "stdafx.h"
#include "WorldObject.h"

WorldObject::WorldObject(
    sf::Texture& texture,
    const sf::Font& font,
    int textureX,
    int textureY,
    int width,
    int height
)
    : sprite_(texture, sf::IntRect({ textureX, textureY }, { width, height })),
    nameText_(font),
    chatText_(font)
{
    SetName("NONAME");
    messageEndTime_ = std::chrono::steady_clock::now();
}

void WorldObject::Show()
{
    showing_ = true;
}

void WorldObject::Hide()
{
    showing_ = false;
}

void WorldObject::A_Move(int x, int y) {
    sprite_.setPosition({(float)x, (float)y});
}

void WorldObject::A_Draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}
void WorldObject::Move(int x, int y)
{
    this->x = x;
    this->y = y;
}

void WorldObject::Draw(sf::RenderWindow& window, int leftX, int topY)
{
    if (!showing_) return;

    const float rx = static_cast<float>((x - leftX) * TILE_WIDTH + 1);
    const float ry = static_cast<float>((y - topY) * TILE_WIDTH + 1);

    sprite_.setPosition({ rx, ry });
    window.draw(sprite_);    

    if (messageEndTime_ < std::chrono::steady_clock::now())
    {
        const auto size = nameText_.getGlobalBounds();
        nameText_.setPosition({ rx + 32.0f - size.size.x / 2.0f, ry - 10.0f });
        window.draw(nameText_);
    }
    else
    {
        const auto size = chatText_.getGlobalBounds();
        chatText_.setPosition({ rx + 32.0f - size.size.x / 2.0f, ry - 10.0f });
        window.draw(chatText_);
    }
}

void WorldObject::SetName(const char str[])
{
    nameText_.setString(str);
    if (id < MAX_USER) nameText_.setFillColor(sf::Color(255, 255, 255));
    else nameText_.setFillColor(sf::Color(255, 255, 0));
    nameText_.setStyle(sf::Text::Bold);
}

void WorldObject::SetChat(const char str[])
{
    chatText_.setString(str);
    chatText_.setFillColor(sf::Color::White);
    chatText_.setStyle(sf::Text::Bold);

    messageEndTime_ =
        std::chrono::steady_clock::now() + std::chrono::seconds(3);
}

