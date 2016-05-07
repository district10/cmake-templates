#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int main ( int argc, char **argv )
{
    std::cout << std::string("Contents in vector:\n") << std::endl;

    std::vector<int> v(3, 0);
    v[2] = 2;
    v.push_back(3);
    v.push_back(4);

    for( std::vector<int>::iterator it = v.begin(); it != v.end(); ++it ) {
        std::cout << "\t" << *it << '\n';
    }

    getchar();
    return 0;
}
