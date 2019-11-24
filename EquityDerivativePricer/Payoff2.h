#ifndef PAYOFF2_H_INCLUDED
#define PAYOFF2_H_INCLUDED

class Payoff
{
    public:
        Payoff(){};
        virtual double operator()(double spot) const = 0;
        virtual ~Payoff(){}
        inline static int max ( int a, int b ) { return a > b ? a : b; }
    private:

};

class PayoffCall : public Payoff
{
    public:
        PayoffCall(double _strike);
        virtual double operator()(double spot) const;
        virtual ~PayoffCall(){}
    private:
        double strike;
};

class PayoffPut : public Payoff
{
    public:
        PayoffPut(double _strike);
        virtual double operator()(double spot) const;
        virtual ~PayoffPut(){}
    private:
        double strike;
};
#endif // PAYOFF2_H_INCLUDED
