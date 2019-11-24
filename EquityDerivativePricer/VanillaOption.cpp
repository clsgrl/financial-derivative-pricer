#include "Vanilla1.h"

double VanillaOptionOld::GetExpiry() const
{
    return expiry;
}

double VanillaOptionOld::OptionPayoff(double spot) const
{
    return thePayoff(spot);
}
