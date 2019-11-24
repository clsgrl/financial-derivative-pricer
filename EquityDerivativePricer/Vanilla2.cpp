#include "Vanilla2.h"

VanillaOption::VanillaOption(const Payoff& thePayoff_, double expiry_) : Expiry(expiry_)
{
    thePayoffPtr = thePayoff_.clone();
}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayoff(double spot) const
{
    return (*thePayoffPtr)(spot);
}

VanillaOption::VanillaOption(const VanillaOption& original)
{
    Expiry = original.Expiry;
    thePayoffPtr = original.thePayoffPtr->clone();
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
    if(this != &original)
    {
        Expiry = original.Expiry;
        delete thePayoffPtr;
        thePayoffPtr = original.thePayoffPtr->clone();
    }

    return *this;

}

VanillaOption::~VanillaOption()
{
    delete thePayoffPtr;
}
