#include "DoubleDigital.h"

double PayoffDoubleDigital::operator()(double Spot) const
{
    if(Spot <= lowerLevel)
        return 0;
    if(Spot >= upperLevel)
        return 0;

    return 1;
}

Payoff* PayoffDoubleDigital::clone() const
{
    return new PayoffDoubleDigital(*this);
}
