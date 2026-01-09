#include "lve_window.h"
#include <cstdlib>
#include <iostream>

int main(void)
{
    game::LiveWindow app{};

    try {
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
