#include "Payoff1.h"

Payoff::Payoff(double _strike, OptionType _optType) : strike(_strike), optType(_optType)
{
}

double Payoff::operator()(double spot) const
{
    switch(optType)
    {
        case call:
            return max((spot - strike), 0.0);
        case put:
            return max((strike - spot), 0.0);
        //case digitalcall:
        //    return (spot >= strike ? 1.0 : 0.0);
        default:
            throw("Unknown option type");
    }
}
