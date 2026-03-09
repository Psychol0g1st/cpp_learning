#include "ratedproduct.h"
#include <iostream>
using namespace std;

namespace ToolsForRating {

    //Part 5
    double RatedProduct::acceptableLevel = 4.2;

    // PART 1: Konstruktor
    // A : Product(name, price) hívja meg az ős konstruktorát! Ezt nem lehet kihagyni.
    RatedProduct::RatedProduct(const string& name, double price, int count)
        : Product(name, price), reviewCount(count)
    {
        // Dinamikus memóriafoglalás (Heap) a tömbnek a new kulcsszóval
        reviews = new Review[reviewCount];
    }

    // PART 1: Destruktor
    RatedProduct::~RatedProduct() {
        // Mivel a konstruktorban new[] volt, itt delete[] kell a memóriaszivárgás ellen!
        delete[] reviews;
    }

    // PART 2: setReview
    void RatedProduct::setReview(int index, const Review r) {
        // Jó mérnöki gyakorlat megnézni, hogy jó-e az index
        if (index >= 0 && index < reviewCount) {
            reviews[index] = r;
        }
    }

    // PART 3: print
    void RatedProduct::print() const {
        // 1. Az ősosztály kiíratásának meghívása
        Product::print();

        // 2. A tömb elemeinek kiíratása
        for (int i = 0; i < reviewCount; i++) {
            reviews[i].print();
        }
    }
    //PART 4
    double RatedProduct::getRating() const {
        if(reviewCount == 0)
            return 0.0;

        double sum = 0.0;
        for (unsigned i = 0; i < reviewCount; i++)
        {
            sum += reviews[i].getStars();
        }
        return sum / reviewCount;
    }

    void RatedProduct::setAcceptableLevel(double value){
        acceptableLevel = value;
    }
    double RatedProduct::getAcceptableLevel(){
        return acceptableLevel;
    }

    bool RatedProduct::isAcceptable() const{
        return getRating() >= acceptableLevel;
    }
}
