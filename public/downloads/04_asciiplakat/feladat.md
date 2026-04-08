# 04 – ASCII-plakát

Ebben a feladatsorban egy `Canvas` nevű absztrakt alaposztályból kell származtatni.  
A `Canvas`:
- szélességet és magasságot tárol,
- ki tudja írni a vásznat,
- egy adott pozícióhoz egy karaktert vár vissza.

Az üres helyet `.` karakter jelzi.

---

## PART1 – Keret

Készíts egy `Frame` nevű osztályt a `frame.h` és `frame.cpp` fájlokban.  
Az osztály a `Canvas` osztályból származzon.

A `Frame` egy fix méretű, 9 széles és 5 magas vásznat jelenítsen meg.  
A széleken `*` karakterből álló keret legyen, belül minden maradjon üres, vagyis `.`.

A konstruktora paraméter nélküli legyen.

---

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

---

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

---

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

---

## PART5 – Fájlba mentés

Egészítsd ki a `Canvas` osztályt egy `saveToFile` nevű művelettel.  
Ez ugyanazt a formátumot mentse, mint amit a `print()` kiír:
- először a szélesség és magasság,
- utána a vászon sorai.

A név pontosan `saveToFile` legyen.

---

## Megjegyzés

A pontos tesztelést a `main.cpp`, az elvárt eredményt a `minta-stdout.txt` mutatja.
