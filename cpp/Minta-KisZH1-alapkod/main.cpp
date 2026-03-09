#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "ratedproduct.h"
#include "product.h"
#include "review.h"
#endif

struct TesterGuard
{
	string partname;
	TesterGuard (const string& partname);
	~TesterGuard();
};

namespace ToolsForRating {}
using namespace ToolsForRating;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
	{
        TesterGuard tguard("PART1");
        RatedProduct rp("vasalo", 42.99, 7);
        if (!is_base_of<Product,RatedProduct>::value)
            cout << "Hiba: A Product nem a RatedProduct ose.";
        else
            cout << "Latszolag OK." << endl;
	}//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        RatedProduct rp("porszivo", 51.99, 3);
        rp.setReview(0, Review(5,"Works perfectly."));
        rp.setReview(1, Review(1,"Broken after 1 use."));
        rp.setReview(2, Review(2,"Hard to handle, overpriced"));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        RatedProduct rp1("porszivo", 51.99, 5);
        rp1.setReview(0, Review(5,"Works perfectly."));
        rp1.setReview(1, Review(1,"Broken after 1 use."));
        rp1.setReview(2, Review(2,"Hard to handle, overpriced."));
        rp1.setReview(3, Review(5,"OK"));
        rp1.setReview(4, Review(4,"Too much noise."));
        RatedProduct rp2("mikro", 109.49, 3);
        rp2.setReview(0, Review(3,"Labels do not match."));
        rp2.setReview(1, Review(5,"Nice."));
        rp2.setReview(2, Review(2,"Barely works."));
        rp1.print();
        cout << endl;
        rp2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        RatedProduct rp1("porszivo", 51.99, 5);
        rp1.setReview(0, Review(5,"Works perfectly."));
        rp1.setReview(1, Review(1,"Broken after 1 use."));
        rp1.setReview(2, Review(2,"Hard to handle, overpriced."));
        rp1.setReview(3, Review(5,"OK"));
        rp1.setReview(4, Review(4,"Too much noise."));
        RatedProduct rp2("mikro", 109.49, 3);
        rp2.setReview(0, Review(3,"Labels do not match."));
        rp2.setReview(1, Review(5,"Nice."));
        rp2.setReview(2, Review(2,"Barely works."));
        cout << rp1.getRating() << endl;
        cout << rp2.getRating() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << RatedProduct::getAcceptableLevel() << endl;
        RatedProduct::setAcceptableLevel(3.7);
        cout << RatedProduct::getAcceptableLevel() << endl;
        RatedProduct::setAcceptableLevel(4.2);
        cout << RatedProduct::getAcceptableLevel() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        RatedProduct rp1("product",100.00, 2); // avg: 4.5
        rp1.setReview(0, Review(4,"..."));
        rp1.setReview(1, Review(5,"..."));
        RatedProduct rp2("product",100.00, 3); // avg: 4
        rp2.setReview(0, Review(3,"..."));
        rp2.setReview(1, Review(5,"..."));
        rp2.setReview(2, Review(4,"..."));
        RatedProduct rp3("product",100.00, 6); // avg: 3.83
        rp3.setReview(0, Review(2,"..."));
        rp3.setReview(1, Review(4,"..."));
        rp3.setReview(2, Review(4,"..."));
        rp3.setReview(3, Review(4,"..."));
        rp3.setReview(4, Review(4,"..."));
        rp3.setReview(5, Review(5,"..."));
        for (double level : {4.2, 3.9, 5.0, 3.5})
        {
            RatedProduct::setAcceptableLevel(level);
            cout << "elfogadhato: " << level << " ->" << flush;
            for (auto rp_addr : {&rp1, &rp2, &rp3})
            {
                const RatedProduct& rp = *rp_addr;
                bool acceptable = rp.isAcceptable();
                cout << " " << acceptable << flush;
            }
            cout << endl;
        }
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<RatedProduct,ToolsForRating::RatedProduct>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "RatedProduct nincs a nevterben!" << endl;
    }//
#endif

	cout << "main() vege!" << endl;
	return 0;
}

TesterGuard::TesterGuard(const string &p):
	partname(p)
{
	cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
	cout << endl << "----END OF " << partname << "----" << endl << endl;
}
