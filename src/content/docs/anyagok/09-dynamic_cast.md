---
title: "09. Típuskonverzió: dynamic_cast"
description: Ismerd meg a biztonságos lefelé kasztolás (downcasting) mechanizmusát és a futásidejű típusazonosítást (RTTI).
---

Gondolkoztál már azon, mi történik, ha van egy listád `Alakzat*` mutatókkal, de neked hirtelen pontosan tudnod kellene, hogy az adott mutató egy `Kör` vagy egy `Négyzet` objektumra mutat-e? 

Mivel a C++ statikus típusos nyelv, a fordító csak azt látja, hogy az egy `Alakzat`. A **dynamic_cast** az az eszköz, amivel "megkérdezhetjük" az objektumot futás közben: *"Te tényleg egy Kör vagy?"*

## 1. Mi az a dynamic_cast?

A `dynamic_cast` a C++ négy speciális kasztoló operátorának egyike. Elsődleges feladata a **biztonságos lefelé kasztolás** (*downcasting*): az öröklődési hierarchiában egy ősosztály mutatóját (vagy referenciáját) egy származtatott osztály típusává alakítja.

### A legfontosabb feltétel
A `dynamic_cast` csak akkor működik, ha az alaposztály **polimorf**, azaz tartalmaz legalább egy **virtuális függvényt** (lehetőleg egy virtuális destruktort).

> **Miért?** Mert a `dynamic_cast` a futásidejű típusinformációt (**RTTI** - *Run-Time Type Information*) használja, ami az objektum virtuális metódus táblájához (vtable) kötődik. Ha nincs virtuális függvény, nincs vtable, és a `dynamic_cast` nem tudja ellenőrizni a típust.

---

## 2. Mutatók vs. Referenciák

A `dynamic_cast` kétféleképpen jelezheti, ha a konverzió nem lehetséges:

### A) Mutatók esetén (Biztonságos ellenőrzés)
Ha a konverzió sikertelen (pl. egy `Macska` objektumot próbálsz `Kutya*` típussá kasztolni), az eredmény **`nullptr`** lesz. Ez teszi lehetővé az egyszerű `if` alapú ellenőrzést.

### B) Referenciák esetén (Kivételkezelés)
Mivel C++-ban nem létezik "null referencia", hiba esetén a program egy **`std::bad_cast`** típusú kivételt dob. Ezt `try-catch` blokkal kell kezelni.

---

## 3. Kódpélda: Az Állatkert

```cpp
#include <iostream>
#include <vector>

class Allat {
public:
    virtual void hangotAd() { std::cout << "...\n"; }
    virtual ~Allat() {} // Virtuális destruktor = Polimorfizmus
};

class Kutya : public Allat {
public:
    void hangotAd() override { std::cout << "Vau!\n"; }
    void farkatCsoval() { std::cout << "*Boldog kutya hangok*\n"; }
};

class Macska : public Allat {
public:
    void hangotAd() override { std::cout << "Miau!\n"; }
    void dorombol() { std::cout << "Prrr...\n"; }
};

void interakcio(Allat* a) {
    // Megpróbáljuk kutyaként kezelni
    Kutya* k = dynamic_cast<Kutya*>(a);
    
    if (k) {
        // Sikerült! A mutató nem null.
        k->farkatCsoval();
    } else {
        // Nem kutya volt. Próbáljuk macskaként.
        Macska* m = dynamic_cast<Macska*>(a);
        if (m) {
            m->dorombol();
        } else {
            std::cout << "Ez egy ismeretlen állat.\n";
        }
    }
}
```

---


## 4. Gyakorló Feladatok

### 1. Feladat: A biztonságos Plugin rendszer
Készíts egy `Plugin` ősosztályt és két származtatottat: `AudioPlugin` és `VideoPlugin`.
* Az `AudioPlugin` rendelkezzen egy `setVolume(int)` metódussal.
* Írj egy függvényt, ami egy `Plugin*` listát kap, és csak az audio pluginokon állítja be a hangerőt 50-re a `dynamic_cast` segítségével.

### 2. Feladat: Referencia kasztolás (Kivételkezelés)
Írj egy programot, amely egy `Allat&` referenciát próbál `Macska&` referenciává alakítani.
* Készítsd fel a programot arra, hogy ha az állat nem macska, ne omoljon össze, hanem írja ki: "Sajnos ez nem egy cica". (Használj `try-catch` blokkot és `std::bad_cast`-ot).

---

## Összefoglaló táblázat

| Szempont | dynamic_cast | static_cast |
| :--- | :--- | :--- |
| **Mikor fut le?** | Futási időben (Runtime) | Fordítási időben (Compile time) |
| **Biztonság** | Ellenőrzi a típust, hibázhat | Nem ellenőriz, vakon bízik a programozóban |
| **Feltétel** | Polimorf osztály (virtuális fv.) | Nem szükséges polimorfizmus |
| **Hiba jelzése** | `nullptr` vagy kivétel | Nincs (hibás adatot eredményezhet) |
| **Alkalmazás** | Biztonságos Downcasting | Upcasting vagy primitív típusok (int -> float) |

---

### Mire figyelj?
A `dynamic_cast` lassabb, mint a `static_cast`, mert futás közben ellenőrzi a típusokat. Ha biztosan tudod, hogy a mutató mi lesz, használj `static_cast`-ot, de ha bizonytalan vagy (pl. egy külső API-ból érkező objektumnál), a `dynamic_cast` az egyetlen biztonságos út!
