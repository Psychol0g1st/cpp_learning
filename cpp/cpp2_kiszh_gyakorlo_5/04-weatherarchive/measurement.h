#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
using namespace std;

class Measurement
{
    double temperature;
    string label;
public:
    Measurement();
    Measurement(double temperature,
                const string& label);

    double getTemperature() const;
    const string& getLabel() const;

    void print() const;
};

#endif // MEASUREMENT_H
