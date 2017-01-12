#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main( void )
{
    std::vector<int> v(3, 0);
    v[0] = 3;
    v[2] = 1;
    v.push_back( 25 );
    v.push_back( 13 );

    std::sort( v.begin(), v.end(), [](int x, int y){ return x<y; } );

    auto it = v.cbegin();
    while ( it != v.cend() ) {
        std::cout << '\t' << *it;
        ++it;
    }
    std::cout << "\n";

    // getchar();
    return 0;
}
