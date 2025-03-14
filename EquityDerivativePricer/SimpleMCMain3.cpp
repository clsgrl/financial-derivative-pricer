#include "SimpleMC.h"
//#include "Payoff2.h"
#include <iostream>

using namespace std;

int main3()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    PayoffCall callPayoff(Strike);
    PayoffPut putPayoff(Strike);

    double resultCall = SimpleMonteCarlo2(callPayoff,
                                            Expiry,
                                            Spot,
                                            Vol,
                                            r,
                                            NumberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayoff,
                                        Expiry,
                                        Spot,
                                        Vol,
                                        r,
                                        NumberOfPaths);
    cout <<"the prices are " << resultCall <<
        " for the call and " << resultPut <<
    " for the put\n";

    return 0;
}
