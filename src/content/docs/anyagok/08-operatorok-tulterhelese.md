---
title: 08. Operátorok Átdefiniálása C++-ban
description: Sajátítsd el az operátor túlterhelés csínját-bínját a motivációtól kezdve a komplex generikus rendszerekig.
---

Gondoltál már arra, milyen jó lenne, ha két saját magad által írt `Pont` objektumot egyszerűen össze tudnál adni egy `+` jellel, pont úgy, mintha sima számok lennének? 
A C++-ban ezt megtehetjük! Ezt hívják **operátor átdefiniálásnak** (vagy túlterhelésnek - *operator overloading*).

A fő cél a **tömör és jól olvasható kód**.

## 1. A Játékszabályok (Korlátok)

Mielőtt belevágunk, van néhány vasszabály, amit a C++ megkövetel :
* **Nincs új varázslat:** Csak létező operátorokat írhatunk felül (pl. `+`, `-`, `*`, `==`). Nem találhatunk ki újakat (pl. nincs `**` a hatványozásra).
* **A matek szabályai maradnak:** Nem változtathatjuk meg az operandusok számát (a `+` mindig két oldalt vár).
* **A sorrend szent:** A műveleti sorrend (precedencia) nem módosítható (a szorzás mindig erősebb marad, mint az összeadás).
* **Nem módosítható operátorok:** `::` (hatókör), `.` (tagelérés), `.*` (mutató tagon át), `?:` (feltételes), `sizeof`.

---

## 2. Hogyan írjuk meg? (A két út)

Az operátorokat speciális függvényekként definiáljuk, melyek neve az `operator` szóból és magából a jelből áll (pl. `operator+`).

### A) Tagfüggvényként (Amikor módosítjuk magunkat)
Ha a művelet megváltoztatja magát az objektumot (pl. `+=`, `++`, `=`), akkor az operátort az osztályon **belül** írjuk meg. Ilyenkor az első paraméter rejtetten a `this` mutató.

### B) Külső függvényként (Amikor új eredmény születik)
Ha a művelet nem bántja az eredetit, hanem egy **új** objektumot hoz létre (pl. `+`, `-`, `==`), érdemes az osztályon kívül megírni.

> **Mi az a `friend`?**
> Ha egy függvény az osztályon kívül van, nem látja a privát (`private`) adatokat. Ha azonban az osztályon belül **barátnak** (`friend`) nyilvánítjuk, akkor szabad bejárása lesz a rejtett adattagokhoz is. Ez elengedhetetlen a kiírató (`<<`) operátornál!

---

## 3. Kódpéldák: A Pont osztály

### A destruktív `+=` (Tagfüggvény) és a barátságos `<<`

```cpp
#include <iostream>

class Pont {
private:
    int x, y;

public:
    Pont(int x = 0, int y = 0) : x(x), y(y) {}

    // += módosítja az eredetit, tehát tagfüggvény 
    const Pont& operator+=(const Pont& masik) {
        this->x += masik.x;
        this->y += masik.y;
        return *this; // Visszaadjuk magunkat láncoláshoz 
    }

    // A kiírató operátor külső függvény, de barát (friend)
    friend std::ostream& operator<<(std::ostream& os, const Pont& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// Sima összeadás: külső függvény, a +=-re vezetjük vissza 
Pont operator+(Pont a, const Pont& b) {
    a += b; 
    return a;
}
```

### Prefix és Postfix növelés (`++`)
A kettőt egy látszat `int` paraméterrel különböztetjük meg:

```cpp
// Prefix (++p): Növeli, majd visszaadja magát
Pont& operator++() {
    x++; y++;
    return *this;
}

// Postfix (p++): Elmenti a régit, növel, majd a régit adja vissza
Pont operator++(int) {
    Pont regi = *this;
    x++; y++;
    return regi;
}
```

---

## Interaktív Operátor Tanácsadó

Nézd meg, hogyan alakítja át a fordító a kódodat függvényhívásokká a háttérben!

```json?chameleon
{"component":"LlmGeneratedComponent","props":{"height":"650px","prompt":"Hozzon létre egy interaktív oktatóeszközt 'C++ Operátor Vizualizáló' néven. A felhasználó választhasson kódminták közül: 'a += b', 'a + b', 'cout << a', '++a'. Amikor választ, jelenjen meg a 'színfalak mögötti' transzformáció (pl. 'a + b' -> 'operator+(a, b)'). Magyarázza el közérthető magyar nyelven, hogy miért tagfüggvény vagy külső függvény az adott megvalósítás, és mi a visszatérési értéke. Az eszköz legyen vizuálisan tiszta, a kód részeit jelölje ki (pl. paraméterek, operátor név). Ne használjon CSS-t a promptban.","id":"im_f6f6b63203ebcd15"}}
```

---

## 4. Gyakorló Feladatok

### 1. Feladat: A Tört-matek (Kezdő)
Készíts egy `Tort` osztályt (számláló és nevező)!
* Írd meg a `*` operátort két tört szorzásához.
* Írd meg a `==` operátort az egyenlőség vizsgálatához.
* Készíts `<<` operátort a `szamlalo/nevezo` formátumhoz.

### 2. Feladat: Dinamikus Tároló (Haladó)
Írj egy osztályt, ami szavakat tárol (`std::vector<std::string>`).
* A `+` operátorral fűzz hozzá egy új szót a vektorhoz.
* A `[]` operátorral lehessen elérni a szavakat index alapján.

### 3. Mester Feladat: Generikus Alakzat Rendszer
*Ez a feladat az absztrakt osztályokat, a sablonokat és az operátorokat ötvözi!*

1. **Absztrakt Ős:** Készíts egy `Alakzat` osztályt, tisztán virtuális `double terulet() const = 0;` metódussal.
2. **Gyerekek:** Származtass belőle `Negyzet` (oldal) és `Kor` (sugar) osztályokat.
3. **Operátor:** Az `Alakzat` osztályhoz írj egy `<` operátort (külső függvényként), ami terület alapján hasonlít össze két alakzatot.
4. **Sablon Tároló:** Készíts egy `Tarolo<T>` osztálysablont.
5. **A Csúcs:** A `Tarolo` kapjon egy `+` operátort! Ha két tárolót összeadunk, az adja vissza azt a tárolót, amelyikben a **nagyobb területű** alakzat van. 
   *(Segítség: Mivel az `Alakzat` absztrakt, a tárolóban mutatókat (`Alakzat*`) tárolj!)*

---

## Összefoglaló táblázat

| Operátor típus | Hol írjuk meg? | Példa |
| :--- | :--- | :--- |
| **Módosító** | Tagfüggvény | `=`, `+=`, `++`, `[]` |
| **Lekérdező** | Külső függvény | `+`, `-`, `==`, `<` |
| **I/O Stream** | Külső `friend` függvény | `<<`, `>>` |
```
