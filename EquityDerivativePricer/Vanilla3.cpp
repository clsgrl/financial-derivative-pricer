#include "Vanilla3.h"

VanillaOption::VanillaOption(const PayoffBridge& ThePayoff_, double Expiry_) : ThePayoff(ThePayoff_), Expiry(Expiry_)
{}

double VanillaOption::GetExpiry() const
{
    return Expiry;
}

double VanillaOption::OptionPayoff(double Spot) const
{
    return ThePayoff(Spot);
}
