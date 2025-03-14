#include "SimpleMC7.h"
#include "Random1.h"
#include <cmath>

using namespace std;

void SimpleMonteCarlo5(const VanillaOption& TheOption,
                       double Spot,
                       const Parameters& Vol,
                       const Parameters& r,
                       unsigned long NumberOfPaths,
                       StatisticsMC& gathered)
{
    double Expiry = TheOption.GetExpiry();
    double variance = Vol.IntegralSquare(0, Expiry);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r.Integral(0,Expiry)+itoCorrection);
    double thisSpot;
    double discounting = exp(-r.Integral(0,Expiry));

    for(unsigned long i=0; i< NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance*thisGaussian);
        double thisPayoff = TheOption.OptionPayoff(thisSpot);
        gathered.DumpOneResult(thisPayoff*discounting);
    }
    return;
}
