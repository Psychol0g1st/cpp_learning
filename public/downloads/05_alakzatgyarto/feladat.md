# 05 – Alakzatgyártó

Ebben a feladatsorban ismét az `Image` absztrakt alaposztályból kell kiindulni.  
Az `Image` tárolja a szélességet és a magasságot, és ki tudja írni a képet.

A világos pont `.` karakterrel, a sötét pont `#` karakterrel jelenik meg.

---

## PART1 – Függőleges csíkok

Készíts egy `VerticalStripes` nevű osztályt a `verticalstripes.h` és `verticalstripes.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály függőleges világos csíkokat rajzoljon.  
A csíkok szabályosan ismétlődjenek, és minden csík azonos szélességű legyen.

A konstruktor 3 egész számot várjon ebben a sorrendben:
1. a kép szélessége
2. a kép magassága
3. a világos csík szélessége

A tesztelés ilyen példákat használ:
- `VerticalStripes(9,5,2)`
- `VerticalStripes(10,4,3)`

Tehát az osztálynak a méreten kívül tárolnia kell a csíkszélességet.

---

## PART2 – Homokóra

Készíts egy `Hourglass` nevű osztályt a `hourglass.h` és `hourglass.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály homokóra alakú világos mintát jelenítsen meg:
- felül széles legyen,
- a közepe felé keskenyedjen,
- utána újra szélesedjen.

A konstruktor 2 egész számot kapjon:
1. szélesség
2. magasság

A tesztelés ilyen példányosításokat használ:
- `Hourglass(9,5)`
- `Hourglass(11,7)`

A feladat lényege a soronként változó szélesség és a szimmetria kezelése.

---

## PART3 – Eltolt kép

Készíts egy `Shifted` nevű osztályt a `shifted.h` és `shifted.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály egy meglévő képet toljon el a síkon:
- legyen megadva vízszintes eltolás,
- legyen megadva függőleges eltolás,
- ami a képből kicsúszik, az ne jelenjen meg,
- az üresen maradó részek legyenek sötétek.

A konstruktor 3 paramétert várjon:
1. egy meglévő `Image` objektum címe
2. a vízszintes eltolás
3. a függőleges eltolás

A teszt ilyen hívásokat használ:
- `Shifted(&e1,2,1)`
- `Shifted(&e2,-1,2)`

Tehát az osztálynak tárolnia kell:
- az eredeti képet,
- a két eltolási értéket.

---

## PART4 – Célpontok

Készíts egy `Targets` nevű osztályt a `targets.h` és `targets.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály egy olyan képet reprezentáljon, amelyre több célpont helyezhető el.  
Minden célpontnak legyen:
- x koordinátája,
- y koordinátája,
- mérete vagy sugara.

Egy célpont céltáblaszerű, koncentrikus mintát hozzon létre.  
A célpontok egymás mellé vagy egymás részleges átfedésébe is kerülhetnek.

A konstruktor 2 egész számot kapjon:
1. szélesség
2. magasság

Az osztályban legyen egy `addTarget` nevű művelet, amely 3 egész számot vár:
1. x koordináta
2. y koordináta
3. méret vagy sugár

A tesztelés ilyen hívásokat használ:
- `t1.addTarget(3,3,2);`
- `t1.addTarget(8,2,1);`

Tehát az osztálynak több célpont adatait kell eltárolnia.

---

## PART5 – Fájlba mentés

Egészítsd ki az `Image` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a tartalmat mentse fájlba, amit a `print()` is kiír:
- először a szélesség és magasság,
- utána a kép sorai.

A művelet neve pontosan `saveToFile` legyen.

---

## Megjegyzés

A `main.cpp` mutatja a teszteseteket, a helyes mintát a `minta-stdout.txt` tartalmazza.
