#include "shipment.h"

#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

Shipment::Shipment(const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);

    json root = json::parse(in);
    json items = root["ShipmentItems"];

    for (size_t i=0;i<items.size();i++)
    {
        json& item = items[i];
        string id = item["ProductId"];
        int quantity = item["Quantity"];
        ids.push_back(id);
        quantities.push_back(quantity);
    }
}

size_t Shipment::getItemCount() const
{
    return ids.size(); // ==quantities.size()
}

const string &Shipment::getId(size_t index) const
{
    return ids[index];
}

int Shipment::getQuantity(size_t index) const
{
    return quantities[index];
}
