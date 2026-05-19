#pragma once
#include "stdafx.h"

class ServerFramework
{
public:
    void Initialize();
    void Run();
    void Shutdown();
    ~ServerFramework();

private:
    void CreateListenSocket();
    //void CreateIOCP() {};
    //void StartWorkerThreads() {};
    void PostAccept();
    //void WorkerThread();

private:
    SOCKET listenSocket_{ INVALID_SOCKET };
    SOCKET clientSocket_{ INVALID_SOCKET };
    HANDLE iocpHandle_{ INVALID_HANDLE_VALUE };

    WSADATA wsaData_;
    std::vector<std::thread> workerThreads_;

    bool isRunning_ = false;
    //unordered_map<int, class Session> sessions_;
    //World world_;
};

