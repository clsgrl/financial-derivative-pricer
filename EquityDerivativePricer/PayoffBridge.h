#ifndef PAYOFFBRIDGE_H_INCLUDED
#define PAYOFFBRIDGE_H_INCLUDED

#include "Payoff3.h"

class PayoffBridge
{
    public:
        PayoffBridge(const PayoffBridge& original);
        PayoffBridge(const Payoff& innerPayoff);

        inline double operator()(double spot) const;
        ~PayoffBridge();
        PayoffBridge& operator=(const PayoffBridge& original);

    private:
        Payoff* thePayoffPtr;
};

inline double PayoffBridge::operator()(double spot) const
{
    return thePayoffPtr->operator()(spot);
}

#endif // PAYOFFBRIDGE_H_INCLUDED

