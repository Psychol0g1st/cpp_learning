---
title: C++ 2. KisZH gyakorlócsomag
description: 5 új, automatikusan ellenőrizhető C++ gyakorlófeladatsor a minta 2. KisZH szerkezetében.
---

# C++ 2. KisZH gyakorlócsomag

Ez az oldal 5 darab, a mintafeladat szerkezetét követő gyakorlófeladatsort tartalmaz.  
Mindegyik feladatsor ugyanarra az alapelvre épül:

- van egy kész absztrakt alaposztály,
- a `main.cpp` automatikusan teszteli a megoldást,
- a `megoldott_feladatok.h` fájlban lehet részenként bekapcsolni a feladatokat,
- a `minta-stdout.txt` tartalmazza a helyes mintakimenetet.

A leírások emberi nyelven magyarázzák el a feladatot, de közben pontosan megadják:
- az osztály nevét,
- az öröklés helyét,
- a konstruktor paramétereit,
- a szükséges plusz adatokat,
- az elvárt műveletek nevét.

## Letöltés

- [Teljes gyakorlócsomag letöltése](/cpp_learning/downloads/kiszh_2-gyakorlo-feladatok.zip)

---

# 01 – Fényfestő képek

Ebben a feladatsorban az `Image` absztrakt alaposztályból kell származtatni új osztályokat.  
Az `Image` már tárolja a kép szélességét és magasságát, és tudja a képet kiírni.  
A te dolgod minden feladatnál az, hogy megadd, mely pontok legyenek világosak.

A képen:
- a világos pont `.` karakterként jelenik meg,
- a sötét pont `#` karakterként jelenik meg.

A részeket a `megoldott_feladatok.h` fájlban lehet bekapcsolni.

## PART1 – Kereszt

Készíts egy `Cross` nevű osztályt a `cross.h` és `cross.cpp` fájlokban.  
Az osztály az `Image` osztályból származzon.

Ez az osztály egy fix méretű, 9 széles és 9 magas képet jelenítsen meg.  
A képen egy középre igazított kereszt legyen látható:
- a középső oszlop legyen világos,
- a középső sor legyen világos,
- minden más pont legyen sötét.

A `Cross` osztályhoz nem kell külön új mezőt eltárolni, mert a kép mérete állandó.  
A konstruktora paraméter nélküli legyen, mert a tesztelés így példányosítja.

## PART2 – Háromszög

Készíts egy `Triangle` nevű osztályt a `triangle.h` és `triangle.cpp` fájlokban.  
Az osztály az `Image` osztályból származzon.

Ez az osztály egy lefelé szélesedő, egyenlő szárú háromszöget jelenítsen meg.  
A háromszög:
- egy megadott vízszintes középvonal köré legyen szimmetrikus,
- egy megadott kezdősorból induljon,
- egy megadott zárósorig tartson,
- lefelé haladva minden sorban szélesebb legyen.

A `Triangle` objektum létrehozásakor a konstruktor pontosan 5 egész számot kapjon ebben a sorrendben:

1. a kép szélessége
2. a kép magassága
3. a háromszög vízszintes közepe
4. a háromszög felső sora
5. a háromszög alsó sora

Vagyis az osztálynak az `Image`-ből örökölt szélesség és magasság mellett még tárolnia kell:
- a közép x koordinátát,
- a felső határt,
- az alsó határt.

A tesztelés ilyen példányosításokat használ:
- `Triangle(11,7,5,1,5)`
- `Triangle(9,6,2,0,4)`

## PART3 – Vízszintes tükörkép

Készíts egy `MirrorX` nevű osztályt a `mirrorx.h` és `mirrorx.cpp` fájlokban.  
Az osztály az `Image` osztályból származzon.

Ez az osztály ne saját mintát rajzoljon, hanem egy már meglévő képet jelenítsen meg úgy, hogy azt vízszintesen tükrözi.  
Ez azt jelenti, hogy a bal és jobb oldal felcserélődik.

A konstruktor egyetlen paramétert várjon:
- egy már létező `Image` objektum címét.

Vagyis a konstruktort úgy kell megírni, hogy ilyen hívás működjön:
- `MirrorX(&valamilyenKep)`

Az osztálynak ezért el kell tárolnia egy másik `Image` objektum elérését.  
A kép saját szélessége és magassága egyezzen meg a becsomagolt kép méretével.

## PART4 – Lámpások

Készíts egy `Lanterns` nevű osztályt a `lanterns.h` és `lanterns.cpp` fájlokban.  
Az osztály az `Image` osztályból származzon.

Ez az osztály egy olyan képet reprezentáljon, amelyre több lámpást lehet elhelyezni.  
Minden lámpásnak van:
- x koordinátája,
- y koordinátája,
- hatótávolsága.

