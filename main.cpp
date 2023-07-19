#include "message_broker.h"
#include <iostream>

int main() {
    MessageBroker broker("mydatabase.db");

    std::cout << broker.isInitialized()<<std::endl;

    return 0;
}
