#include <iostream>
#include <vector>
using namespace std;

// sajat include-ok (az osztalyok atnevezhetok)
#include "warehouse.h"
#include "bproduct.h"
#include "btoy.h"
#include "bclothes.h"
#include "bchair.h"
using BabyProduct = BProduct;
using Toy = BToy;
using Clothes = BClothes;
using Chair = BChair;

template <class T>
void printVector (const vector<T*>& v)
{
    for (size_t i=0;i<v.size();i++)
    {
        const T& item = *v[i];
        cout << item << endl; // operator<<
    }
}

int main()
{
    cout << "main() eleje!" << endl << endl;

    Warehouse wh;

    wh.loadProducts("toy","stock-toys.json");
    wh.loadProducts("clothes","stock-clothes.json");
    wh.loadProducts("chair","stock-chairs.json");

    vector<BabyProduct*> products = wh.getProducts();
    cout << "Teljes termeklista:" << endl;
    printVector(products);
    cout << endl;

    vector<BabyProduct*> toys = wh.getProducts("toy");
    cout << "Csak jatekok (\"toy\"):" << endl;
    printVector(toys);
    cout << endl;
    vector<BabyProduct*> clothes = wh.getProducts("clothes");
    cout << "Csak ruhak (\"clothes\"):" << endl;
    printVector(clothes);
    cout << endl;
    vector<BabyProduct*> chairs = wh.getProducts("chair");
    cout << "Csak etetoszekek (\"chair\"):" << endl;
    printVector(chairs);
    cout << endl;

    vector<Toy*> toys1 = wh.getSpecificProducts<Toy>(2000,10000);
    vector<Toy*> toys2 = wh.getSpecificProducts<Toy>(5500,20000);
    cout << "Jatekok, 2000 Ft-tol 10000 Ft-ig:" << endl;
    printVector(toys1);
    cout << "Jatekok, 5500 Ft-tol 20000 Ft-ig:" << endl;
    printVector(toys2);
    cout << endl;
    vector<Clothes*> clothes1 = wh.getSpecificProducts<Clothes>(0,10000);
    vector<Clothes*> clothes2 = wh.getSpecificProducts<Clothes>(5000,15000);
    cout << "Ruhak, 0 Ft-tol 10000 Ft-ig:" << endl;
    printVector(clothes1);
    cout << "Ruhak, 5000 Ft-tol 15000 Ft-ig:" << endl;
    printVector(clothes2);
    cout << endl;
    vector<Chair*> chairs1 = wh.getSpecificProducts<Chair>(0,12000);
    vector<Chair*> chairs2 = wh.getSpecificProducts<Chair>(30000,150000);
    cout << "Etetoszekek, 0 Ft-tol 12000 Ft-ig:" << endl;
    printVector(chairs1);
    cout << "Etetoszekek, 30000 Ft-tol 150000 Ft-ig:" << endl;
    printVector(chairs2);
    cout << endl;

    Shipment shipment1("shipment-1.json");
    Shipment shipment2("shipment-2.json");
    wh.deliverShipment(shipment1);
    wh.deliverShipment(shipment2);
    cout << "Teljes termeklista (leszallitas utan):" << endl;
    printVector(wh.getProducts());
    cout << endl;

    int sum=120000;
    bool sikeres;
    sikeres = wh.makeOrder("9987",1,sum);
    cout << "Vasarlas 1 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("7409",5,sum);
    cout << "Vasarlas 2 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("8002",2,sum);
    cout << "Vasarlas 3 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("4624",1,sum);
    cout << "Vasarlas 4 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("9987",4,sum);
    cout << "Vasarlas 5 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("9987",3,sum);
    cout << "Vasarlas 6 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("8999",2,sum);
    cout << "Vasarlas 7 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;
    sikeres = wh.makeOrder("8999",1,sum);
    cout << "Vasarlas 8 " << (sikeres ? "sikeres" : "SIKERTELEN");
    cout << ", megmaradt penz: " << sum << endl;

    cout << endl << "Vegso termeklista (eladasok utan):" << endl;
    printVector(wh.getProducts());
    cout << endl;

    wh.saveProducts("toy","output-toys.json");
    wh.saveProducts("clothes","output-clothes.json");
    wh.saveProducts("chair","output-chairs.json");

    cout << "main() vege!" << endl;
    return 0;
}
