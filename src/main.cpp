#include "engine/anvilengine.h"

#include <iostream>

int main()
{
    try {
        anvilengine engine(1360, 768);
        engine.start();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
