#ifndef VANILLA2_H_INCLUDED
#define VANILLA2_H_INCLUDED

#include "Payoff3.h"

class VanillaOption
{
    public:
        VanillaOption(const Payoff& thePayoff_, double expiry_);
        VanillaOption(const VanillaOption& original);
        VanillaOption& operator=(const VanillaOption& original);
        ~VanillaOption();

        double GetExpiry() const;
        double OptionPayoff(double spot) const;

    private:
        double Expiry;
        Payoff* thePayoffPtr;
};

#endif // VANILLA2_H_INCLUDED
