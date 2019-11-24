#ifndef VANILLA3_H_INCLUDED
#define VANILLA3_H_INCLUDED

#include "PayoffBridge.h"

class VanillaOption
{
public:
    VanillaOption(const PayoffBridge& ThePayoff_, double Expiry_);
    double OptionPayoff(double Spot) const;
    double GetExpiry() const;

private:
    double Expiry;
    PayoffBridge ThePayoff;
};

#endif // VANILLA3_H_INCLUDED
