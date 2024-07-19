#include <iostream>
#include <thread>

#include "server.h"
#include "sharedbuffer.h"
#include "inputhandler.h"
#include "outputhandler.h"


int main() {
    SharedBuffer buffer;

    Server server(2424);
    server.run();

    InputHandler inHandler(buffer);
    OutputHandler outHendler(buffer);

    std::thread inputThread(&InputHandler::inputProcess, inHandler);
    std::thread outputThread(&OutputHandler::outputProcess, outHendler, std::ref(server));

    inputThread.join();
    outputThread.join();

    return 0;
}