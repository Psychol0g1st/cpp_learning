---
title: 1. alkalom - A C++ alapjai és a memóriamodell
description: Hogyan lesz a kódunkból program, és mi is az a változó valójában?
---

Szia! Vágjunk is bele az első alkalomba! Nem az a célom, hogy száraz definíciókat magoljunk be, hanem hogy tényleg megértsd: **mit is csinál pontosan a gép a motorháztető alatt**, amikor lefuttatod a kódodat.

Ma lefektetjük a stabil alapokat: megnézzük, hogyan lesz a gépelt szövegedből futtatható program, mi is az a változó a valóságban, és hogyan néz ki egy igazi, működő C++ kód.

---

### 1. A C++ program felépítése

Minden C++ programnak van egy startvonala, ahonnan az egész elindul. Ez a **`main()` függvény**. Bármit is írunk a `main` függvény kapcsos zárójelei közé `{ }`, azt a gép szépen, sorról sorra végre fogja hajtani.

Nézzük meg a klasszikus "Hello World" programot, és szedjük darabokra:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, Vilag!" << endl;
    return 0;
}

```

* **`#include <iostream>`**: Ezzel szólunk a gépnek, hogy "légyszi, töltsd be a be- és kimenetért felelős cuccokat". Enélkül nem tudnánk a képernyőre írni.
* **`using namespace std;`**: Ezzel spórolunk magunknak egy kis gépelést. Jelzi, hogy a standard (alapértelmezett) C++ elemeket használjuk, így nem kell minden kiíratás elé beírnunk, hogy `std::cout`, elég csak annyi, hogy `cout`.
* **`int main() { ... }`**: A főfüggvény. Amikor duplán kattintasz a programodra, a Windows (vagy Linux/Mac) ezt a blokkot kezdi el futtatni.
* **`cout << ...`**: A "console output" (konzol kimenet) rövidítése. A `<<` jelek mutatják az áramlás irányát: a szöveged belefolyik a konzolba. Az `endl` pedig csak egy entert (sortörést) jelent a végén.
* **`return 0;`**: Ezzel üzenjük az operációs rendszernek, hogy "Köszi, a program hiba nélkül lefutott!". A 0 jelenti a hibamentes kilépést.

---

### 2. Hogyan lesz a szövegből program? (A fordítás)

A C++ egy **lefordított (compiled) nyelv**. A processzorod (CPU) nem beszél angolul, fogalma sincs, mi az az `int` vagy a `return`. A szövegedből gépi kódot (nullákat és egyeseket) kell csinálnunk. Ez három lépésben történik a háttérben:

* **Előfeldolgozó (Preprocessor):** Elsőként végigszalad a kódon, és megkeresi a `#` jellel kezdődő sorokat. Például az `#include <iostream>` esetén fogja, és fizikailag bemásolja az iostream fájl tartalmát a te kódod tetejére.
* **Fordító (Compiler):** Megfogja a kibővített kódodat, és lefordítja a gép számára érthető "tárgykódra", csinál belőle egy nyers fájlt (általában `.o` vagy `.obj` kiterjesztéssel).
* **Szerkesztő (Linker):** Mivel egy komolyabb program ezer helyről szedheti a fájlokat, a linker feladata, hogy ezeket a különálló darabokat és könyvtárakat **egy darab futtatható programmá** (pl. `program.exe`) ragassza össze.

---

### 3. Változók és Alaptípusok

A programozásban az adatainkat változókban (dobozokban) tároljuk. Amikor létrehozol egy változót, meg kell mondanod a típusát. Ez azért fontos, mert ez mondja meg a gépnek, hogy **mennyi helyet foglaljon le**, és **hogyan értelmezze** a benne lévő adatot.

A leggyakoribb típusok:

* **`int` (Integer):** Egész számok (pl. `10`, `-5`).
* **`double` (vagy `float`):** Törtszámok (pl. `3.14`).
* **`char` (Character):** Egyetlen karakter, szimpla idézőjelek között (pl. `'A'`).
* **`bool` (Boolean):** Logikai érték, ami csak `true` (igaz / 1) vagy `false` (hamis / 0) lehet.

---

### 4. A Memória, avagy mi is az a változó valójában?

