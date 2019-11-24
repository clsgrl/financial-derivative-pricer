#ifndef DOUBLEDIGITAL_H_INCLUDED
#define DOUBLEDIGITAL_H_INCLUDED

#include "Payoff2.h"

class PayoffDoubleDigital : public Payoff
{
    public:
        PayoffDoubleDigital(double _lowerLevel, double _upperLevel) :
            lowerLevel(_lowerLevel), upperLevel(_upperLevel){}
        virtual double operator()(double spot) const;
        virtual ~PayoffDoubleDigital(){}
        virtual Payoff* clone() const;
    private:
        double lowerLevel, upperLevel;
};

#endif // DOUBLEDIGITAL_H_INCLUDED
