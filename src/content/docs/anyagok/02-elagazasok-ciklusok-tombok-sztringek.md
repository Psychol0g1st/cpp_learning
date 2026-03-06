---
title: 02. Vezérlési szerkezetek, tömbök és sztringek
description: Hogyan tanítsuk meg a gépet dönteni, ismételni, és sok adatot kezelni?
---

Üdv újra itt! Az első alkalmon megértettük, hogy a kódunk hogyan válik futtatható programmá, és hogy a változóink valójában fizikai memóriaterületek.

Ma egy hatalmas lépést teszünk előre. Megtanuljuk, hogyan törjük meg a program fentről lefelé haladó, unalmas végrehajtását elágazásokkal (döntésekkel) és ciklusokkal (ismétlésekkel). Azt is megnézzük, hogyan tudunk sok egyforma adatot hatékonyan tárolni tömbökben, és hogyan kezeljük a szövegeket. Kezdjük is el!

---

### 1. Elágazások (Amikor a program dönt)

**A koncepció:** A processzor (CPU) alapból sorról sorra halad. Az elágazásokkal "intelligenciát" adunk a programnak: logikai (igaz/hamis, azaz boolean) feltételek alapján a program dönthet úgy, hogy bizonyos kódrészleteket átugrik, vagy más irányba megy tovább.

#### Az `if - else if - else` szerkezet
Ez a leggyakoribb döntési eszközünk.

* Az `if` (ha) blokk csak akkor fut le, ha a benne lévő feltétel `true` (igaz).
* Az `else if` (különben ha) újabb feltételt vizsgál, ha az előző hamis volt. Ebből akárhányat írhatsz egymás után.
* Az `else` (különben) blokk a "maradék", akkor fut le, ha a fentiek közül *egyik sem* teljesült.

```cpp
int sebesseg = 65;

if (sebesseg > 130) {
    cout << "Elveszik a jogositvanyt!" << endl;
} else if (sebesseg > 50) {
    cout << "Gyorshajtas, buntetes jar erte." << endl;
} else {
    cout << "Minden rendben, kivalo tempo." << endl;
}

```

> **A leggyakoribb kezdő hiba!** A C++-ban a logikai egyenlőség vizsgálata **két** egyenlőségjellel (`==`) történik (pl. `if (a == 5)`). Az egyetlen egyenlőségjel (`=`) értékadást jelent. Ha véletlenül azt írod, hogy `if (a = 5)`, a gép bele fogja rakni az 5-öt az `a`-ba, és az eredmény mindig "igaz" lesz. Óriási szívás megtalálni ezt a hibát, szóval figyelj rá!

#### A `switch` utasítás

Ha egyetlen konkrét változó értékét (pl. egy menüpont számát) akarod sok konkrét esettel összehasonlítani, a `switch` sokkal átláthatóbb, mint egy kilométer hosszú `else if` láncolat.

```cpp
int menupont = 2;

switch (menupont) {
    case 1:
        cout << "Jatek inditasa" << endl;
        break; 
    case 2:
        cout << "Beallitasok" << endl;
        break; // KÖTELEZŐ! Enélkül a program "rácsorog" a következő case-re!
    default: // Ez az 'else' megfelelője: ha egyik case sem egyezik
        cout << "Ervenytelen valasztas" << endl;
        break;
}

```

**Miért kell a `break`?** A switch a háttérben egy memóriacímre való "ugrás" (jump). Odaugrik a megfelelő `case`-hez, és elkezdi végrehajtani a kódot. A `break` mondja meg neki, hogy "oké, végeztünk, lépj ki a switch blokkból". Ha lehagyod a `break`-et a 2. esetnél, a gép simán lefuttatja a `default` ágat is!

---

### 2. Ciklusok (Amikor a gép ismétel)

**A koncepció:** A számítógépek abban a legjobbak, hogy unalmas, monoton feladatokat végezzenek el irdatlan sebességgel. A ciklusokkal utasítjuk a gépet, hogy egy kódblokkot addig ismételjen, amíg egy feltétel igaz.

#### A `while` és a `do-while` ciklus

* A **`while` (elöltesztelő)** először megvizsgálja a feltételt. Ha igaz, lefuttatja a kódot. Ha a feltétel eleve hamis, a ciklus *egyszer sem* fut le.
* A **`do-while` (hátultesztelő)** először mindenképp lefuttatja a kódot egyszer, és *csak utána* nézi meg a feltételt.

Nézzük meg mindkettőt működés közben!

