#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo2(const Payoff& _payoff,
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long numOfPaths)
{
    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(r*expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for(unsigned int i=0; i<numOfPaths; ++i)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);
        double thisPayoff = _payoff(thisSpot);
        runningSum += thisPayoff;
    }
    double mean = runningSum / numOfPaths;
    mean *= exp(-r*expiry);
    return mean;
}
