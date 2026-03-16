#include "measurement.h"

#include <iostream>
using namespace std;

Measurement::Measurement():
    temperature(0.0),
    label("<NINCS MERES>")
{
}

Measurement::Measurement(double temperature,
                         const string& label):
    temperature(temperature),
    label(label)
{
}

double Measurement::getTemperature() const
{
    return temperature;
}

const string& Measurement::getLabel() const
{
    return label;
}

void Measurement::print() const
{
    cout << label << " -> " << temperature << " C" << endl;
}
