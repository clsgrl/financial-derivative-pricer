#include "Random1.h"
#include <cstdlib>
#include <cmath>
#include <random>

using namespace std;

double GetOneGaussianBySummation()
{
    double result = 0;
    for(unsigned long j=0; j < 12; j++){
        result += rand()/static_cast<double>(RAND_MAX);
    }

    result -= 6.0;
    return result;
}

double GetOneGaussianByBoxMuller()
{
    double result;
    double x;
    double y;

    double sizeSquared;
    do{
        x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
        sizeSquared = x*x + y*y;
    }while(sizeSquared >= 1.0);

    result = x * sqrt(-2*log(sizeSquared)/sizeSquared);

    return result;

}

double GetOneNormalDistribution()
{
    return 0.0;
}

double heaviside(const double& val)
{
    if(val >= 0) {
        return 1.0;
    }else{
        return 0.0;
    }
}

