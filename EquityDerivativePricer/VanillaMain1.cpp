#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include <iostream>
#include "Vanilla1.h"

using namespace std;

int main()
{
    double Expiry;
    double Low,Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter low barrier\n";
    cin >> Low;
    cout << "\nEnter up barrier\n";
    cin >> Up;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayoffDoubleDigital thePayoff(Low, Up);
    VanillaOption theOption(thePayoff, Expiry);

    double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

    cout << "\nthe price is " << result << "\n";

    return 0;

}
