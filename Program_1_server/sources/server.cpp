#include "server.h"

Server::Server(int port)
{
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0) {        
        std::cerr << "Error: socket" << std::endl;
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        std::cerr << "Error: bind" << std::endl;
        exit(2);
    }
    listen(listener, 1);
}

void Server::send(std::string num)
{
    ::send(useSocket, num.c_str(), num.size(), 0);
}

void Server::run()
{
    useSocket = accept(listener, NULL, NULL);
    std::thread reconnectionThread([&](){
        char buffer[BUFFER_SIZE];
        while(true) {
            if (read(useSocket, buffer, BUFFER_SIZE - 1 ) <= 0) {
                close(useSocket);
                useSocket = accept(listener, NULL, NULL);
            }
        }
    });
    reconnectionThread.detach();
}