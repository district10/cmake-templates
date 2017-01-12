#include <stdio.h>
#include "functions.h"

int main ( int argc, char **argv )
{
    double x = 9.8;
    fprintf( stdout, "Square of %5.2f is %18.6f\n", x, square(x) );
    fprintf( stdout, "Cubic  of %5.2f is %18.6f\n", x, cubic(x) );
    fprintf( stdout, "x^4    of %5.2f is %18.6f\n", x, power4(x) );
    fprintf( stdout, "x^5    of %5.2f is %18.6f\n", x, power5(x) );

    // getchar();
    return 0;
}
