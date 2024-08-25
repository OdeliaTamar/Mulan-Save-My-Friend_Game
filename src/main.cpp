#include "Controller.h"
#include <SFML/Graphics.hpp>
int main()try
{
    srand(std::time(nullptr));
    Controller c;
    c.run();
}
catch (std::exception& ex)
{
    std::cerr << "Exception: " << ex.what() << '\n';
    return EXIT_FAILURE;
}