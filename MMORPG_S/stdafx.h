#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>

#include <Windows.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <optional>
#include <chrono>
#include <queue>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "ws2_32.lib")

constexpr int PORT_NUM = 4000;

constexpr int W_WIDTH = 2000;
constexpr int W_HEIGHT = 2000;

constexpr int MAX_USER = 10000;
	

