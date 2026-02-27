---
title: Tanulási Útvonalterv
description: C++ tematikája.
---

Összeraktam egy 10 alkalmas tervet, ami egymásra épül. Ha ezeken végigmegyünk, teljesen át fogod látni az alapokat és az Objektumorientált Programozást (OOP) is. Íme a menetrend:

---

### 1. alkalom: A C++ alapjai, fordítás és a memóriamodell
* **A lényeg, amit itt meg kell érteni:** A C++ egy lefordított nyelv. Át kell látnunk, hogyan lesz a szöveges kódunkból futtatható program (előfeldolgozó, fordító, linker). Tisztázzuk azt is, hogy a változó nem csak egy matekos betű, hanem egy konkrét, fizikai hely a memóriában (RAM), aminek címe és mérete van.
* **Amiket átveszünk:**
    * A `main()` függvény, mint a programunk startvonala.
    * Alaptípusok (`int`, `char`, `float`, `double`, `bool`) és hogy mennyi helyet foglalnak.
    * A `sizeof` operátor és az alap be-/kiviteli műveletek (`std::cin`, `std::cout`).
    * Változók memóriacímének lekérdezése az `&` jellel.
* **Feladat / Gyakorlás:** Írj egy programot, ami beolvas adatokat. A kiíratásnál ne csak az értéket, hanem a memóriacímeket (`&`) és a méretet (`sizeof`) is jelenítsd meg! Ebből látni fogod, hogyan sorakoznak a változók a gépben.

### 2. alkalom: Vezérlési szerkezetek és a program futása
* **A lényeg, amit itt meg kell érteni:** A gép alapból sorról sorra olvassa a kódot. A vezérlési szerkezetekkel (if, ciklusok) tudjuk ezt megváltoztatni. Igazából a háttérben logikai igaz/hamis értékek alapján dönt a program, hogy merre ugorjon tovább.
* **Amiket átveszünk:**
    * Elágazások: `if`, `else if`, `else`, `switch`.
    * Ciklusok: `while`, `do-while`, `for`.
    * Logikai (`&&`, `||`, `!`) és relációs operátorok (`==`, `!=`, `<`, `>`).
    * Hatókörök (scope): mit jelentenek a `{}` blokkok, és meddig él egy változó.
* **Feladat / Gyakorlás:** Készíts egy prímtesztelő vagy barkóba (számkitaláló) programot. Itt kénytelen leszel egymásba ágyazni a ciklusokat és a feltételeket, és ki is kell találnod, hogyan lépj ki belőlük jókor.

### 3. alkalom: Függvények és a Call Stack (Hívási verem)
* **A lényeg, amit itt meg kell érteni:** Amikor meghívsz egy függvényt, a memóriában létrejön egy új rekesz (stack frame). A C++ alapból mindent "érték szerint" ad át, ami azt jelenti, hogy lemásolja az adataidat egy új helyre.
* **Amiket átveszünk:**
    * Függvények deklarációja és definíciója (miért jó ezt kettészedni).
    * Paraméterek és visszatérési értékek.
    * Érték szerinti paraméterátadás.
    * A Stack memória automatikus működése.
* **Feladat / Gyakorlás:** Írj egy `swap` függvényt, ami megpróbál felcserélni két számot. Nyomtasd ki a memóriacímeiket a `main`-ben és a csere függvényben is. Látni fogod, miért nem sikerül a csere az eredeti változóknál (mert csak a másolatokkal dolgoztál).

### 4. alkalom: Mutatók (Pointers) és a közvetlen memóriahozzáférés
* **A lényeg, amit itt meg kell érteni:** Ez a vízválasztó. A mutató (pointer) simán csak egy változó, aminek az értéke egy memóriacím. Ez a kulcs ahhoz, hogy átadjunk adatokat másolás nélkül, és közvetlenül belenyúljunk a memóriába.
* **Amiket átveszünk:**
    * Mutatók létrehozása (`int* p;`).
    * A dereferencia operátor (`*p`): hogyan olvassuk ki a memóriacím mögötti adatot.
    * Pointerek inicializálása és a `nullptr`.
    * Cím szerinti paraméterátadás.
* **Feladat / Gyakorlás:** Javítsd meg az előző alkalmon írt `swap` függvényt úgy, hogy most mutatókat kérjen paraméterként. A `*` operátorral már tényleg az eredeti adatokat fogod tudni kicserélni!

### 5. alkalom: Dinamikus memóriakezelés (Heap) és Referenciák
* **A lényeg, amit itt meg kell érteni:** A Stack gyors, de kicsi. A Heap (dinamikus tár) hatalmas, viszont az itt lévő adatok addig élnek, amíg mi le nem töröljük őket. Amit lefoglalsz, azt fel is kell szabadítani, különben jön a memóriaszivárgás (memory leak).
* **Amiket átveszünk:**
    * `new` és `delete` operátorok.
    * Dinamikus tömbök (`new[]` és `delete[]`).
    * Referenciák (`&`), mint a mutatók barátságosabb, biztonságosabb alternatívái.
* **Feladat / Gyakorlás:** Kérj be egy N számot, és foglalj le dinamikusan egy N elemű tömböt a Heap-en. Töltsd fel, csinálj vele valamit, majd szigorúan töröld a `delete[]`-tel! (Próbáld ki egyszer anélkül is, hogy lásd, mi történik).

