#ifndef PAYOFF3_H_INCLUDED
#define PAYOFF3_H_INCLUDED

class Payoff
{
    public:
        Payoff(){};
        virtual double operator()(double spot) const = 0;
        virtual ~Payoff(){}
        virtual Payoff* clone() const = 0;
};

class PayoffCall : public Payoff
{
    public:
        PayoffCall(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayoffCall(){}
        virtual Payoff* clone() const;

    private:
        double Strike;
};

class PayoffPut : public Payoff
{
    public:
        PayoffPut(double Strike_);
        virtual double operator()(double Spot) const;
        virtual ~PayoffPut(){}
        virtual Payoff* clone() const;

    private:
        double Strike;
};

#endif // PAYOFF3_H_INCLUDED
