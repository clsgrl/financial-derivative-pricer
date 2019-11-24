#include "DoubleDigital.h"

double PayoffDoubleDigital::operator()(double spot) const
{
    if(spot <= lowerLevel)
        return 0;
    if(spot >= upperLevel)
        return 0;

    return 1;
}
