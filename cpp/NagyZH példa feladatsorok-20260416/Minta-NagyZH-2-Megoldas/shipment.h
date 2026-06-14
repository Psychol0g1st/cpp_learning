#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include <vector>
using namespace std;

class Shipment
{
    vector<string> ids;
    vector<int> quantities;
public:
    Shipment(const string& filePath);

    size_t getItemCount() const;
    const string& getId (size_t index) const;
    int getQuantity (size_t index) const;
};

#endif // SHIPMENT_H
