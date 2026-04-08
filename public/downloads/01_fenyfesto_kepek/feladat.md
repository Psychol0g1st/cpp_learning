# 01 – Fényfestő képek

Ebben a feladatsorban az `Image` absztrakt alaposztályból kell származtatni új osztályokat.  
Az `Image` már tárolja a kép szélességét és magasságát, és tudja a képet kiírni.  
A te dolgod minden feladatnál az, hogy megadd, mely pontok legyenek világosak.

A képen:
- a világos pont `.` karakterként jelenik meg,
- a sötét pont `#` karakterként jelenik meg.

A részeket a `megoldott_feladatok.h` fájlban lehet bekapcsolni.

---

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

---

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

---

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

---

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

---

## PART5 – Fájlba mentés

Egészítsd ki az `Image` alaposztályt úgy, hogy legyen benne egy `saveToFile` nevű művelet.

Ez a művelet egy fájlnevet vagy elérési utat kapjon szövegként, és ugyanazt a tartalmat mentse fájlba, amit a `print()` is kiír:
- először a szélességet és a magasságot,
- utána a kép sorait.

A művelet neve pontosan `saveToFile` legyen, mert a teszt ezt hívja.

---

## Megjegyzés

A `main.cpp` mutatja, hogyan történik a tesztelés.  
A helyes mintakimenetet a `minta-stdout.txt` fájlban találod.
