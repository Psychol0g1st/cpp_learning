---
title: 3. alkalom - Mutatók, OOP alapok és a több fájlos kód
description: Lépjünk szintet! Hogyan nyúljunk közvetlenül a memóriához, és hogyan szervezzük a kódunkat mérnöki módon?
---

Üdv újra itt! Eddig nagyon jól haladunk az alapokkal, de most egy hatalmas lépést teszünk előre. 

Ahhoz, hogy komolyabb programokat (és később rendszereket vagy játékokat) tudjunk írni, muszáj megértenünk, hogyan nyúlhatunk *közvetlenül* a gép memóriájához, hogyan tudjuk az adatainkat fájlokba menteni, és hogyan rakjunk rendet a kódunkban az Objektumorientált Programozás (OOP) segítségével.

Ez az alkalom egy kicsit sűrű lesz, de hidd el, ha ezen átrágjuk magunkat, onnantól teljesen más szemmel fogsz nézni a programozásra!

---

### 1. Mutatók (Pointers): A közvetlen memóriahozzáférés

**A koncepció:** Emlékszel az 1. alkalomra? Minden változó egy fizikai hely a memóriában (RAM), aminek van egy memóriacíme (pl. `0x7ffeefbff5ac`). 

A **mutató (pointer)** egy speciális változó. Nem számot, nem szöveget, hanem **kizárólag egy másik változó memóriacímét** képes tárolni. Segítségével anélkül tudunk belenyúlni egy változóba, hogy lemásolnánk azt. 

Három alapvető lépést kell megértenünk:
1. **Címképzés (`&` operátor):** Ezzel kérdezzük le egy meglévő változó memóriacímét.
2. **Mutató létrehozása (`*` a típusnál):** Így hozzuk létre magát a memóriacímet tároló dobozt.
3. **Dereferálás (`*` a változó előtt):** Ez a "nyitókód". Ezzel megyünk el a tárolt memóriacímre, és olvassuk ki / írjuk felül az ott lévő *tényleges* adatot.

```cpp
#include <iostream>
using namespace std;

int main() {
    int eletkor = 25;

    // Mutató létrehozása, ami az 'eletkor' memóriacímét tárolja.
    // Figyeld meg a csillagot az int után, és az & jelet az eletkor előtt!
    int* ptr = &eletkor;

    cout << "Az eredeti eletkor: " << eletkor << endl;
    
    // Ha csak kiírom a ptr-t, a hexadecimális memóriacímet kapom:
    cout << "Az 'eletkor' memoriacime: " << ptr << endl;

    // DEREFERÁLÁS: A csillaggal "benyúlunk" a cím mögé, és átírjuk a RAM-ban lévő adatot!
    *ptr = 99;

    cout << "Az eletkor UJ erteke: " << eletkor << endl; // Ez 99 lesz!

    return 0;
}

```

> **Ökölszabály:** Ha létrehozol egy mutatót, de még nem tudod, hova fog mutatni, *sose hagyd üresen*! Mindig adj neki `nullptr` (null pointer) értéket (pl. `int* p = nullptr;`). Egy "lógó", véletlenszerű memóriaszemétre mutató pointer a program azonnali összeomlásához vezethet!

---

### 2. Fájlok olvasása és írása (File I/O)

**A koncepció:** Bármit is tárolunk a memóriában (akár mutatókkal), az a program leállásakor azonnal megsemmisül. Ha tartósan meg akarunk őrizni valamit, le kell mentenünk a merevlemezre egy fájlba. Ehhez az `<fstream>` könyvtárat használjuk.

* **`ofstream` (Output File Stream):** Fájlok írására.
* **`ifstream` (Input File Stream):** Fájlok olvasására.

```cpp
#include <iostream>
#include <fstream> // Kötelező a fájlkezeléshez!
#include <string>
using namespace std;

int main() {
    // 1. ÍRÁS FÁJLBA
    ofstream ki_fajl("mentes.txt"); 
    
    // Mindig ellenőrizd, hogy sikerült-e megnyitni a fájlt!
    if (ki_fajl.is_open()) {
        ki_fajl << "Ezt a szoveget a C++ program irta!" << endl;
        ki_fajl.close(); // Illik bezárni a fájlt, ha végeztünk!
        cout << "Mentes sikeres." << endl;
    } else {
        cout << "Hiba a fajl megnyitasakor!" << endl;
    }

    // 2. OLVASÁS FÁJLBÓL
    ifstream be_fajl("mentes.txt");
    if (be_fajl.is_open()) {
        string sor;
        // A getline sorról sorra olvassa a fájlt, amíg van benne valami
        while (getline(be_fajl, sor)) {
            cout << "Fajlbol beolvasva: " << sor << endl;
        }
        be_fajl.close();
    }
    return 0;
}

```

---

### 3. Struktúrák (Structs) és a Nyíl (`->`) operátor

**A koncepció:** Tegyük fel, hogy egy diák adatait akarjuk tárolni (név, átlag). Nem akarunk külön `nev` és `atlag` változókkal zsonglőrködni. A `struct` segítségével ezeket egyetlen közös, új típusba csomagolhatjuk.

Ha egy ilyen struktúrára *mutatóval* hivatkozunk, nem használhatjuk a sima pont (`.`) operátort. Helyette bejön a képbe a **nyíl operátor (`->`)**, ami automatikusan elvégzi nekünk a dereferálást (a `*` használatát) és a belső adat elérését.

