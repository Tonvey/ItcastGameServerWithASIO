#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include "Server.h"

GG_USING_NAMESPACE
int main(int argc, char* argv[])
{
    try
    {
        Server s(8899);
        s.Run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