```cpp
// while példa: Várjuk a jó jelszót. Ha elsőre rossz, kérjük újra.
int probalkozas = 0;
while (probalkozas < 3) {
    cout << "while iteracio: " << probalkozas << endl;
    probalkozas++; // Ne felejtsük el növelni, különben VÉGTELEN ciklust kapunk!
}

// do-while példa: Menüpont bekérése. Egyszer mindenképp ki kell írni a menüt!
int valasztas;
do {
    cout << "Nyomj 1-est a kilepeshez: ";
    cin >> valasztas;
} while (valasztas != 1); 
// Figyeld meg a pontosvesszőt a while vége után! Ez itt kötelező.

```

#### A `for` ciklus (A mérnökök kedvence)

A `for` ciklus azért zseniális, mert egyetlen sorba tömöríti a ciklus három alappillérét: a **kezdőértéket**, a **futási feltételt**, és a **léptetést**. Legtöbbször akkor használjuk, ha pontosan tudjuk, hányszor akarunk ismételni valamit.

```cpp
// for (1. inicializálás; 2. feltétel; 3. léptetés)
for (int i = 0; i < 5; i++) {
    cout << "A ciklusvaltozo erteke: " << i << endl;
}

```

És mi van, ha **visszafelé** akarunk számolni? Simán megfordítjuk a logikát! Beállítjuk a kezdőt 10-re, addig megyünk, amíg nagyobb mint nulla, és minden körben levonunk egyet (`i--`):

```cpp
for (int i = 10; i > 0; i--) {
    cout << "Visszaszamlalas: " << i << endl;
}
cout << "Kiloves!" << endl;

```

---

### 3. Tömbök (Adatok csoportosítása)

**A koncepció:** Tegyük fel, hogy 5 diák vizsgaeredményét kell tárolnunk. Nem hozhatunk létre `jegy1`, `jegy2` ... `jegy5` nevű változókat. Helyette kérünk a memóriától egy egybefüggő blokkot, ami pontosan 5 darab egész számot képes tárolni egymás mellett. Ez a tömb (array).

```cpp
// Létrehozunk egy 5 elemű, egészeket tároló tömböt, és rögtön feltöltjük:
int jegyek[5] = {5, 4, 3, 5, 2};

// A harmadik diák jegyének kiíratása (ami a 2-es index!)
cout << "A harmadik diak jegye: " << jegyek[2] << endl;

```

> **A legfontosabb alapszabály:** C++-ban az indexelés (a sorszámozás) mindig **0-tól indul!** Miért? Mert ahogy múltkor beszéltük, a változók fizikai helyek a memóriában. Az index valójában egy "eltolást" (offset) jelent a memóriában. A `jegyek[2]` azt jelenti a gépnek: menj a tömb kezdőcímére (0. elem), és ugorj előre 2 darab memóriarekeszt.

**Veszélyzóna!** A C++ a sebesség maximalizálása érdekében *nem ellenőrzi*, hogy túlléptél-e a tömb határán. Ha egy 5 elemű tömbnél a `jegyek[100]` értékét akarod módosítani, a program szó nélkül megteszi, felülírva ezzel a gép memóriájában valami teljesen más adatot. Ebből lesznek az összeomlások (segfault) vagy a komoly biztonsági rések.

A tömböket leggyakrabban egy `for` ciklussal szoktuk bejárni:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << ". indexu elem: " << jegyek[i] << endl;
}

```

---

### 4. Sztringek (Szövegek kezelése)

**A koncepció:** A szöveg a gép számára nem más, mint egymás után következő betűk (karakterek) sorozata, vagyis igazából egy karaktertömb.

A "régi C" stílusban így is kezelték a szöveget, de ez rengeteg memóriahibához vezetett. Szerencsére a modern C++-ban van egy okos beépített típusunk, az `std::string`. Ez egy "dobozolt" szöveg, ami okosan kezeli a saját memóriáját: magától képes nőni vagy zsugorodni.

A használatához be kell emelned a `<string>` könyvtárat a kód tetején!

```cpp
#include <iostream>
#include <string> // Ezt ne felejtsd el!
using namespace std;

int main() {
    string vezeteknev = "Kovacs";
    string keresztnev = "Bela";

    // Sztringek összefűzése sima + jellel:
    string teljesnev = vezeteknev + " " + keresztnev;

    cout << "Udvozollek, " << teljesnev << "!" << endl;

    // A string meg tudja mondani a saját hosszát (hany betűből áll):
    cout << "A neved " << teljesnev.length() << " karakterbol all." << endl;

    return 0;
}

```

C++-ban alapvetően **kétféleképpen** tudsz szöveget (stringet) beolvasni a konzolról, attól függően, hogy pontosan mit is szeretnél:

### 5. Csak egyetlen szót akarok (szóközig)

Ha mondjuk csak egy keresztnevet kérsz be, a sima `cin >>` tökéletes. Ennek az a trükkje, hogy addig olvas, amíg az első szóközbe (vagy enterbe) bele nem ütközik.

```cpp
#include <iostream>
#include <string> // Ne felejtsd el beemelni!
using namespace std;

