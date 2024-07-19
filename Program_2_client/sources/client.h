#pragma once
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>


class Client {
    std::string serverIP;
    int serverPort;
    int useSocket;
    const int BUFFER_SIZE = 1024;
    const int COUNT_DIGITS_RESULT = 2;
    const int MULTIPLICITY_RESULT = 32;

public:

    /**
     * Setting values
     * @param [in] inServerIP - server IP
     * @param [in] inServerPort - server port 
     */
    Client(const std::string& inServerIP, int inServerPort);

    /**
     * Connecting to the server and receiving data
     */
    void run();

private:

    bool connectToServer();

    void receiveData();

    bool isValid(const std::string& number);
};