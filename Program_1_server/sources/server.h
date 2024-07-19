#pragma once
#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

class Server
{
    int useSocket;
    int listener;
    static const int BUFFER_SIZE = 1024;

public:

    /**
     * Creating a socket
     * @param [in] port - client port 
     */
    Server(int port);

    /**
     * Sending the value to the client
     * @param [in] num - value 
     */
    void send(std::string num);

    /**
     * Connecting to the client (reconnecting)
     */
    void run();
};