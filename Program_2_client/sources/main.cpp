#include <iostream>

#include "client.h"

int main() {    
    
    Client client("127.0.0.1", 2424);
    client.run();

    return 0;
}