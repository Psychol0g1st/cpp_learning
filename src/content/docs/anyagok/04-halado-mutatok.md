---
title: 04. Haladó Mutatók - Tömbök, Sztringek és Mátrixok
description: Lépjünk a színfalak mögé! Hogyan kezeli a C++ a memóriában a többdimenziós adatokat és a szövegeket mutatók segítségével?
---

Szia! Eddig azt láttuk, hogy egy mutató egyetlen változóra (egy `int`-re vagy egy objektumra) mutat. De mi történik, ha sok adatunk van egymás mellett? Itt kezdődik az igazi "mérnöki" C++ programozás!

Ebben a leckében lerántjuk a leplet a tömbökről, belenézünk a szövegek (`string`-ek) memóriaképébe, és megépítjük a végső főellenséget: a dinamikus mátrixot (2D tömböt).

---

## 1. A Nagy Titok: A Tömb neve is csak egy Mutató!

Ha létrehozol egy statikus tömböt: `int szamok[5] = {10, 20, 30, 40, 50};`, te azt hiszed, a `szamok` egy 5 elemű doboz. A gép viszont máshogy gondolja. 

A C++-ban **egy tömb neve valójában egy memóriacím**, ami a tömb legelső (nulladik) elemére mutat! Vagyis a `szamok` egyenértékű azzal, hogy `&szamok[0]`.

### Pointer Aritmetika (Lépkedés a memóriában)
Mivel a tömb elemei szorosan egymás mellett vannak a memóriában, a mutatókhoz hozzáadhatunk számokat, hogy "lépegessünk" rajtuk.

```cpp
#include <iostream>
using namespace std;

int main() {
    int szamok[3] = {10, 20, 30};
    int* ptr = szamok; // A ptr most a 10-esre (a 0. indexre) mutat

    cout << "Elso elem: " << *ptr << endl; // 10

    // Lépjünk egyet előre a memóriában!
    ptr = ptr + 1; // A gép tudja, hogy egy int 4 bájt, így automatikusan 4 bájttal ugrik tovább!
    cout << "Masodik elem: " << *ptr << endl; // 20

    // Sőt, ezt írhatjuk így is (ez pontosan ugyanaz, mint a szamok[2]):
    cout << "Harmadik elem: " << *(szamok + 2) << endl; // 30

    return 0;
}

```

> **Aha! élmény:** Amikor azt írod, hogy `tomb[2]`, a C++ a motorháztető alatt ezt csinálja: fogja a `tomb` kezdőcímét, hozzáad `2`-t, és kinyitja a memóriát (`*(tomb + 2)`). A szögletes zárójel csak egy kényelmi funkció (szintaktikai cukorka)!

---

## 2. Dinamikus Tömbök (A `new[]` és `delete[]`)

A statikus tömbök méretét fordításkor tudni kell (`int tomb[100];`). De mi van, ha a felhasználó dönti el, hány elem kell? Ilyenkor a Heap-en (dinamikus memóriában) kell helyet kérnünk mutatók segítségével.

```cpp
int meret;
cout << "Hany adat lesz? ";
cin >> meret;

// 1. Memória lefoglalása a Heap-en. A 'new' egy mutatót ad vissza a blokk elejére.
int* dinamikusTomb = new int[meret];

// 2. Használhatjuk úgy, mint egy sima tömböt
for(int i = 0; i < meret; i++) {
    dinamikusTomb[i] = i * 2;
}

// 3. KÖTELEZŐ: Felszabadítás! Mivel tömböt foglaltunk (szögletes zárójel), 
// a törlésnél is használni kell a [] jelet, különben memóriaszivárgás lesz!
delete[] dinamikusTomb; 

```

---

## 3. Sztringek és a `char*` (A régi C-s módszer)

A modern C++-ban imádjuk az `std::string`-et. De a háttérben (és sok régebbi kódban) a szöveg nem más, mint egy dinamikus karaktertömb, aminek a legvégén van egy speciális láthatatlan karakter, a **lezáró nulla (`\0`)**.

Ha látsz egy ilyet: `const char* szoveg = "Hello";`, ez azt jelenti, hogy a `szoveg` egy mutató, ami a 'H' betű memóriacímére mutat. A gép onnan tudja, hogy hol van a szöveg vége, hogy addig lépked a memóriában, amíg meg nem találja a `\0`-t.

```cpp
const char* uzenet = "C++"; 
// A memóriában: ['C', '+', '+', '\0']

const char* ptr = uzenet;

// Lépkedjünk a mutatóról mutatóra, amíg el nem érjük a lezáró nullát!
while (*ptr != '\0') {
    cout << "Karakter a memoriaban: " << *ptr << endl;
    ptr++; // Ugrás a következő bájt-ra
}

```

---

## 4. A Főellenség: Mátrixok (2D Dinamikus Tömbök)

Hogyan csinálunk olyan rácsot (mátrixot), aminek a sorait és oszlopait is futási időben, a felhasználó mondja meg? A válasz: **Egy mutatókat tároló tömb, ahol minden mutató egy újabb tömbre mutat!** Ezt hívjuk "Pointer a pointerre" szerkezetnek (`int**`).

Gondolj rá úgy, mint egy könyvespolcra. A `**matrix` a polc maga. A polc minden sora egy mutató (`*`), ami egy konkrét könyvsorozatra (tömbre) mutat.

### A 3 lépéses folyamat:

```cpp
int sorok = 3;
int oszlopok = 4;

// LÉPÉS 1: Létrehozzuk a "polcot" (Egy tömb, ami int* mutatókat tárol)
int** matrix = new int*[sorok];

// LÉPÉS 2: Minden sornál lefoglaljuk a tényleges oszlopokat (az adatokat)
for (int i = 0; i < sorok; i++) {
    matrix[i] = new int[oszlopok];
}

// Használat: Pont ugyanúgy, mint egy sima 2D tömböt!
matrix[1][2] = 42; // A 2. sor 3. eleme (indexelés 0-tól indul)

// LÉPÉS 3: A takarítás (Megfordítjuk a folyamatot!)
// Először a sorokat (az oszlop-tömböket) kell kitörölni
for (int i = 0; i < sorok; i++) {
    delete[] matrix[i];
}
// Végül magát a polcot (a mutatókat tároló tömböt) töröljük
delete[] matrix;

```

*Ha csak a `delete[] matrix;`-ot hívnád meg a végén, a sorok adatai örökre bent ragadnának a memóriában! Mindig kifelé haladunk a törléssel.*

---

### 📝 Gyakorlat: A Dinamikus Kincstérkép

Most teszteljük le, hogy átlátod-e a 2D mátrixokat!

**A feladat:**

1. Kérd be a felhasználótól a térkép méretét (N sor és M oszlop).
2. Hozz létre dinamikusan egy `char**` (karaktereket tároló) mátrixot a fent tanult módon.
3. Töltsd fel a teljes mátrixot pont karakterekkel (`.`), ami a homokot jelképezi.
4. Kérj be egy X és Y koordinátát, és tegyél oda egy `X` karaktert (ez a kincs!).
5. Írasd ki a képernyőre a teljes mátrixot két egymásba ágyazott `for` ciklussal.
6. A program végén szakszerűen, lépésről lépésre szabadítsd fel a lefoglalt memóriát (`delete[]`).

Ha ezt a feladatot össze tudod rakni, akkor a memóriakezelés és a pointerek többé nem fognak tudni meglepni!

```