Itt jön a legfontosabb felismerés! Egy változó a C++-ban **nem csak egy matekos betű**, hanem egy **konkrét, fizikai hely a géped memóriájában (RAM)**, aminek van címe és kiterjedése.

Képzeld el a memóriát úgy, mint egy hatalmas postahivatalt, tele számozott rekeszekkel.

* Minden kis rekesz 1 bájtnyi adatot bír el.
* Ha kérsz egy `int` típusú változót, a gép kinéz neked 4 darab rekeszt egymás mellett (4 bájtot).
* Ennek a 4 rekeszből álló blokknak az **első rekeszének a száma** lesz a változód "memóriacíme".

Két zseniális eszközünk is van, amivel ezt ki tudjuk nyomozni:

* A **`sizeof` operátor**: Megmondja, hány bájtot foglal a memóriában a változód.
* Az **`&` (címképző) operátor**: Ha egy változó neve elé teszed (pl. `&kor`), visszadobja a pontos fizikai címet a RAM-ban (ezt a gép hexadecimális, azaz 16-os számrendszerben írja ki, pl. `0x0053FBA8`).

---

### 5. Adatbekérés a felhasználótól

Hogy ne csak kiírjunk, hanem be is kérjünk adatot, a `cin` ("console input") objektumot és a fordított irányú `>>` operátort használjuk.

```cpp
int eletkor;
cout << "Hany eves vagy? ";
cin >> eletkor; // A begépelt szám a memóriában az 'eletkor' fizikai helyére kerül

```

---

### Gyakorlat: A Memória-vizsgáló program

Ne csak beszéljünk róla, nézzük is meg a memóriát működés közben! Ez a feladat rákényszerít, hogy lásd, mi történik a háttérben.

**A feladat:**
Hozz létre egy `int`, egy `double` és egy `char` változót. Kérj be hozzájuk értékeket, majd írasd ki az értéküket, a méretüket (`sizeof`) és a memóriacímüket (`&`).

**Megoldás és elemzés:**
Másold be ezt a kódot a szerkesztődbe, fordítsd le és futtasd!

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. Dobozok (memória) lefoglalása a RAM-ban
    int egesz_szam;
    double tort_szam;
    char karakter;

    // 2. Értékek bekérése
    cout << "Kerek egy egesz szamot: ";
    cin >> egesz_szam;

    cout << "Kerek egy tort szamot (pl. 3.14): ";
    cin >> tort_szam;

    cout << "Kerek egy betut: ";
    cin >> karakter;

    cout << "\n--- MEMORIA VIZSGALAT ---\n";

    // 3. Eredmények kiíratása
    // (A (void*)&karakter egy kis technikai trükk. A C++ alapból megpróbálja
    // szövegként kiírni a char típusú mutatókat, ezzel a trükkel viszont
    // rákényszerítjük, hogy a nyers memóriacímet mutassa meg.)
    
    cout << "Egesz szam erteke: " << egesz_szam 
         << " | Merete: " << sizeof(egesz_szam) << " bajt" 
         << " | Memoriacime: " << &egesz_szam << endl;

    cout << "Tort szam erteke: " << tort_szam 
         << " | Merete: " << sizeof(tort_szam) << " bajt" 
         << " | Memoriacime: " << &tort_szam << endl;

    cout << "Karakter erteke: " << karakter 
         << " | Merete: " << sizeof(karakter) << " bajt" 
         << " | Memoriacime: " << (void*)&karakter << endl;

    return 0;
}

```

> **Mire figyelj a kimenetnél?**
> * Látni fogod a méreteket: egy `char` általában 1 bájtot, az `int` 4 bájtot, a `double` 8 bájtot eszik meg.
> * A memóriacímek (pl. `0x7ffeefbff5ac`) megmutatják a fizikai valóságot. Ha megnézed őket, látni fogod, hogy nagyon közel vannak egymáshoz, jelezve, hogy a változóidat a gép szépen libasorban pakolta le a memóriába.
> * Ha többször egymás után lefuttatod a programot, a címek valószínűleg változni fognak! Ez azért van, mert az operációs rendszered biztonsági okokból mindig máshová osztja ki a programodnak a szabad memóriát.
