# 02 – Útvonalképek

Ebben a feladatsorban szintén az `Image` absztrakt alaposztályból kell származtatni.  
Az `Image` tárolja a szélességet és a magasságot, és ki tudja írni a képet.  
A te feladatod az, hogy megadd, mely pontok legyenek világosak.

A képen:
- a világos pont `.` karakter,
- a sötét pont `#` karakter.

---

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

---

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

---

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

---

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

---

## PART5 – Fájlba mentés

Egészítsd ki az `Image` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a tartalmat mentse fájlba, amit a `print()` a konzolra kiír:
- először a méretet,
- utána a kép sorait.

A név pontosan `saveToFile` legyen.

---

## Megjegyzés

A pontos tesztelést a `main.cpp` mutatja, az elvárt kimenetet a `minta-stdout.txt` tartalmazza.
