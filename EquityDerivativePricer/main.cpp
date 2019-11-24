#include "Random1.h"
#include <iostream>
#include <cmath>

using namespace std;

double SimpleMonteCarlo1(double expiry, double strike, double spot, double vol, double r, unsigned long numOfPaths)
{
    double variance = vol * vol * expiry;
    double rootVariance = sqrt(variance);
    double itoCorrelation = -0.5 * variance;

    double movedSpot = spot * exp(r * expiry + itoCorrelation);
    double thisSpot;
    double runningSum = 0;

    for(unsigned long i=0; i<numOfPaths; i++){
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thisSpot - strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / numOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}


int main2()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long nOfPaths;

    cout << "\nEnter expiry\n";
    cin >> expiry;
    cout << "\nEnter strike\n";
    cin >> strike;
    cout << "\nEnter spot\n";
    cin >> spot;
    cout << "\nEnter vol\n";
    cin >> vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> nOfPaths;

    double result = SimpleMonteCarlo1(expiry, strike, spot, vol, r, nOfPaths);

    cout << "the price is " << result << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
