#include "SimpleMC7.h"
#include <iostream>
#include "Vanilla3.h"
#include "MCStatistics.h"

using namespace std;

int main2332()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayoffCall thePayoff(Strike);
    VanillaOption theOption(thePayoff, Expiry);
    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;

    SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer);

    vector<vector<double>> results = gatherer.GetResultsSoFar();

    cout << "\nFor the call price the results are\n";

    for(unsigned long i = 0; i < results.size(); i++)
    {
        for(unsigned long k = 0; k < results[i].size(); k++)
        {
            cout << results[i][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
