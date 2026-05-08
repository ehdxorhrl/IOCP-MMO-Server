#include "GameFramework.h"

void GameFramework::Initialize()
{
	// texture 불러오기
	board = new sf::Texture;
	pieces = new sf::Texture;
	if (false == board->loadFromFile("map.png")) {
		cout << "Map Load Failed!\n";
		exit(-1);
	}
	
	if (false == pieces->loadFromFile("chess.png")) {
		cout << "Piece Load Failed!\n";
		exit(-1);
	}

	if (false == g_font.openFromFile("Pretendard-Regular.otf")) {
		cout << "Font Load Failed!\n";
		exit(-1);
	}

	g_window.create(
		sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
		"MMORPG"
	);
}

void GameFramework::Run()
{
	while (g_window.isOpen())
	{
		ProcessEvents(); // 자기 클라이언트 이벤트에 대한 처리
		Update(); // 서버 연결 전까진 로컬에 대한 처리, 연결 후 패킷에 대한 처리
		Render();
	}
}

sf::RenderWindow& GameFramework::GetWindow()
{
	return g_window;
	// TODO: 여기에 return 문을 삽입합니다.
}

void GameFramework::ProcessEvents()
{
	while (const std::optional event = g_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			g_window.close();
		if (event->is<sf::Event::KeyPressed>())
			int direction = -1;
	}
}

void GameFramework::Update()
{
}

void GameFramework::Render()
{
	g_window.clear();
	g_window.display();
}
