---
title: SOS ZH Felkészítő - OOP és Dinamikus Memória
description: Az1. Kis ZH-hoz. Elméleti gyorstalpaló és a minta ZH lépésről lépésre történő megoldása.
---

Ebben az anyagban először gyorsan átvesszük a legszükségesebb elméletet, utána pedig lépésről lépésre megoldjuk a kiadott Minta ZH-t. 

> **A legfontosabb ZH szabályok:**
>  kapott alapkódokon (pl. `Product`, `Review`, `main.cpp`) nem szabad módosítani, hacsak a feladat kifejezetten nem kéri!
> igyelni kell a pontos kiíratásra (szóközök, sortörések), mert a javítórendszer gépiesen ellenőriz.
> inden lefoglalt memóriát kötelező felszabadítani a memóriaszivárgás elkerülése végett.
>  feladatok pontozásához a `megoldott_feladatok.h` fájlban lévő `#define` sorokat be kell kapcsolni (ki kell venni előlük a `//` komment jelet).

---

## 1. Rész: OOP Túlélő Gyorstalpaló (Az elmélet)

Ahhoz, hogy a feladatot meg tudd oldani, ezt a 4 alapfogalmat kell megértened.

### 1. Osztályok és Objektumok
Az **osztály (class)** egy tervrajz. Megmondja, hogy valami hogyan nézzen ki és mit tudjon csinálni. Az **objektum** pedig az a konkrét dolog, amit a memóriában a tervrajz alapján megépítünk.
A C++-ban az osztálynak vannak "privát" (csak belülről látható) adatai, és "publikus" (kívülről is hívható) függvényei (metódusai).

### 2. Öröklődés (Inheritance)
Amikor csinálunk egy új osztályt, gyakran nem akarjuk nulláról kezdeni. Az öröklődés ("Is-A" kapcsolat) segítségével egy új osztály (Gyerek) átveheti egy meglévő osztály (Ős) minden tudását. 
[cite_start]A feladatban a `RatedProduct` a `Product` osztályból származik. Szintaxisa:
```cpp
class RatedProduct : public Product { ... };
```

**A Nagy Trükk:** Amikor a Gyerek létrejön, *kötelező* megmondania, hogyan épüljön fel az Ős! Mivel a `Product`-nak nevet és árt kell adni, ezt a `RatedProduct` konstruktorában, egy ún. **inicializáló listán** kell átadnunk neki (egy kettőspont után).

### 3. Konstruktor, Destruktor és a Dinamikus Memória (Pointerek)

A feladat kiköti, hogy az értékeléseket (`Review`) egy dinamikus tömbben kell tárolnunk. Mivel előre nem tudjuk, hány értékelés lesz (ezt a felhasználó adja meg), a memóriát "röptében", a **Heap**-en kell lefoglalnunk.

* **A Mutató (Pointer):** Az osztályunkban csak egy mutatót (`Review* reviews`) tárolunk, ami majd a tömb legelső elemére fog mutatni a memóriában.
* **A Konstruktor:** Ez a függvény fut le, amikor az objektum megszületik. Itt foglalunk memóriát a `new` kulcsszóval: `reviews = new Review[darabszam];`.
* **A Destruktor (`~` jel):** Ez fut le automatikusan, amikor az objektum élete véget ér. Ha a konstruktorban `new[]` volt, a destruktorban **kötelező** a `delete[] reviews;` hívás, különben "memóriaszivárgás" történik (bent ragad a RAM-ban a tömb).



### 4. Statikus adattagok (Static)

A "sima" változókból minden objektumnak sajátja van (pl. minden terméknek saját ára van). A **statikus** (`static`) változóból viszont *csak egyetlen darab* létezik az egész memóriában, és az összes objektum ezen az egyen osztozik. A feladatban egy ilyen közös "elfogadható minimum szintet" kell beállítanunk. Ezt a fejlécben deklaráljuk, de a működését a `.cpp` fájlban, globálisan kell inicializálnunk!

---

## 2. Rész: A Minta ZH Lépésről Lépésre

Most alkalmazzuk az elméletet! Létre kell hoznunk két fájlt: `ratedproduct.h` és `ratedproduct.cpp`.

### PART 1: Származtatás és Memóriakezelés (2 pont)

A feladat: Hozzunk létre egy `RatedProduct` osztályt a `Product`-ból származtatva. A konstruktor várjon nevet, árat és az értékelések számát. Foglaljunk dinamikus tömböt, és figyeljünk a felszabadításra.

**Megoldás:**
Az osztályba kell egy `int reviewCount` (méret) és egy `Review* reviews` (mutató a dinamikus tömbre).
A konstruktor inicializáló listáján (`: Product(name, price)`) meghívjuk az őst, utána a `new` operátorral memóriát kérünk. A destruktorban `delete[]`-el töröljük.

### PART 2: Értékelés beállítása (1 pont)

A feladat: Egy `setReview` metódus, ami indexet és `Review`-t kap, majd beteszi a tömbbe.
**Megoldás:** Simán a tömb megfelelő indexére tesszük az átadott értéket: `reviews[index] = r;`. (Mivel a feladat kéri, hogy figyeljünk a referenciákra, az objektumot `const Review r` formában érdemes átadni, hogy ne másoljuk feleslegesen a memóriát).

