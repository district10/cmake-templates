#include <iostream>
#include <boost/timer.hpp>
#include <stdio.h>

int main( int argc, char **argv )
{
    boost::timer t;
    std::cout << "max timespan: "
              << t.elapsed_max() / 3600 << "h" << std::endl;
    std::cout << "min timespan: "
              << t.elapsed_min() << "s" << std::endl;
    std::cout << "now times elapsed: "
              << t.elapsed() << "s" << std::endl;

    getchar();
    return 0;
}
