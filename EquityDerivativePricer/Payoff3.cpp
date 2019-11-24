#include "Payoff3.h"
#include "Minmax.h"

PayoffCall::PayoffCall(double Strike_) : Strike(Strike_) {}
PayoffPut::PayoffPut(double Strike_) : Strike(Strike_) {}

double PayoffCall::operator()(double Spot) const
{
    return max(Spot-Strike, 0.0);
}

double PayoffPut::operator()(double Spot) const
{
    return max(Strike-Spot, 0.0);
}

Payoff* PayoffCall::clone() const
{
    return new PayoffCall(*this);
}

Payoff* PayoffPut::clone() const
{
    return new PayoffPut(*this);
}
