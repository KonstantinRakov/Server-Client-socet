#pragma once
#include <iostream>
#include <numeric>

#include "sharedbuffer.h"
#include "server.h"


class OutputHandler
{
private:
    SharedBuffer &buffer;

    /**
     * Calculates the sum of only numeric values in a row
     * @param [in] str - string of values
     * @return sum of the digits only
     */
    int digitSum(const std::string &str);

public:

    /**
     * Connecting to a shared buffer
     * @param [in] inBuffer - shared buffer
     */
    OutputHandler(SharedBuffer &inBuffer);

    /**
     * displays the data on the screen, calculates the amount and sends
     * @param [in] server - instance of the server class
     */
    void outputProcess(Server &server);
};