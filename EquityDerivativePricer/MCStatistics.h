#ifndef MCSTATISTICS_H_INCLUDED
#define MCSTATISTICS_H_INCLUDED

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC(){}

    virtual void DumpOneResult(double result) = 0;
    virtual std::vector<std::vector<double>> GetResultsSoFar() const = 0;
    virtual StatisticsMC* clone() const = 0;
    virtual ~StatisticsMC(){}
};

class StatisticsMean : public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual StatisticsMean* clone() const;
    //virtual ~StatisticMean(){}
private:
    double RunningSum;
    unsigned long PathsDone;
};

#endif // MCSTATISTICS_H_INCLUDED
