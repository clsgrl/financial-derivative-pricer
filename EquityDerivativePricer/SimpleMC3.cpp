#include "SimpleMC3.h"
#include "Random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo3(const VanillaOption& option,
                        double spot,
                        double vol,
                        double r,
                        unsigned long numOfPaths)
{
    double Expiry = option.GetExpiry();
    double variance = vol * vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;

    double movedSpot = spot*exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum=0;

    for(unsigned long i=0; i< numOfPaths; ++i)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = option.OptionPayoff(thisSpot);
        runningSum += thisPayoff;

    }
    double mean = runningSum / numOfPaths;
    mean *= exp(-r*Expiry);

    return mean;

}
