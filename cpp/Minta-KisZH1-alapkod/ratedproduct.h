#ifndef RATEDPRODUCT_H
#define RATEDPRODUCT_H

#include "product.h"
#include "review.h"

namespace ToolsForRating {
    class RatedProduct : public Product {
    private:
        int reviewCount;
        Review* reviews; // Mutató a dinamikus tömbre a memóriában

        static double acceptableLevel;

    public:
        // PART 1: Konstruktor és Destruktor
        RatedProduct(const string& name, double price, int reviewCount);
        ~RatedProduct();

        // PART 2: Értékelés beállítása (referenciát használunk másolás helyett!)
        void setReview(int index, const Review r);

        // PART 3: Kiíratás "felülírása"
        void print() const;

        double getRating() const;

        static void setAcceptableLevel(double value); // RatedProduct::setAcceptableLevel()
        static double getAcceptableLevel(); // RatedProduct::getAcceptableLevel()

        bool isAcceptable() const;
    };
}


#endif // RATEDPRODUCT_H
