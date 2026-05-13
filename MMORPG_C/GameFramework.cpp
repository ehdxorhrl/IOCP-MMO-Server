#include "GameFramework.h"

void GameFramework::Initialize(char* server_ip)
{
	if (false == board_.loadFromFile("map.bmp")) {
		cout << "Map Load Failed!\n";
		exit(-1);
	}
	if (false == pieces_.loadFromFile("chess.png")) {
		cout << "Piece Load Failed!\n";
		exit(-1);
	}
	if (false == font_.openFromFile("Pretendard-Regular.otf")) {
		cout << "Font Load Failed!\n";
		exit(-1);
	}

	//cout << WINDOW_WIDTH << endl;
	//cout << WINDOW_HEIGHT << endl;
	window_.create(
		sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
		"MMORPG"
	);

	white_tile_ = WorldObject{ board_,font_, 5, 5, TILE_WIDTH, TILE_WIDTH };
	black_tile_ = WorldObject{ board_,font_, 69, 5, TILE_WIDTH, TILE_WIDTH };
	avatar_ = WorldObject{ pieces_, font_, 128, 0, 64, 64 };
	avatar_->Move(4, 4);
	avatar_->Show();
	avatar_->SetName("me");

	auto serverIp = sf::IpAddress::resolve(server_ip);

	if (serverIp.has_value() &&
		socket_.connect(serverIp.value(), PORT_NUM) == sf::Socket::Status::Done)
	{
		socket_.setBlocking(false);
		connected_ = true;
		cout << "Connected to server\n";
	}
	else
	{
		cout << "Server connection failed\n";
	}
}

void GameFramework::Run()
{
	while (window_.isOpen())
	{
		ProcessEvents(); // 자기 클라이언트 이벤트에 대한 처리, 이벤트로 인해 발생한 패킷 전송
		Update(); // 서버 연결 전까진 로컬에 대한 처리, 연결 후 패킷에 대한 처리
		Render();
	}
}

sf::RenderWindow& GameFramework::GetWindow()
{
	return window_;
}

void GameFramework::ProcessEvents()
{
	while (const std::optional event = window_.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			window_.close();
		if (event->is<sf::Event::KeyPressed>())
			int direction = -1;
	}
}	

void GameFramework::Update()
{
	
}

void GameFramework::Render()
{
	window_.clear();

	for (int i = 0; i < SCREEN_WIDTH; ++i)
		for (int j = 0; j < SCREEN_HEIGHT; ++j)
		{
			int tile_x = i + left_x;
			int tile_y = j + top_y;
			if ((tile_x < 0) || (tile_y < 0)) continue;
			if (0 == (tile_x/3 + tile_y/3) % 2) {
				white_tile_->A_Move(TILE_WIDTH * i, TILE_WIDTH * j);
				white_tile_->A_Draw(window_);
			}
			else
			{
				black_tile_->A_Move(TILE_WIDTH * i, TILE_WIDTH * j);
				black_tile_->A_Draw(window_);
			}
		}
	avatar_->Draw(window_, 4 - SCREEN_WIDTH / 2, 4 - SCREEN_HEIGHT / 2);
	for (auto& pl : players_) pl.second.Draw(window_,0,0);
	sf::Text text(font_);
	char buf[100];
	sprintf_s(buf, "(%d, %d)", avatar_->x, avatar_->y);
	text.setString(buf);
	window_.draw(text);

	window_.display();
}
