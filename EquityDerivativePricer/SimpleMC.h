#ifndef SIMPLEMC_H_INCLUDED
#define SIMPLEMC_H_INCLUDED
#include "Payoff2.h"

double SimpleMonteCarlo2(const Payoff& _payoff,
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long numOfPaths);

#endif // SIMPLEMC_H_INCLUDED