```cpp
struct Diak {
    string nev;
    double atlag;
};

int main() {
    Diak d1;
    d1.nev = "Kovacs Peter"; // Közvetlen elérés pont (.) operátorral

    Diak* mutato = &d1;       // Csinálunk egy mutatót a diákra

    // Pointeren keresztüli elérés a -> operátorral!
    mutato->atlag = 4.5;      // Ez pontosan ugyanaz, mintha ezt írtuk volna: (*mutato).atlag = 4.5;

    cout << mutato->nev << " atlaga: " << mutato->atlag << endl;
    return 0;
}

```

---

### 4. Belépés az OOP (Objektumorientált Programozás) világába

**A koncepció:** A `struct` tök jó, de van vele egy baj: "nyitott". Bárki, bárhonnan átírhatja a diák átlagát mondjuk `-500`-ra, és a program nem fog szólni.

Az OOP legfőbb elve az **egységbezárás (encapsulation)**. A változókat és az azokkal dolgozó függvényeket egy közös "osztályba" (`class`) zárjuk, a belső adatokat pedig elrejtjük (priváttá tesszük) a külvilág elől.

```cpp
class Diak {
private: // Ezekhez csak maga az osztály fér hozzá!
    string nev;
    double atlag;

public: // Ezeket bárki használhatja kívülről is
    
    // 1. Konstruktor: Ez fut le automatikusan, amikor "megszületik" az objektum
    Diak(string n, double a) {
        nev = n;
        atlag = a;
    }

    // 2. Getter metódusok: Ezekkel lehet biztonságosan, csak olvasásra kikérni a privát adatokat
    string getNev() { return nev; }
    double getAtlag() { return atlag; }
};

```

---

### 5. Moduláris programozás (Rend a lelke mindennek)

Egy komoly program sosem áll egyetlen, végtelenül hosszú `main.cpp` fájlból. A C++ megköveteli, hogy szétválasszuk a *tervrajzot* (deklaráció) a *tényleges működéstől* (definíció). Ezt több fájl használatával érjük el.

Nézzük meg, hogyan néz ki a fenti `Diak` osztály helyesen, három fájlra bontva:

**1. `Diak.h` (A Header fájl - A Tervrajz)**
Itt csak megmondjuk, hogy mik lesznek az osztályban, de nem írjuk meg a kódjukat.

```cpp
#pragma once // Kötelező! Megakadályozza, hogy a fordító kétszer töltse be ezt a fájlt.
#include <string>

class Diak {
private:
    std::string nev;
    double atlag;
public:
    Diak(std::string n, double a); // Csak deklaráljuk, hogy lesz ilyen!
    std::string getNev();
    double getAtlag();
};

```

**2. `Diak.cpp` (A Forrásfájl - A Megvalósítás)**
Itt beemeljük a tervrajzot, és a hatókör operátorral (`::`) megmondjuk, hogy most a `Diak` osztály függvényeit írjuk meg.

```cpp
#include "Diak.h"

// A :: operátor köti a metódust az osztályhoz
Diak::Diak(std::string n, double a) {
    nev = n;
    atlag = a;
}

std::string Diak::getNev() { return nev; }
double Diak::getAtlag() { return atlag; }

```

**3. `main.cpp` (A Főprogram - A Használat)**

```cpp
#include <iostream>
#include "Diak.h" // Csak a tervrajzot emeljük be!

using namespace std;

int main() {
    Diak d1("Kovacs Peter", 4.5); // Itt fut le a konstruktor
    cout << d1.getNev() << " atlaga: " << d1.getAtlag() << endl;
    return 0;
}

```

---

### 📝 Gyakorlat: A "Pointeres Fájl-Exportáló"

Lássuk, hogyan állnak össze a ma tanultak (Mutatók, Fájlok, OOP, Modulok) egyetlen mérnöki egységgé!

**A feladat lépései:**

1. Hozd létre a projektet a fenti 3 fájlos szerkezetben (`Diak.h`, `Diak.cpp`, `main.cpp`). Másold be a fenti kódokat!
2. A `main.cpp`-ben példányosíts egy `Diak` objektumot (adj neki egy nevet és egy átlagot).
3. **Itt jön a csavar:** Hozz létre egy `Diak*` típusú mutatót, ami erre az objektumra mutat (ne felejtsd az `&` jelet!).
4. Nyiss meg egy `jegyek.txt` fájlt írásra (`ofstream`).
5. Szigorúan **csak a mutatón és a nyíl operátoron (`->`) keresztül** hívd meg a gettereket (`getNev()`, `getAtlag()`), és az eredményt írd bele a szöveges fájlba!

> **A "Linker Error" kipróbálása:**
> Mielőtt a VS Code Play gombjával lefuttatnád a projektet, próbáld meg ezt: nyiss egy terminált, és írd be ezt a parancsot: `g++ main.cpp -o program.exe` (vagyis direkt kihagyjuk a `Diak.cpp`-t).
> Látni fogod, hogy kapsz egy csúnya "Undefined reference" (Nem definiált hivatkozás) hibát. Ez azért van, mert a `main.cpp` a headerből tudja ugyan, hogy *léteznek* a függvények (a fordító átengedte), de a Linker (szerkesztő) nem találja a *tényleges kódot*, mert nem adtuk oda neki a `Diak.cpp`-t.
> Ha mindkettőt megadod neki (`g++ main.cpp Diak.cpp -o program.exe`), varázslatosan működni fog!

