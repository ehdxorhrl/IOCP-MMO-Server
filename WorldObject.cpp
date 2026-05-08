#include "stdafx.h"
#include "WorldObject.h"

void OBJECT::show()
{
    m_showing = true;
}

void OBJECT::hide()
{
    m_showing = false;
}

void OBJECT::a_move(int x, int y)
{
    m_sprite.setPosition(sf::Vector2f{ static_cast<float>(x), static_cast<float>(y) });
}

void OBJECT::a_draw()
{
    g_window->draw(m_sprite);
}

void OBJECT::move(int x, int y)
{
    m_x = x;
    m_y = y;
}

void OBJECT::draw()
{
    if (!m_showing) return;

    const float rx = (m_x - g_left_x) * 65.0f + 1.0f;
    const float ry = (m_y - g_top_y) * 65.0f + 1.0f;

    m_sprite.setPosition(sf::Vector2f{ rx, ry });
    g_window->draw(m_sprite);

    const auto size = m_name.getGlobalBounds();

    if (m_mess_end_time < chrono::system_clock::now()) {
        m_name.setPosition(sf::Vector2f{ rx + 32.0f - size.size.x / 2.0f, ry - 10.0f });
        g_window->draw(m_name);
    }
    else {
        m_chat.setPosition(sf::Vector2f{ rx + 32.0f - size.size.x / 2.0f, ry - 10.0f });
        g_window->draw(m_chat);
    }
}

void OBJECT::set_name(const char str[])
{
    m_name.setFont(g_font);
    m_name.setString(str);
    if (id < MAX_USER) m_name.setFillColor(sf::Color(255, 255, 255));
    else m_name.setFillColor(sf::Color(255, 255, 0));
    m_name.setStyle(sf::Text::Bold);
}

void OBJECT::set_chat(const char str[])
{
    m_chat.setFont(g_font);
    m_chat.setString(str);
    m_chat.setFillColor(sf::Color(255, 255, 255));
    m_chat.setStyle(sf::Text::Bold);
    m_mess_end_time = chrono::system_clock::now() + chrono::seconds(3);
}