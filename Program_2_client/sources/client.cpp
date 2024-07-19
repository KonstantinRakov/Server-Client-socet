#include "client.h"


Client::Client(const std::string &inServerIP, int inServerPort)
    : serverIP(inServerIP), serverPort(inServerPort) {}


void Client::run() {
    while (true) {
        if (!connectToServer()) {            
            sleep(1);
            continue;
        }        
        receiveData();
        close(useSocket);
    }
}

bool Client::connectToServer() {
    useSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (useSocket < 0) {
        std::cerr << "Error: soket" << std::endl;
        return false;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverIP.c_str(), &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "Error: server IP" << std::endl;
        close(useSocket);
        return false;
    }

    if (connect(useSocket, reinterpret_cast<const sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        close(useSocket); 
        return false;
    }
         
    return true;
}

void Client::receiveData() {
    char buffer[BUFFER_SIZE];
    while (true) {
        memset(buffer, 0, BUFFER_SIZE);
        if (read(useSocket, buffer, BUFFER_SIZE - 1) <= 0) {
            break;
        }
        std::string data(buffer);
        if (isValid(data)){
        std::cout << "Get data: " << buffer << std::endl;
        } else {
        std::cout << "Error: data is not valid" << std::endl;
        }
        
    }
}

bool Client::isValid(const std::string& number)
{
    return number.length() >= COUNT_DIGITS_RESULT && std::stoi(number) % MULTIPLICITY_RESULT == 0;
}