int main() {
    string nev;
    cout << "Hogy hivnak (csak a keresztneved)? ";
    cin >> nev; // Ha beírod, hogy "Kovacs Peter", ide csak a "Kovacs" kerül!
    
    cout << "Szia, " << nev << "!" << endl;
    return 0;
}

```

### 6. Egy egész sort akarok (szóközökkel együtt)

Ha egy teljes nevet (pl. "Kovács Péter") vagy egy egész mondatot akarsz beolvasni, a `cin >>` cserbenhagy, mert a szóköz utáni részt levágja. Ilyenkor a `getline()` függvényt kell használnunk. Ez beolvas mindent, egészen addig, amíg le nem nyomod az Entert.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string teljes_nev;
    cout << "Mi a teljes neved? ";
    
    getline(cin, teljes_nev); // Ez hiba nélkül beolvassa a szóközöket is
    
    cout << "Szia, " << teljes_nev << "!" << endl;
    return 0;
}

```

---

### ⚠️ A tipikus csapda: A kettő keverése!

Ha egy programon belül először használsz egy `cin >>` beolvasást (mondjuk bekérsz egy számot, korábban bemutatott módon), és *utána* akarsz egy `getline()`-t használni, a `getline` látszólag "átugrik", lefut anélkül, hogy hagyná begépelni a szöveget.

**Mi történik a motorháztető alatt?** Amikor begépeled a számot és ütsz egy Entert, a `cin` a számot szépen kiveszi és beteszi a változóba, de magát az "Entert" (a sortörés karaktert, `\n`) bent felejti a bemeneti memóriában (a pufferben). Amikor a `getline` sorra kerül, benéz a pufferbe, rögtön meglátja ezt a bent ragadt Entert, és azt hiszi: *"Szuper, a felhasználó már ütött is egy entert, üres stringet adok vissza!"*

**A megoldás:** A kettő közé be kell szúrni egy `cin.ignore();` parancsot, ami kipucolja a bent ragadt Entert:

```cpp
int eletkor;
string nev;

cout << "Hany eves vagy? ";
cin >> eletkor;

cin.ignore(); // <--- EZ MENTI MEG A NAPOT! Kitakarítja a pufferből a bent ragadt Entert.

cout << "Mi a teljes neved? ";
getline(cin, nev); // Így már hajlandó lesz megvárni, amíg beírod a nevet!

```

---

### 📝 Gyakorlat: A "Hőmérséklet-elemző Állomás"

A mai elméletet egy klasszikus, menüvezérelt programmal fogjuk összefűzni. Ez a feladat rákényszerít, hogy a ciklusokat, az elágazásokat és a tömböket egyetlen működő rendszerré dolgozd össze.

Pontosan így működik szinte minden interaktív szoftver a háttérben: van egy fő ciklus (game loop), ami a végtelenségig fut, várja a bemenetet, döntést hoz, és adatokat dolgoz fel a memóriában, egészen addig, amíg ki nem lépsz belőle.

**A feladat lépései:**

1. Hozz létre egy 7 elemű `double` tömböt, amely egy hét napi átlaghőmérsékleteit tárolja. Töltsd fel kezdőértékekkel (pl. `{12.5, 14.0, 11.2, ...}`).
2. Csinálj egy végtelenített `while` (vagy `do-while`) ciklust, ami kiír egy menüt:
* 1: Hőmérsékletek listázása
* 2: Átlaghőmérséklet kiszámítása
* 3: Legmelegebb nap (maximum keresés)
* 4: Kilépés


3. Olvasd be a választást egy változóba.
4. Használj egy `switch` szerkezetet a menüpontok lekezelésére!
* Az **1. esetben** egy `for` ciklussal írasd ki a tömb elemeit.
* A **2. esetben** egy `for` ciklussal add össze a tömb elemeit egy változóba, oszd el 7-tel, és írd ki az eredményt.
* A **3. esetben** (ez a legnehezebb!) egy `for` ciklussal és egy `if` feltétellel keresd meg a tömb legnagyobb elemét. *(Tipp: csinálj egy `max` változót, állítsd be a tömb 0. elemére, majd a ciklusban vizsgáld meg, hogy a soron következő elem nagyobb-e a `max`-nál. Ha igen, írd felül a `max` értékét!)*
* A **4. esetben** oldd meg, hogy a program kilépjen a `while` ciklusból. (Használhatsz egy `bool fut_a_program = true` változót, amit itt `false`-ra állítasz).
