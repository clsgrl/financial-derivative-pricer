#ifndef SIMPLEMC3_H_INCLUDED
#define SIMPLEMC3_H_INCLUDED
#include "Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption& option,
                        double spot,
                        double vol,
                        double r,
                        unsigned long numOfPaths);


#endif // SIMPLEMC3_H_INCLUDED