### 6. alkalom: Több fájlos kódolás és az OOP alapjai
* **A lényeg, amit itt meg kell érteni:** Ha nő a kód, mindent egy `main.cpp`-ben tartani kész öngyilkosság. Az OOP (Objektumorientált Programozás) lényege az "egységbezárás", ami szuperül passzol ehhez: a terveket (interfész) header fájlokba (`.h`), a tényleges kódot forrásfájlokba (`.cpp`) tesszük.
* **Amiket átveszünk:**
    * Header (`.h`) és forrás (`.cpp`) fájlok szétválasztása.
    * Include guardok (`#pragma once`), hogy ne töltsünk be semmit kétszer.
    * Osztályok (`class`): adattagok és függvények egybecsomagolása. `public` és `private` láthatóság.
    * A scope operátor (`::`).
* **Feladat / Gyakorlás:** Hozz létre egy `Henger` osztályt, de szigorúan három fájlra bontva (`Henger.h`, `Henger.cpp`, `main.cpp`). Próbálj meg szándékosan Linker errort előidézni (pl. kihagyni a `.cpp`-t a fordításból), hogy érezd a különbséget a fordító és a szerkesztő között.

### 7. alkalom: Az objektumok élete – Konstruktorok és Destruktorok
* **A lényeg, amit itt meg kell érteni:** Az objektumok megszületnek és meghalnak. A konstruktor felelős azért, hogy egy objektum jól felépítve jöjjön létre. Amikor az objektum ideje lejár (kimegy a scope-ból), a destruktor automatikusan lefut, és eltakarít (pl. törli a dinamikus memóriát).
* **Amiket átveszünk:**
    * Alapértelmezett és paraméteres konstruktorok.
    * Inicializáló lista.
    * Destruktorok (`~Osztalyneve()`).
* **Feladat / Gyakorlás:** Készíts egy saját dinamikus tömb osztályt. A konstruktor foglaljon memóriát a Heap-en, a destruktor pedig hívja meg a `delete[]`-et. Hozz létre egy ilyen objektumot a main-ben egy sima blokkon `{}` belül, és csekkold le a kiíratásokkal, hogy tényleg magától kitakarít-e a blokk végén.

### 8. alkalom: Másolás és a "Hármas Ökölszabály" (Rule of Three)
* **A lényeg, amit itt meg kell érteni:** Ha egy dinamikus memóriát használó objektumot lemásolsz (pl. `a = b`), a C++ alapból csak "sekély" másolatot csinál. Mindkét objektum ugyanoda fog mutatni a memóriában, és a végén kétszer akarják majd letörölni ugyanazt a memóriát (összeomlás). Ezt nekünk kell lekezelni mély másolással (deep copy).
* **Amiket átveszünk:**
    * Sekély vs. Mély másolás.
    * Másoló konstruktor.
    * Másoló értékadás operátor (`operator=`).
    * A Hármas Ökölszabály.
* **Feladat / Gyakorlás:** Az előző órán írt saját tömbödet add át egy függvénynek "érték szerint". Látni fogod, ahogy a program elszáll a dupla törlés miatt. Írd meg a másoló konstruktort, hogy megoldd a problémát!

### 9. alkalom: Öröklődés (Inheritance)
* **A lényeg, amit itt meg kell érteni:** Ne írjuk le kétszer ugyanazt a kódot! Az öröklődéssel meglévő osztályokból tudunk újakat csinálni. Át kell látnunk, hogyan hívódnak meg az ős-konstruktorok, és hogyan néz ki ez az egész a memóriában.
* **Amiket átveszünk:**
    * Alaposztály (Base) és Származtatott osztály (Derived).
    * A `protected` láthatóság (a "gyerek" látja, a külvilág nem).
    * Ős-konstruktorok hívása.
* **Feladat / Gyakorlás:** Csinálj egy `Alkalmazott` ősosztályt (név, fizetés), és abból egy `Menedzser` származtatott osztályt (plusz bónusz adattal). Készíts konstruktorokat, és teszteld, milyen sorrendben futnak le a dolgok.

### 10. alkalom: Polimorfizmus és Virtuális függvények
* **A lényeg, amit itt meg kell érteni:** Ez az OOP csúcsa. Elérjük, hogy egy ősosztály mutatójával kezeljünk különböző leszármazott objektumokat, és a program csak futás közben (dinamikusan) találja ki, kinek a függvényét kell ténylegesen meghívni.
* **Amiket átveszünk:**
    * Dinamikus kötés és a `virtual` kulcsszó.
    * Tisztán virtuális függvények és absztrakt osztályok.
    * Virtuális destruktorok (kötelező, ha nem akarsz memóriaszivárgást!).
* **Feladat / Gyakorlás:** Csinálj egy absztrakt `Alakzat` osztályt, amiből származtass `Teglalap`-ot és `Kor`-t. A main-ben pakold be őket vegyesen egy `Alakzat*` típusú tömbbe, majd egyetlen ciklussal menj végig rajtuk, és írasd ki a területüket. Ne felejtsd el a polimorf törlést a végén!

---
> Ha ezen a 10 alkalmon átrágjuk magunkat, a mutatók, a memória és az OOP többé nem fog gondot okozni. Vágjunk is bele!
