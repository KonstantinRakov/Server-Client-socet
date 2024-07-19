#include "inputhandler.h"


bool InputHandler::isValid(const std::string &str)
{
    return !str.empty() && str.length() <= MAX_LENGTH_INPUT && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string InputHandler::sortAndReplace(std::string str)
{
    std::sort(str.rbegin(), str.rend());
    std::string newString;
    for(char c : str)
        if(c % 2 == 0){
            newString += REPLACEMENT;
        } else {
            newString += c;
        }            
    return newString;
}

InputHandler::InputHandler(SharedBuffer &inBuffer) :
    buffer(inBuffer){}

void InputHandler::inputProcess()
{
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        if(isValid(input)) {
            std::string processedInput = sortAndReplace(std::move(input));
            buffer.writeAndNotify(std::move(processedInput));
        }
    }
}