A lámpás a saját helyén és a környezetében világos pontokat adjon.  
A fényfolt rácsos, rombuszszerű alakban terjedjen szét.  
Ha egy pontot több lámpás is megvilágít, akkor az természetesen világos marad.

A konstruktor 2 egész számot kapjon ebben a sorrendben:
1. a kép szélessége
2. a kép magassága

Az osztályon belül legyen egy `addLantern` nevű művelet, amely 3 egész számot vár ebben a sorrendben:
1. x koordináta
2. y koordináta
3. hatótáv

A tesztelés ilyen hívásokat használ:
- `Lanterns l1(11,7);`
- `l1.addLantern(2,2,1);`
- `l1.addLantern(8,4,2);`

Tehát az osztálynak a méreten kívül több lámpás adatait is tárolnia kell.

## PART5 – Fájlba mentés

Egészítsd ki az `Image` alaposztályt úgy, hogy legyen benne egy `saveToFile` nevű művelet.

Ez a művelet egy fájlnevet vagy elérési utat kapjon szövegként, és ugyanazt a tartalmat mentse fájlba, amit a `print()` is kiír:
- először a szélességet és a magasságot,
- utána a kép sorait.

A művelet neve pontosan `saveToFile` legyen, mert a teszt ezt hívja.

---

# 02 – Útvonalképek

Ebben a feladatsorban szintén az `Image` absztrakt alaposztályból kell származtatni.  
Az `Image` tárolja a szélességet és a magasságot, és ki tudja írni a képet.  
A te feladatod az, hogy megadd, mely pontok legyenek világosak.

A képen:
- a világos pont `.` karakter,
- a sötét pont `#` karakter.

## PART1 – Belső téglalap

Készíts egy `Border` nevű osztályt a `border.h` és `border.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

A `Border` egy fix méretű, 10 széles és 6 magas képet jelenítsen meg.  
A képen egy belső világos téglalap jelenjen meg úgy, hogy:
- a felső és alsó legkülső sor teljesen sötét,
- a bal és jobb szélen is maradjon sötét szegély,
- belül összefüggő világos terület legyen.

A konstruktora paraméter nélküli legyen.  
Ehhez az osztályhoz nem kell külön plusz mezőt tárolni.

## PART2 – Rombusz

Készíts egy `Diamond` nevű osztályt a `diamond.h` és `diamond.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály egy rombuszt jelenítsen meg.  
A rombusz:
- egy megadott középpont köré szerveződjön,
- felfelé és lefelé csúcsosodjon,
- középen legyen a legszélesebb.

A konstruktor 5 egész számot várjon ebben a sorrendben:
1. a kép szélessége
2. a kép magassága
3. a rombusz középpontjának x koordinátája
4. a rombusz középpontjának y koordinátája
5. a rombusz mérete vagy sugara

A tesztelés ilyen példákat használ:
- `Diamond(11,7,5,3,3)`
- `Diamond(9,6,2,2,2)`

Tehát az osztálynak az `Image`-ből örökölt adatokon kívül tárolnia kell:
- a középpont helyét,
- a méretet.

## PART3 – Negatív kép

