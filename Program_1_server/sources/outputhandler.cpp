#include "outputhandler.h"


int OutputHandler::digitSum(const std::string &str)
{
    return std::accumulate(str.begin(), str.end(), 0, [](const int& sum, const char& num){
        return sum + (::isdigit(num) ? (num - '0') : 0);
    });
}

OutputHandler::OutputHandler(SharedBuffer &inBuffer) :
    buffer(inBuffer) {}

void OutputHandler::outputProcess(Server &server)
{
    while (true) {
        std::string data = buffer.readOnNotified();
        std::cout << data << std::endl;
        int sum = digitSum(std::move(data));
        server.send(std::move(std::to_string(sum)));
    }
}