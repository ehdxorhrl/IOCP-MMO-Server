#pragma once
#include "stdafx.h"
#include "WorldObject.h"

class GameFramework
{
public:
    void Initialize(char* server_ip);
    void Run();

    sf::RenderWindow& GetWindow();
private:
    void ProcessEvents();
    void Update();
    void Render();

    sf::RenderWindow window_;

    sf::Texture board_;
    sf::Texture pieces_;
    sf::Font font_;

    optional<WorldObject> avatar_;
    unordered_map<int, WorldObject> players_;
    optional<WorldObject> white_tile_;
    optional<WorldObject> black_tile_;

    int my_id;
    int left_x;
    int top_y;
    int g_myid;

    sf::TcpSocket socket_;
    bool connected_{ false };
};