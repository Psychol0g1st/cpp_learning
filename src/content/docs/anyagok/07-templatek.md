---
title: C++ Templétek (Sablonok) Alapjai
description: Bevezetés a C++ templétek világába. Generikus programozás, függvény és osztály sablonok elmélete, példái és gyakorló feladatai.
---

A C++ egyik legerősebb funkciója a **generikus programozás**, amelynek alapját a templétek (sablonok) adják. Ebben a leckében megvizsgáljuk, hogyan írhatunk olyan kódot, ami bármilyen adattípussal képes működni, anélkül, hogy százszor le kellene írnunk ugyanazt a logikát.

---

## 1. Mi az a Templét és miért van rá szükség?

Képzeld el, hogy írnod kell egy függvényt, ami visszaadja két szám közül a nagyobbat.

```cpp
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

Szuper, működik egész számokra! De mi van, ha a felhasználó tört számokat (double) akar összehasonlítani? Vagy karaktereket? Esetleg saját `Ember` objektumokat a koruk alapján?
Hagyományos esetben minden típusra külön meg kellene írnod a függvényt (**túlterhelés - overloading**):

```cpp
double max(double a, double b) { return (a > b) ? a : b; }
char max(char a, char b) { return (a > b) ? a : b; }
// ... és így tovább a végtelenségig.
```

Ez rengeteg felesleges gépelés, ráadásul sérti a **DRY (Don't Repeat Yourself)** elvet. Ha találsz egy hibát a logikában, mind a tíz függvényben ki kell javítanod.

**A Megoldás: A Templét (Sablon)**
A templét egy "tervrajz" a fordítóprogram (compiler) számára. Megmondjuk neki a logikát egy "Joker" típussal (ezt általában `T`-nek hívjuk), a gép pedig fordítási időben legenerálja helyettünk a megfelelő függvényeket azokra a típusokra, amiket a kódunkban ténylegesen használunk.

---

## 2. Függvény Templétek

Nézzük meg, hogyan néz ki a fenti probléma sablonként megírva!

```cpp
#include <iostream>

// Itt jelezzük a fordítónak, hogy egy sablon következik.
// A 'T' lesz az ismeretlen típusunk (Joker).
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // A gép látja, hogy int-eket adunk át, ezért 
    // a háttérben legenerál egy getMax(int, int) függvényt.
    std::cout << getMax(5, 10) << std::endl; 

    // Itt legenerál egy getMax(double, double) függvényt.
    std::cout << getMax(3.14, 2.71) << std::endl; 

    // Kifejezetten meg is mondhatjuk neki a típust a < > jelek között:
    std::cout << getMax<char>('a', 'z') << std::endl;

    return 0;
}
```

:::tip[A `typename` vs `class` kulcsszó]
Gyakran találkozhatsz a `template <class T>` kiírással is a `template <typename T>` helyett. A sablonok paramétereinél a két szó **teljesen egyenértékű**. Manapság a `typename` használata az elterjedtebb, mert kevésbé megtévesztő (hiszen a `T` lehet egy sima `int` is, ami nem osztály).
:::

---

## 3. Osztály Templétek

Nem csak függvényeket, hanem teljes osztályokat is generikussá tehetünk. Például a C++ beépített `std::vector` osztálya is egy templét (ezért kell kiírni, hogy `std::vector<int>`).

Írjunk egy egyszerű `Doboz` osztályt, ami képes bármilyen típusú adatot tárolni!

```cpp
#include <iostream>
#include <string>

template <typename T>
class Doboz {
private:
    T tartalom;

public:
    // Konstruktor
    Doboz(T t) {
        tartalom = t;
    }

    // Getter
    T getTartalom() {
        return tartalom;
    }

    // Setter
    void setTartalom(T t) {
        tartalom = t;
    }
};

int main() {
    // Létrehozunk egy int-eket tároló dobozt
    Doboz<int> szamDoboz(42);
    std::cout << "Szam: " << szamDoboz.getTartalom() << std::endl;

    // Létrehozunk egy string-eket tároló dobozt
    Doboz<std::string> szovegDoboz("Hello Templetek!");
    std::cout << "Szoveg: " << szovegDoboz.getTartalom() << std::endl;

    return 0;
}
```

:::caution[Hol tároljuk a Templétek kódját?]
Hagyományosan az osztályokat szétbontjuk egy `.h` (deklaráció) és egy `.cpp` (megvalósítás) fájlra. **A templéteknél ezt nem tehetjük meg!** Mivel a fordítónak látnia kell a teljes sablonkódot ahhoz, hogy fordítási időben legenerálja az adott típusokat, a templét függvények/osztályok teljes kódját a header (`.h` vagy `.hpp`) fájlban kell tartani!
:::

---

## 4. Gyakorló Feladatok a foglalkozásra

Ezeket a feladatokat közösen fogjuk átbeszélni és leprogramozni.

### 1. Feladat: A "Csere" függvény
C++-ban gyakran kell felcserélni két változó értékét.
* Írj egy `template <typename T> void csere(T& a, T& b)` nevű függvényt, amely megcseréli a két paraméterként kapott változó értékét!
* *(Segítség: Szükséged lesz egy harmadik, ideiglenes `T` típusú változóra a cseréhez).*
* Teszteld le a `main` függvényben `int`, `double` és `std::string` típusokkal is!

### 2. Feladat: Generikus Tömb Nyomtató
* Írj egy sablonfüggvényt, amely képes bármilyen típusú tömb elemeit kiírni a képernyőre, szóközzel elválasztva!
* A függvény paraméterei: `T tomb[]` (maga a tömb) és `int meret` (a tömb hossza).

### 3. Feladat (Haladó): A "Szuper Csomag" osztály
* Készíts egy `Csomag` nevű osztály sablont, amely **kettő** különböző típusú adatot tud tárolni!
* Ehhez a sablonnak két paramétert kell kapnia: `template <typename T1, typename T2>`.
* Írj hozzá egy konstruktort, valamint egy `kiir()` metódust, ami szépen megformázva kiírja mindkét adatot.
* Hozz létre belőle egy objektumot, ami egy `string` nevet és egy `int` életkort tárol (pl. `Csomag<std::string, int> user("Anna", 22);`)!