### PART 3: A kiíratás felülírása (2 pont)

A feladat: A `print` metódus írja ki a terméket, majd soronként az értékeléseket.
**Megoldás:** Először meghívjuk az ős `print` függvényét (`Product::print();`), majd egy `for` ciklussal végigmegyünk a tömbön, és minden elemen meghívjuk a saját `print()`-jét.

### PART 4: Átlagolás (getRating) (2 pont)

A feladat: Vissza kell adni a kapott csillagok átlagát (`double`). A csillagok száma a `getStars()`-al kérdezhető le.
**Megoldás:** Egy ciklussal összeadjuk a csillagokat. Mivel az osztásnál pontos törtet szeretnénk kapni (nem egész osztást), az összegző változónak `double`-nek kell lennie!

### PART 5: Statikus adattag (1 pont)

A feladat: Egy statikus `double` adattag, kezdeti értéke `4.2`, és ehhez getter/setter metódusok.
**Megoldás:** A `static` kulcsszóval deklaráljuk az osztályban. A trükk az, hogy a kezdőértéket a `.cpp` fájlban, minden függvényen kívül kell megadni!

### PART 6: Elfogadhatóság vizsgálata (1 pont)

A feladat: Egy `isAcceptable` metódus, ami visszaadja, hogy az átlag (`getRating()`) eléri-e a statikus elfogadható szintet.
**Megoldás:** Egyetlen soros feltétel: `return getRating() >= acceptableLevel;`.

### PART 7: Névtér (1 pont)

A feladat: Az osztály legyen a `ToolsForRating` névtérben.
**Megoldás:** A `.h` és `.cpp` fájlokban az egész kódunkat körbeöleljük egy `namespace ToolsForRating { ... }` blokkal.

---

## 3. Rész: A Végleges Forráskód (Copy-Paste)

Ha a fentieket összerakjuk, ez lesz a két fájl, amit fel kell tölteni a vizsgán!

### 1. `ratedproduct.h` (A Tervrajz)

```cpp
#ifndef RATEDPRODUCT_H
#define RATEDPRODUCT_H

#include "product.h"
#include "review.h"

// PART 7: Névtérbe csomagolás
namespace ToolsForRating {

    // PART 1: Öröklődés a Product osztályból
    class RatedProduct : public Product {
    private:
        int reviewCount;
        Review* reviews; // Mutató a dinamikus tömbre a memóriában
        
        // PART 5: Statikus adattag (közös minden objektumnak)
        static double acceptableLevel;

    public:
        // PART 1: Konstruktor és Destruktor
        RatedProduct(const string& name, double price, int reviewCount);
        ~RatedProduct();

        // PART 2: Értékelés beállítása (referenciát használunk másolás helyett!)
        void setReview(int index, const Review r);

        // PART 3: Kiíratás "felülírása"
        void print() const;

        // PART 4: Átlag számítása
        double getRating() const;

        // PART 5: Statikus getter/setter
        static double getAcceptableLevel();
        static void setAcceptableLevel(double level);

        // PART 6: Elfogadhatóság vizsgálata
        bool isAcceptable() const;
    };

}

#endif // RATEDPRODUCT_H

```

### 2. `ratedproduct.cpp` (A Megvalósítás)

```cpp
#include "ratedproduct.h"
#include <iostream>

using namespace std;

// PART 7: A megvalósításnak is a névtérben kell lennie!
namespace ToolsForRating {

    // PART 5: Statikus adattag inicializálása (mindig a függvényeken kívül!)
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
    void RatedProduct::setReview(int index, const r) {
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

    // PART 4: getRating
    double RatedProduct::getRating() const {
        if (reviewCount == 0) return 0.0; // Nullával osztás elleni védelem
        
        double sum = 0.0; // Double-nek kell lennie, hogy az osztás törtet adjon!
        for (int i = 0; i < reviewCount; i++) {
            sum += reviews[i].getStars(); // Csillagok összeadása
        }
        
        return sum / reviewCount; 
    }

    // PART 5: Statikus metódusok
    double RatedProduct::getAcceptableLevel() {
        return acceptableLevel;
    }

    void RatedProduct::setAcceptableLevel(double level) {
        acceptableLevel = level;
    }

    // PART 6: isAcceptable
    bool RatedProduct::isAcceptable() const {
        // Ha az átlag nagyobb vagy egyenlő a szinttel, true-t ad vissza
        return getRating() >= acceptableLevel;
    }

}

```

> **Az Utolsó Lépés:** Beadás előtt nyisd meg a `megoldott_feladatok.h` fájlt, és **töröld ki a `//` jeleket** a `#define PART...` sorok elől! Így fogja a gép lefuttatni a te új kódodat.

Ha ezt a logikát megérted, garantált a pontszerzés. Sok sikert a Kis ZH-hoz, szurkolok! Ha bármi nem világos az elméletben, kérdezz nyugodtan!
