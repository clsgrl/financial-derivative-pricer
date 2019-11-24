#pragma once

//#define ( MAX( a, b ) ( ( a > b) ? a : b ) )
//#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))

class Payoff
{
    public:
        enum OptionType {call, put};
        Payoff(double strike, OptionType optType);
        double operator()(double spot) const;

        inline static int max ( int a, int b ) { return a > b ? a : b; }

    private:
        double strike;
        OptionType optType;

};