Készíts egy `Negative` nevű osztályt a `negative.h` és `negative.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály egy meglévő kép negatívját jelenítse meg:
- ami az eredeti képen világos, itt legyen sötét,
- ami az eredetin sötét, itt legyen világos.

A konstruktor egyetlen paramétert várjon:
- egy meglévő `Image` objektum címét.

A tesztelés ilyen formában használja:
- `Negative(&valamilyenKep)`

Az osztálynak ezért el kell tárolnia a becsomagolt képet.

## PART4 – Törött vonal

Készíts egy `PathImage` nevű osztályt a `pathimage.h` és `pathimage.cpp` fájlokban.  
Az osztály az `Image`-ből származzon.

Ez az osztály egy olyan képet kezeljen, amelyre pontokat lehet egymás után felvenni, és ezek között útvonal jelenik meg.

A működés:
- a pontokat felvételi sorrendben kell összekötni,
- két egymást követő pont között csak vízszintes vagy függőleges szakasz lesz,
- nem csak a megadott pontok, hanem a köztük lévő pontok is világosak legyenek.

A konstruktor 2 egész számot kapjon:
1. szélesség
2. magasság

Az osztályon belül legyen egy `addPoint` nevű művelet, amely 2 egész számot vár:
1. x koordináta
2. y koordináta

A teszt ilyen hívásokat használ:
- `PathImage p1(11,7);`
- `p1.addPoint(1,1);`
- `p1.addPoint(6,1);`
- `p1.addPoint(6,4);`
- `p1.addPoint(3,4);`

Tehát az osztálynak tárolnia kell a felvett pontok listáját.

## PART5 – Fájlba mentés

Egészítsd ki az `Image` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a tartalmat mentse fájlba, amit a `print()` a konzolra kiír:
- először a méretet,
- utána a kép sorait.

A név pontosan `saveToFile` legyen.

---

# 03 – Sorozatlabor

Ebben a feladatsorban nem képet, hanem számsorozatot kell megvalósítani.  
Az alapkód egy `Sequence` nevű absztrakt alaposztályt ad.

A `Sequence`:
- tárolja a sorozat hosszát,
- ki tudja írni a sorozat elemeit,
- de azt neked kell megadni, hogy egy adott indexen milyen érték van.

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

## PART5 – Fájlba mentés

Egészítsd ki a `Sequence` osztályt egy `saveToFile` nevű művelettel.  
Ez a művelet írja fájlba ugyanazt, amit a `print()` is megjelenít:
- először a hosszot,
- utána a sorozat elemeit.

A művelet neve pontosan `saveToFile` legyen.

---

# 04 – ASCII-plakát

Ebben a feladatsorban egy `Canvas` nevű absztrakt alaposztályból kell származtatni.  
A `Canvas`:
- szélességet és magasságot tárol,
- ki tudja írni a vásznat,
- egy adott pozícióhoz egy karaktert vár vissza.

Az üres helyet `.` karakter jelzi.

## PART1 – Keret

Készíts egy `Frame` nevű osztályt a `frame.h` és `frame.cpp` fájlokban.  
Az osztály a `Canvas` osztályból származzon.

A `Frame` egy fix méretű, 9 széles és 5 magas vásznat jelenítsen meg.  
A széleken `*` karakterből álló keret legyen, belül minden maradjon üres, vagyis `.`.

A konstruktora paraméter nélküli legyen.

## PART2 – Lépcső

Készíts egy `Stairs` nevű osztályt a `stairs.h` és `stairs.cpp` fájlokban.  
Az osztály a `Canvas` osztályból származzon.

Ez az osztály bal felülről induló, lépcsősen növekvő mintát rajzoljon `#` karakterből:
- az első sorban 1 darab `#`,
- a második sorban 2 darab,
- a harmadik sorban 3 darab,
- és így tovább.

A többi helyen `.` legyen.

A konstruktor 2 egész számot kapjon:
1. szélesség
2. magasság

A tesztelés ilyen hívásokat használ:
- `Stairs(8,5)`
- `Stairs(10,6)`

Ehhez nem kell sok plusz adatot eltárolni, csak a méretet.

## PART3 – Egymásra helyezés

Készíts egy `Overlay` nevű osztályt az `overlay.h` és `overlay.cpp` fájlokban.  
Az osztály a `Canvas` osztályból származzon.

Ez az osztály két meglévő vásznat egyesítsen:
- legyen egy alsó vászon,
- legyen egy felső vászon,
- ha a felső vászon adott pozícióban nem üres, akkor az látszódjon,
- különben az alsó vászon karaktere maradjon.

A konstruktor 2 paramétert várjon:
1. az alsó `Canvas` objektum címe
2. a felső `Canvas` objektum címe

A teszt ilyen formában használja:
- `Overlay(&also,&felso)`

Az osztálynak tehát két másik vászonra kell hivatkoznia.

## PART4 – Feliratok

Készíts egy `Labels` nevű osztályt a `labels.h` és `labels.cpp` fájlokban.  
Az osztály a `Canvas` osztályból származzon.

Ez az osztály alapból üres vásznat kezeljen, de különböző helyekre karaktereket lehessen elhelyezni.

A konstruktor 2 egész számot kapjon:
1. szélesség
2. magasság

Az osztályban legyen egy `addLabel` nevű művelet, amely 3 paramétert vár:
1. x koordináta
2. y koordináta
3. a kirakandó karakter

A teszt ilyen hívásokat használ:
- `l1.addLabel(1,1,'A');`
- `l1.addLabel(4,2,'B');`

Tehát az osztálynak tárolnia kell:
- a feliratok helyét,
- a hozzájuk tartozó karaktert.

## PART5 – Fájlba mentés

Egészítsd ki a `Canvas` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a formátumot mentse, mint amit a `print()` kiír:
- először a szélesség és magasság,
- utána a vászon sorai.

A név pontosan `saveToFile` legyen.

---

# 05 – Alakzatgyártó

Ebben a feladatsorban ismét az `Image` absztrakt alaposztályból kell kiindulni.  
Az `Image` tárolja a szélességet és a magasságot, és ki tudja írni a képet.

A világos pont `.` karakterrel, a sötét pont `#` karakterrel jelenik meg.

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

## PART5 – Fájlba mentés

Egészítsd ki az `Image` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a tartalmat mentse fájlba, amit a `print()` is kiír:
- először a szélesség és magasság,
- utána a kép sorai.

A művelet neve pontosan `saveToFile` legyen.
