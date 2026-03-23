#include "checkpoint.h"

#include <iostream>
using namespace std;

Checkpoint::Checkpoint():
    distanceKm(0.0),
    durationMin(0)
{
}

Checkpoint::Checkpoint(double distanceKm,
                       int durationMin):
    distanceKm(distanceKm),
    durationMin(durationMin)
{
}

double Checkpoint::getDistanceKm() const
{
    return distanceKm;
}

int Checkpoint::getDurationMin() const
{
    return durationMin;
}

void Checkpoint::print() const
{
    cout << distanceKm << " km, " << durationMin << " perc" << endl;
}
