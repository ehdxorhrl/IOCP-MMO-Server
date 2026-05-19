#include "ServerFramework.h"
#include "protocol.h"

void ServerFramework::Initialize()
{
	CreateListenSocket();
}

void ServerFramework::Run()
{
	while (isRunning_)
	{
		char buffer[BUF_SIZE]{};
		int recvBytes = recv(clientSocket_, buffer, BUF_SIZE, 0);
		if (recvBytes <= 0)
		{
			std::cout << "Client disconnected\n";
			closesocket(clientSocket_);
			break;
		}
		std::cout << "Recv: " << buffer << std::endl;

		send(clientSocket_, buffer, recvBytes, 0);
	}
}

void ServerFramework::Shutdown()
{
	isRunning_ = false;

	for (auto& w : workerThreads_)
	{
		if (w.joinable())
			w.join();
	}
	WSACleanup();
}

ServerFramework::~ServerFramework()
{
	Shutdown();
}

void ServerFramework::CreateListenSocket()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData_);
	listenSocket_ = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);
	SOCKADDR_IN server_addr;
	ZeroMemory(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(listenSocket_, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
	listen(listenSocket_, SOMAXCONN);

	int addr_size = sizeof(server_addr);
	clientSocket_ = WSAAccept(listenSocket_, reinterpret_cast<sockaddr*>(&server_addr), &addr_size, 0, 0);
	isRunning_ = true;
}

void ServerFramework::PostAccept()
{
	
}
