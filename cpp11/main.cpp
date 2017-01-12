#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main( void )
{
    std::vector<int> v = {7, 5, 16, 8};

    v.push_back( 25 );
    v.push_back( 13 );

    auto it = v.cbegin();
    while ( it != v.cend() ) {
        std::cout << '\t' << *it;
        ++it;
    }
    std::cout << "\n";

    std::sort( v.begin(), v.end(), [](int x, int y){ return x<y; } );

    for( int n : v ) {
        std::cout << '\t' << n;
    }
    std::cout << "\n";

    // getchar();
    return 0;
}
