#pragma once
#include <iostream>
#include <algorithm>

#include "sharedbuffer.h"


class InputHandler
{
private:
    SharedBuffer &buffer;
    const std::string REPLACEMENT = "KB";
    const int MAX_LENGTH_INPUT = 64;

    /**
     * Checking the string for validity
     * @param [in] str - string of values
     * @return true - if the string is valid
     */
    bool isValid(const std::string &str);

    /**
     * sorts and replaces even numbers with "REPLACEMENT"
     * @param [in] str - string of values
     * @return modified string
     */
    std::string sortAndReplace(std::string str);

public:

    /**
     * Connecting to a shared buffer
     * @param [in] inBuffer - shared buffer
     */
    InputHandler(SharedBuffer &inBuffer);

    /**
     * Processes user input and writes data to the shared bufferr
     */
    void inputProcess();
};