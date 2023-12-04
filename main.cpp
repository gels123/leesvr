#include <iostream>
#include "Utils.h"
#include "hiredis.h"

int main() {
    std::cout << "Hello, World! Time=" << Utils::getTimestamp() << std::endl;
    return 0;
}
