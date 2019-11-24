#include "SimpleMC2.h"
#include <iostream>

using namespace std;

int main233()
{
    double expiry, strike, spot, vol, r;
    unsigned long numberOfPaths;

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
    cin >> numberOfPaths;

    PayoffCall callPayoff(strike);
    PayoffPut putPayoff(strike);

    double resultCall = SimpleMonteCarlo2(callPayoff, expiry, spot, vol, r, numberOfPaths);
    double resultPut = SimpleMonteCarlo2(putPayoff, expiry, spot, vol, r, numberOfPaths);

    cout << "The prices are: call= " << resultCall << " / put= " << resultPut << "\n";

}
