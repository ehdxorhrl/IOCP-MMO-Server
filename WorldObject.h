#pragma once
#include "stdafx.h"

sf::RenderWindow* g_window;
sf::Font g_font;

int g_left_x;
int g_top_y;
int g_myid;

class OBJECT {
private:
    bool m_showing{ false };
    sf::Sprite m_sprite;

    sf::Text m_name;
    sf::Text m_chat;
    chrono::system_clock::time_point m_mess_end_time;

public:
    int id{ -1 };
    int m_x{ 0 }, m_y{ 0 };
    char name[NAME_SIZE]{};

    OBJECT() = delete;

    OBJECT(sf::Texture& t, int x, int y, int width, int height)
        : m_sprite(t, sf::IntRect({ x, y }, { width, height })),
        m_name(g_font),
        m_chat(g_font)
    {
        set_name("NONAME");
        m_mess_end_time = chrono::system_clock::now();
    }

    void show();
    void hide();
    void a_move(int x, int y);
    void a_draw();
    void move(int x, int y);
    void draw();
    void set_name(const char str[]);
    void set_chat(const char str[]);
};