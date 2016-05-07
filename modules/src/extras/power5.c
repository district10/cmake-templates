#include "extras.h"
#include "square.h"
#include "cubic.h"

double power5( double x )
{
    return cubic(x) * square(x);
}
