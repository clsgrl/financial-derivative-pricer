#ifndef VANILLA1_H_INCLUDED
#define VANILLA1_H_INCLUDED

#include "Payoff2.h"

class VanillaOption
{
    public:
        VanillaOption(Payoff& _thePayoff, double _expiry) : thePayoff(_thePayoff), expiry(_expiry) {}
        double GetExpiry() const;
        double OptionPayoff(double spot) const;

    private:
        double expiry;
        Payoff& thePayoff;
};

#endif // VANILLA1_H_INCLUDED
