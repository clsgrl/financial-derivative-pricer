#include "Vanilla1.h"

double VanillaOption::GetExpiry() const
{
    return expiry;
}

double VanillaOption::OptionPayoff(double Spot) const
{
    return thePayoff(Spot);
}
