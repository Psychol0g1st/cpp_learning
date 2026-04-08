# 03 – Sorozatlabor

Ebben a feladatsorban nem képet, hanem számsorozatot kell megvalósítani.  
Az alapkód egy `Sequence` nevű absztrakt alaposztályt ad.

A `Sequence`:
- tárolja a sorozat hosszát,
- ki tudja írni a sorozat elemeit,
- de azt neked kell megadni, hogy egy adott indexen milyen érték van.

---

## PART1 – Számtani sorozat

Készíts egy `ArithmeticSequence` nevű osztályt az `arithmetic.h` és `arithmetic.cpp` fájlokban.  
Az osztály a `Sequence` osztályból származzon.

Ez az osztály számtani sorozatot írjon le:
- van egy kezdőérték,
- minden következő elem ugyanannyival tér el az előzőtől.

A konstruktor 3 egész számot várjon ebben a sorrendben:
1. a kezdőérték
2. a lépésköz
3. a sorozat hossza

A tesztelés ilyen példákat használ:
- `ArithmeticSequence(3,4,6)`
- `ArithmeticSequence(-2,3,5)`

Tehát az osztálynak a hossz mellett még tárolnia kell:
- a kezdőértéket,
- a lépésközt.

---

## PART2 – Cikázó sorozat

Készíts egy `ZigZagSequence` nevű osztályt a `zigzag.h` és `zigzag.cpp` fájlokban.  
Az osztály a `Sequence` osztályból származzon.

Ez a sorozat egy alsó és felső érték között oda-vissza mozogjon:
- indul egy kezdőértékről,
- egyesével halad,
- ha eléri a felső határt, visszafordul,
- ha eléri az alsó határt, újra felfelé indul.

A tesztek alapján a konstruktor 3 egész számot kapjon ebben a sorrendben:
1. az alsó határ
2. a felső határ
3. a sorozat hossza

A létrehozott sorozat mindig az alsó határról induljon.

A tesztelés ilyen példákat használ:
- `ZigZagSequence(2,5,9)` → 2,3,4,5,4,3,2,3,4
- `ZigZagSequence(-1,1,7)` → -1,0,1,0,-1,0,1

Tehát az osztálynak tárolnia kell:
- az alsó határt,
- a felső határt.

---

## PART3 – Fordított sorozat

Készíts egy `ReverseSequence` nevű osztályt a `reversed.h` és `reversed.cpp` fájlokban.  
Az osztály a `Sequence` osztályból származzon.

Ez az osztály egy meglévő sorozatot fordított sorrendben jelenítsen meg:
- az eredeti utolsó eleme legyen az új első,
- az eredeti első eleme legyen az új utolsó.

A konstruktor egyetlen paramétert várjon:
- egy meglévő `Sequence` objektum címét.

A teszt így használja:
- `ReverseSequence(&valamilyenSorozat)`

Tehát az osztálynak egy másik sorozatra kell hivatkoznia.

---

## PART4 – Jelölt elemek

Készíts egy `MarkedSequence` nevű osztályt a `marked.h` és `marked.cpp` fájlokban.  
Az osztály a `Sequence` osztályból származzon.

Ez az osztály egy meglévő sorozatra épüljön, de bizonyos indexeken felül lehessen írni az eredeti értéket.

A működés:
- alapból a becsomagolt sorozat értékei látszanak,
- ha egy indexhez külön értéket rendeltél, akkor azon a helyen azt kell visszaadni.

A konstruktor egy paramétert várjon:
- egy meglévő `Sequence` objektum címét.

Az osztályban legyen egy `mark` nevű művelet, amely 2 egész számot kap:
1. az index
2. az új érték

A tesztelés ilyen hívásokat használ:
- `MarkedSequence m1(&e1);`
- `m1.mark(1,100);`
- `m1.mark(4,-5);`

Tehát az osztálynak tárolnia kell:
- az eredeti sorozatot,
- a felülírt indexekhez tartozó új értékeket.

---

## PART5 – Fájlba mentés

Egészítsd ki a `Sequence` osztályt egy `saveToFile` nevű művelettel.  
Ez a művelet írja fájlba ugyanazt, amit a `print()` is megjelenít:
- először a hosszot,
- utána a sorozat elemeit.

A művelet neve pontosan `saveToFile` legyen.

---

## Megjegyzés

A `main.cpp` mutatja a példányosításokat és a tesztelés módját, a helyes mintát a `minta-stdout.txt` tartalmazza.
