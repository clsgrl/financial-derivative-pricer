#include "SimpleMC.h"
#include <iostream>

using namespace std;

int main1()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long numOfPaths;

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
    cout << "\nNumber of Paths\n";
    cin >> numOfPaths;

    //PayoffCall callPayoff(strike);
    //PayoffPut putPayoff(strike);

    double resultCall = 0.0; //SimpleMonteCarlo2(callPayoff, expiry, spot, vol, r, numOfPaths);

    double resultPut = 0.0;//SimpleMonteCarlo2(putPayoff, expiry, spot, vol, r, numOfPaths);

    cout << "the prices are: call=" << resultCall << " put="<<resultPut << endl;

    return 0;
}
