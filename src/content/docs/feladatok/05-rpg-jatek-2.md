---
title: 05. Mini-Projekt Továbbfejlesztés - Absztrakt Osztályok és Polimorfizmus
description: Hogyan tegyük egyedivé a szörnyeket? Ismerkedés az absztrakt osztályokkal, a virtuális függvényekkel és az öröklődés igazi erejével.
---

Szia! Szuperül összeraktuk a múltkor az Arénát, és működik is a harc. De őszintén: nem egy kicsit unalmas, hogy a Goblin és a Sárkány a motorháztető alatt *pontosan ugyanúgy* harcol, csak a számaik mások? 

Mi lenne, ha a Goblin gyors lenne és kétszer szúrna egy körben, a Sárkány pedig néha tüzet okádna? 

Ahhoz, hogy minden szörnyünknek egyedi viselkedése lehessen, de továbbra is be tudjuk őket tenni ugyanabba az `arena` tömbbe, az Objektumorientált Programozás legszebb eszközéhez kell nyúlnunk: az **absztrakt osztályokhoz** és a **polimorfizmushoz** (többalakúság). Refaktoráljunk!

---

### 1. A probléma és az elmélet

Jelenleg van egy `Szorny` osztályunk. De gondolj bele: a valóságban "Szörny" nevű lénnyel nem találkozol. A "Szörny" csak egy gyűjtőfogalom (egy *absztrakció*). Te a valóságban egy *Goblinnal* vagy egy *Sárkánnyal* találkozol.

A C++-ban meg tudjuk mondani a gépnek: *"Figyelj, a `Szorny` osztály csak egy tervrajz a közös dolgoknak (HP, név), de sosem akarok közvetlenül egy sima Szörnyet létrehozni. Csak a belőle származó (öröklődő) specifikus lényeket engedd létezni!"* Ezt hívjuk **Absztrakt Osztálynak**.

**Hogyan csináljuk?**
Készítünk egy függvényt, amiről megmondjuk, hogy *kötelező* megírni minden leszármazottnak, de az ősosztályban még nincs kidolgozva. Ezt a `= 0` hozzáadásával érjük el, aminek a neve: **tisztán virtuális függvény (pure virtual function)**.

---

### 2. A kód refaktorálása: Az Absztrakt `Szorny` Osztály

Alakítsuk át az eddigi `Szorny` osztályunkat! Két fontos változás lesz:
1.  A `private` szót átírjuk `protected`-re. Emlékszel? Így a belőle származó specifikus szörnyek kódjai is látni fogják a belső HP és sebzés adatokat.
2.  Adunk neki egy `virtual void tamad() = 0;` metódust.

```cpp
class Hos; // Ezt oda kell írnunk a fájl tetejére, hogy a Szörny tudja, létezik majd egy Hos osztály.

class Szorny {
protected: // A private helyett protected: a gyerek osztályok is hozzáférhetnek!
    string nev;
    int hp;
    int alapSebzes;

public:
    Szorny(string nev, int hp, int sebzes) {
        this->nev = nev;
        this->hp = hp;
        this->alapSebzes = sebzes;
    }

    // Virtuális Destruktor! (Nagyon fontos, ha OOP-t és pointereket használsz, 
    // különben a 'delete' nem törli ki rendesen a memóriából a leszármazottakat)
    virtual ~Szorny() {} 

    string getNev() { return nev; }
    void sebzestKap(int ertek) {
        hp -= ertek;
        if (hp < 0) hp = 0;
    }
    bool isHalott() { return hp <= 0; }
    void statusz() { cout << "[" << nev << " HP: " << hp << "] "; }

    // TISZTÁN VIRTUÁLIS FÜGGVÉNY! 
    // Ettől a sortól válik a Szorny osztály absztrakttá. 
    virtual void tamad(Hos* celpont) = 0; 
};
```

---

### 3. Az igazi izgalom: A Leszármazott Szörnyek

Mivel a `Szorny` absztrakt lett, az `arena[0] = new Szorny("Goblin",...);` parancs most már **hibát dobna** a fordítónál. Nem hozhatsz létre "csak úgy" egy szörnyet.

Helyette létrehozzuk a specifikus osztályokat (Goblin, Sárkány), amik örökölnek a Szörnyből, és *kötelezően* megvalósítják a saját `tamad` logikájukat az `override` kulcsszóval.

```cpp
// A Hős osztálynak is lennie kell már itt egy sebzestKap() metódusának!

class Goblin : public Szorny {
public:
    // A Goblin konstruktora rögtön beállítja a saját értékeit az ősnek
    Goblin() : Szorny("Trukkos Goblin", 40, 5) {}

    // Kötelességünk megírni a tamad() metódust!
    void tamad(Hos* celpont) override {
        cout << "<--- A " << nev << " gyorsan, ketszer is megszúr a tőrrel!" << endl;
        // Kétszer sebez
        celpont->sebzestKap(alapSebzes);
        celpont->sebzestKap(alapSebzes);
        cout << "Dupla sebzes: " << (alapSebzes * 2) << " pont!" << endl;
    }
};

class Sarkany : public Szorny {
public:
    Sarkany() : Szorny("Osi Sarkany", 150, 20) {}

    void tamad(Hos* celpont) override {
        cout << "<--- Az " << nev << " tuzet okad ramad!" << endl;
        celpont->sebzestKap(alapSebzes + 10); // A Sárkány bónusz sebzést ad
        cout << "Pusztito sebzes: " << (alapSebzes + 10) << " pont!" << endl;
    }
};
```

---

### 4. A `main` függvény és a Polimorfizmus varázslata

Most jön a legszebb rész. A `main` függvényünk szinte **alig változik**! Az `arena` tömbünk továbbra is `Szorny*` mutatókat vár. Ez azért fantasztikus, mert a C++-ban *egy ősosztály mutatójával rámutathatsz a leszármazottaira is*. Ezt hívják **Polimorfizmusnak**!

```cpp
int main() {
    Hos jatekos("Artur Kiraly", 100, 25);

    // Az aréna egy Ősosztály típusú pointer-tömb!
    Szorny* arena[2]; 
    
    // De specifikus leszármazottakat teszünk bele:
    arena[0] = new Goblin();
    arena[1] = new Sarkany();

    for (int i = 0; i < 2; i++) {
        Szorny* aktualisSzorny = arena[i];

        cout << "\nUj ellenfel lep az arenaba: " << aktualisSzorny->getNev() << "!" << endl;

        while (!jatekos.isHalott() && !aktualisSzorny->isHalott()) {
            jatekos.statusz();
            aktualisSzorny->statusz();
            cout << endl;

            jatekos.tamad(aktualisSzorny);

            if (!aktualisSzorny->isHalott()) {
                // ITT A VARÁZSLAT:
                // Bár az aktualisSzorny változó típusa csak "Szorny*", a gép 
                // futási időben kitalálja, hogy épp egy Goblinal vagy Sárkánnyal
                // van-e dolga, és a megfelelő, egyedi támadást hívja meg!
                aktualisSzorny->tamad(&jatekos); 
            }
        }

        if (jatekos.isHalott()) break;
    }

    // A takarítás ugyanaz marad
    for (int i = 0; i < 2; i++) {
        delete arena[i];
    }

    return 0;
}
