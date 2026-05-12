#include "ServerFramework.h"

void ServerFramework::Initialize()
{
	CreateListenSocket();
}

void ServerFramework::Run()
{
}

void ServerFramework::CreateListenSocket()
{
	WSAStartup(MAKEWORD(2, 2), &wsaData_);
	listenSocket_ = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, WSA_FLAG_OVERLAPPED);
	SOCKADDR_IN server_addr;
	ZeroMemory(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT_NUM);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(listenSocket_, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
	listen(listenSocket_, SOMAXCONN);

	int addr_size = sizeof(server_addr);
	clientSocket_ = WSAAccept(listenSocket_, reinterpret_cast<sockaddr*>(&server_addr), &addr_size, 0, 0);
}

void ServerFramework::PostAccept()
{
	
}
