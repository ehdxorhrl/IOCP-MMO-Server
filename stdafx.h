#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <chrono>
#include <optional>
#include <unordered_map>
#include <Windows.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "ws2_32.lib")

using namespace std;

constexpr int PORT_NUM = 4000;
constexpr int BUF_SIZE = 200;
constexpr int NAME_SIZE = 20;
constexpr int CHAT_SIZE = 100;

constexpr int W_WIDTH = 2000;
constexpr int W_HEIGHT = 2000;

constexpr auto SCREEN_WIDTH = 17;
constexpr auto SCREEN_HEIGHT = 17;

constexpr int MAX_USER = 10000;

constexpr auto TILE_WIDTH = 65;
constexpr auto WINDOW_WIDTH = SCREEN_WIDTH * TILE_WIDTH;   // size of window
constexpr auto WINDOW_HEIGHT = SCREEN_HEIGHT * TILE_WIDTH;

