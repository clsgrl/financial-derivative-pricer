#include "SimpleMC2.h"
#include <iostream>

using namespace std;

int main4()
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
    unsigned long optionType;
    cout << "\nenter 0 for call, otherwise put ";
    cin >> optionType;

    Payoff* thePayoffPtr;

    if(optionType == 0)
        thePayoffPtr = new PayoffCall(Strike);
    else
        thePayoffPtr = new PayoffPut(Strike);

    double result = SimpleMonteCarlo2(*thePayoffPtr, Expiry,Spot, Vol, r, NumberOfPaths);

    cout <<"\nthe price is " << result << "\n";

    delete thePayoffPtr;

    return 0;
}
