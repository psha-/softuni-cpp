#include <iostream>

using namespace std;

float solveProblem(float v1, float v2, float randezvousTime)
{
    float d1 = v1 * randezvousTime;
    float d2 = v2 * randezvousTime;
    return d1 + d2;
}

int main()
{
    float fordV;
    float golfV;
    float randezvousTime;
    float distance;

    cout << "A Ford Mustang is travelling from city A to city B with speed (km/h): ";
    cin >> fordV;

    cout << "A VW Golf 2 is travelling from city B to city A with speed (km/h): ";
    cin >> golfV;

    cout << "The two vehicles meet at point C after (hours): ";
    cin >> randezvousTime;

    cout << "What is the distance between A and B (km)? ";
    cin >> distance;

    float correctDistance = solveProblem(fordV, golfV, randezvousTime);

    if( distance == correctDistance ) {
        cout << "Correct!" << endl;
    }
    else {
        cout << "Wrong! The distance is: " << correctDistance << " km." << endl;
    }

    return 0;
}

