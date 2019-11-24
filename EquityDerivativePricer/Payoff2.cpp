#include "Payoff2.h"
//#include "minmax.h"

PayoffCall::PayoffCall(double _strike) : strike(_strike){}
PayoffPut::PayoffPut(double _strike) : strike(_strike){}

double PayoffCall::operator()(double spot) const
{
    return max((spot - strike), 0.0);
}

double PayoffPut::operator()(double spot) const
{
    return max((strike - spot), 0.0);
}
