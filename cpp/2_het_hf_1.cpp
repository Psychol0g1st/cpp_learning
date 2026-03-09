#include <iostream>

using namespace std;

class SajatTomb
{						//ezek itt privat elemek, az osztalyon kivulrol nem erheto el
	unsigned meret;		//tomb elemeinek szamat tarolja el - hogy mekkora memoriahelyet foglaljon le
	double* ertekek;	//pointer, ez mutat a lefoglalt memoria elejere
public:
	SajatTomb(unsigned m) :	//konstruktor - akkor fut le, amikor egy objektumot letrehozunk
		meret(m),			//inicializalo lista: beallitja a meretet es a "new"-el lefoglak egy "m" darab "double" szamnak megfelelo helyet
		ertekek(new double[m]) //"m" meretu double tipusu memoriat foglal le
	{
	}
	~SajatTomb() {			//Destruktor - amint az objektum megszunik, felszabaditja a lefoglat memoriat a "delete[]"-el
		delete[] ertekek;
	}
	void beallit(unsigned index, double ertek) {//erteket ad a tomb egy adott indexu elemenek
		ertekek[index] = ertek;
	}
	void kiir() const {			//kiirja a tomb osszes elemet, a "const" jelzi, hogy nem modositja az  objektum allapotat
		for (unsigned i = 0; i < meret; i++)	//a kiiras 0-tol a "meret"-ig
			cout << ertekek[i] << " ";
		cout << endl;
	}
	//




	//

};

int main()
{
	unsigned m;							//uj valtozo, ami "unsigned"- tipusu: 0 vagy pozitiv (elojel nelkuli)
	cin >> m;							//bekeri az m-be
	SajatTomb t1(m);					//
	for (unsigned i = 0; i < m; i++) {
		double e;
		cin >> e;
		t1.beallit(i, e);
	}
    
    // SajatTomb t2(m);
    // t2 = t1;
    // t2.beallit(0, 5);
    
    // t1.kiir();
	// t2.kiir();
    
    SajatTomb t2(t1);
    t2.beallit(0, 5);
	t1.kiir();
    t2.kiir();
	


    // SajatTomb t2(t1);
    // t2.kiir();
	// t1.kiir();
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

#define DARABOK 6	//nevesitett konstans

double atlag(int tomb[], int meret) {
	//atlag == osszeadod majd eloszotd oket
	int osszeg = 0;
	for (int i = 0; i < meret; i++)
	{
		osszeg += tomb[i];
	}
	return double(osszeg) / meret;


}


void szamokAtlag() {
	int szamok[DARABOK];
	for (int i = 0; i < DARABOK; i++)
	{
		cout << i + 1 << ". szamot mondd meg: ";
		cin >> szamok[i];
	}

	cout << "A " << DARABOK << " db szam atlaga : " << atlag(szamok, DARABOK) << endl;
}



int main() {

	int jegyek[5] = { 5, 4, 3, 5, 2 };
	cout << "A harmadik diak jegye:  " << jegyek[2] << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i << ". indexu elem: " << jegyek[i] << endl;
	}

	string vnev = "Kovacs";	//6 hosszu
	string knev = "Bela";	//4 hosszu

	string teljesNev = vnev + " " + knev;	//szokoz 1 hosszu

	cout << "Udvozollek, " << teljesNev << "!" << endl;

	cout << "A neved " << teljesNev.length() << " karakterekbol all." << endl;
	cout << "Jegyek atlaga: " << atlag(jegyek, 5) << endl;
	cout << 5 / double(3) << endl;
	cout << 5 / 3.0 << endl;

	//szamokAtlag();
	cout << "Mi a teljes neved?" << endl;
	cin >> teljesNev;
	cout << teljesNev;
	cin.ignore();
	teljesNev.clear();
	getline(cin, teljesNev);
	cout << teljesNev;


	return 0;
}
