#include "stdafx.h"
#include "ServerFramework.h"
ServerFramework serverframework;

int main()
{
	std::wcout.imbue(std::locale("korean"));

	serverframework.Initialize();
	serverframework.Run();
	
	WSACleanup();
	return 0;
}