---
title: 03. Gyakorló 1. KisZH feladatsorok
description: Öt darab, automatikusan ellenőrizhető gyakorló KisZH feladatsor C++ Programozás 2 kurzushoz.
---

Ez az oldal 5 darab, a mintához hasonló felépítésű gyakorló KisZH feladatsort tartalmaz. 
Minden feladathoz tartozik kiinduló alapkód, `main.cpp` alapú automatikus ellenőrzés, valamint mintakimenet.

## Letöltés

A teljes gyakorló csomag innen tölthető le:

**[Gyakorló KisZH csomag letöltése (ZIP)](/cpp_learning/downloads/cpp2_kiszh_gyakorlo_5csomag.zip)**

## Tartalom

- [1. GradedCourse](#1-gradedcourse)
- [2. SmartRoute](#2-smartroute)
- [3. LeagueTeam](#3-leagueteam)
- [4. WeatherArchive](#4-weatherarchive)
- [5. ParcelDay](#5-parcelday)

---

## 1. GradedCourse

### FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket, figyelj a konstansok és referenciák megfelelő használatára.
- A megadott példakódon ne módosíts, hacsak a feladat nem kéri. A megoldásnak ugyanezekkel a fájlokkal kell működnie.
- Figyelj a kiírás megfelelő formátumára, szóközökre, sortörésekre.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- Minden pont értékeléshez szükséges, hogy az adott ponthoz tartozó define szerepeljen a `megoldott_feladatok.h` fájlban.
- A header fájlokban csak a header guard-on belülre dolgozz.
- Csak olyan kódot adj be / használj gyakorláshoz, ami nálad fordul.
- A példakimenet a `main.cpp`-ben lévő tesztek alapján a `minta-stdout.txt` fájlban is megtalálható.
- Ellenőrzéshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

### Feladat

- A `#define PART<X>` direktívák a `megoldott_feladatok.h` fájlban szerepeljenek.
- A feladatok között lehet függőség, egymásra épülés.
- A beadandó / létrehozandó fájlok: `gradedcourse.h` és `gradedcourse.cpp`, valamint a `megoldott_feladatok.h`.

Adott a `Course` osztály, amely egy egyetemi kurzust reprezentál, tárolja a kurzus nevét (`string`) és kreditjeinek számát (`int`), pár alapvető függvénnyel. A feladat a kurzusok mellé a pontszámokat tárolni. A `Grade` osztály reprezentál egy-egy pontszámot és rövid megjegyzést, amiből a feladat szempontjából a pontszám (`getPoints`) lesz érdekes.

A `Course` és `Grade` osztályok kódja nem módosítható.

1. Legyen egy `GradedCourse` osztály a `Course` osztályból származtatva. Konstruktorban három paramétert vár: a kurzus nevén (`string`) és kreditjein (`int`) kívül a tárolt értékelések darabszámát (`int`). Ennyi darab `Grade` objektumot kell tárolni egy dinamikus tömbben, ügyelve később a felszabadításra. **(2 pont)**  
   A feladat kötelező, enélkül a későbbi tesztkódok nem fognak működni.
2. Legyen egy `setGrade` metódus a `GradedCourse` osztályban, ami paraméterben egy indexet és egy `Grade`-et kap. Tárolja el az adott `Grade`-et a tömb megadott indexű helyén. Az index érvényességét nem kell ellenőrizni. **(1 pont)**
3. Legyen a `print` metódus a `GradedCourse` osztályban felülírva. A kurzus neve és kreditje mellett írja ki soronként a pontszámokat a megadott formátumban. Egy-egy `Grade` kiírásához használható a `Grade` osztály saját `print` metódusa. **(2 pont)**
4. Legyen egy `getAveragePoints` metódus a `GradedCourse` osztályban, ami visszaadja a tárolt `Grade`-ek alapján a kurzus átlagpontszámát (`double`). Feltételezhetjük, hogy van legalább egy `Grade`. **(2 pont)**
5. Legyen egy statikus `double` adattag a `GradedCourse` osztályban, amivel egy „minimum átmenő pontszám” állítható be. Kezdeti értéke legyen `60.0`, és a `getPassLimit` valamint `setPassLimit` statikus metódusokkal lehessen lekérdezni és beállítani. **(1 pont)**
6. Legyen egy `isPassed` metódus a `GradedCourse` osztályban, ami visszaadja, hogy a kurzus átlagpontszáma eléri-e a minimumot (`bool`). Ez akkor teljesül, ha az adott kurzus átlagpontszáma legalább akkora, mint az előző feladatban említett minimum. **(1 pont)**
7. Legyen a `GradedCourse` osztály egy `AcademicTools` nevű névtérben. **(1 pont)**

---

## 2. SmartRoute

### FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket, figyelj a konstansok és referenciák megfelelő használatára.
- A megadott példakódon ne módosíts, hacsak a feladat nem kéri. A megoldásnak ugyanezekkel a fájlokkal kell működnie.
- Figyelj a kiírás megfelelő formátumára, szóközökre, sortörésekre.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- Minden pont értékeléshez szükséges, hogy az adott ponthoz tartozó define szerepeljen a `megoldott_feladatok.h` fájlban.
- A header fájlokban csak a header guard-on belülre dolgozz.
- Csak olyan kódot adj be / használj gyakorláshoz, ami nálad fordul.
- A példakimenet a `main.cpp`-ben lévő tesztek alapján a `minta-stdout.txt` fájlban is megtalálható.
- Ellenőrzéshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

### Feladat

- A `#define PART<X>` direktívák a `megoldott_feladatok.h` fájlban szerepeljenek.
- A feladatok között lehet függőség, egymásra épülés.
- A beadandó / létrehozandó fájlok: `smartroute.h` és `smartroute.cpp`, valamint a `megoldott_feladatok.h`.

Adott a `Route` osztály, amely egy útvonalat reprezentál, tárolja az indulás (`string`) és az érkezés (`string`) helyet, pár alapvető függvénnyel. A feladat az útvonalhoz részszakaszokat tárolni. A `Checkpoint` osztály reprezentál egy-egy szakaszt, tárolja annak hosszát kilométerben (`double`) és az ahhoz tartozó menetidőt percben (`int`).

A `Route` és `Checkpoint` osztályok kódja nem módosítható.

1. Legyen egy `SmartRoute` osztály a `Route` osztályból származtatva. Konstruktorban három paramétert vár: az indulási és érkezési helyen kívül a szakaszok darabszámát (`int`). Ennyi darab `Checkpoint` objektumot kell tárolni egy dinamikus tömbben, ügyelve később a felszabadításra. **(2 pont)**  
   A feladat kötelező, enélkül a későbbi tesztkódok nem fognak működni.
2. Legyen egy `setCheckpoint` metódus a `SmartRoute` osztályban, ami paraméterben egy indexet és egy `Checkpoint`-ot kap. Tárolja el az adott objektumot a tömb megadott indexű helyén. Az index érvényességét nem kell ellenőrizni. **(1 pont)**
3. Legyen a `print` metódus a `SmartRoute` osztályban felülírva. Az útvonal alapadatain kívül írja ki soronként a szakaszokat a megadott formátumban. Egy-egy `Checkpoint` kiírásához használható a `Checkpoint` osztály saját `print` metódusa. **(2 pont)**
4. Legyen egy `getAverageSpeed` metódus a `SmartRoute` osztályban, ami visszaadja a teljes útvonal átlagsebességét km/h egységben (`double`), a tárolt szakaszok alapján. Feltételezhetjük, hogy a teljes menetidő pozitív. **(2 pont)**
5. Legyen egy statikus `double` adattag a `SmartRoute` osztályban, amivel egy „ajánlott minimális átlagsebesség” állítható be. Kezdeti értéke legyen `55.0`, és a `getMinimumRecommendedSpeed` valamint `setMinimumRecommendedSpeed` statikus metódusokkal lehessen lekérdezni és beállítani. **(1 pont)**
6. Legyen egy `isFastEnough` metódus a `SmartRoute` osztályban, ami visszaadja, hogy az adott útvonal átlaga eléri-e a minimumot (`bool`). **(1 pont)**
7. Legyen a `SmartRoute` osztály egy `NavigationTools` nevű névtérben. **(1 pont)**

---

## 3. LeagueTeam

### FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket, figyelj a konstansok és referenciák megfelelő használatára.
- A megadott példakódon ne módosíts, hacsak a feladat nem kéri. A megoldásnak ugyanezekkel a fájlokkal kell működnie.
- Figyelj a kiírás megfelelő formátumára, szóközökre, sortörésekre.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- Minden pont értékeléshez szükséges, hogy az adott ponthoz tartozó define szerepeljen a `megoldott_feladatok.h` fájlban.
- A header fájlokban csak a header guard-on belülre dolgozz.
- Csak olyan kódot adj be / használj gyakorláshoz, ami nálad fordul.
- A példakimenet a `main.cpp`-ben lévő tesztek alapján a `minta-stdout.txt` fájlban is megtalálható.
- Ellenőrzéshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

### Feladat

- A `#define PART<X>` direktívák a `megoldott_feladatok.h` fájlban szerepeljenek.
- A feladatok között lehet függőség, egymásra épülés.
- A beadandó / létrehozandó fájlok: `leagueteam.h` és `leagueteam.cpp`, valamint a `megoldott_feladatok.h`.

Adott a `Team` osztály, amely egy sportcsapatot reprezentál, tárolja a csapat nevét (`string`) és városát (`string`), pár alapvető függvénnyel. A feladat a csapat mellé meccseredményeket tárolni. A `MatchResult` osztály reprezentál egy-egy eredményt, amelyben a lőtt és kapott gólok száma szerepel.

A `Team` és `MatchResult` osztályok kódja nem módosítható.

1. Legyen egy `LeagueTeam` osztály a `Team` osztályból származtatva. Konstruktorban három paramétert vár: a csapat nevén és városán kívül az eredmények darabszámát (`int`). Ennyi darab `MatchResult` objektumot kell tárolni egy dinamikus tömbben, ügyelve később a felszabadításra. **(2 pont)**  
   A feladat kötelező, enélkül a későbbi tesztkódok nem fognak működni.
2. Legyen egy `setResult` metódus a `LeagueTeam` osztályban, ami paraméterben egy indexet és egy `MatchResult`-ot kap. Tárolja el az adott objektumot a tömb megadott indexű helyén. Az index érvényességét nem kell ellenőrizni. **(1 pont)**
3. Legyen a `print` metódus a `LeagueTeam` osztályban felülírva. A csapat adatain kívül írja ki soronként a meccseredményeket a megadott formátumban. Egy-egy `MatchResult` kiírásához használható a `MatchResult` osztály saját `print` metódusa. **(2 pont)**
4. Legyen egy `getAveragePoints` metódus a `LeagueTeam` osztályban, ami visszaadja a csapat átlagosan szerzett bajnoki pontjait (`double`) a tárolt eredmények alapján. Győzelemért 3 pont, döntetlenért 1 pont, vereségért 0 pont jár. Feltételezhetjük, hogy van legalább egy eredmény. **(2 pont)**
5. Legyen egy statikus `double` adattag a `LeagueTeam` osztályban, amivel egy „rájátszást érő minimum átlagpont” állítható be. Kezdeti értéke legyen `1.8`, és a `getPlayoffLevel` valamint `setPlayoffLevel` statikus metódusokkal lehessen lekérdezni és beállítani. **(1 pont)**
6. Legyen egy `isPlayoffReady` metódus a `LeagueTeam` osztályban, ami visszaadja, hogy az adott csapat átlaga eléri-e a minimumot (`bool`). **(1 pont)**
7. Legyen a `LeagueTeam` osztály egy `LeagueStats` nevű névtérben. **(1 pont)**

---

## 4. WeatherArchive

### FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket, figyelj a konstansok és referenciák megfelelő használatára.
- A megadott példakódon ne módosíts, hacsak a feladat nem kéri. A megoldásnak ugyanezekkel a fájlokkal kell működnie.
- Figyelj a kiírás megfelelő formátumára, szóközökre, sortörésekre.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- Minden pont értékeléshez szükséges, hogy az adott ponthoz tartozó define szerepeljen a `megoldott_feladatok.h` fájlban.
- A header fájlokban csak a header guard-on belülre dolgozz.
- Csak olyan kódot adj be / használj gyakorláshoz, ami nálad fordul.
- A példakimenet a `main.cpp`-ben lévő tesztek alapján a `minta-stdout.txt` fájlban is megtalálható.
- Ellenőrzéshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

### Feladat

- A `#define PART<X>` direktívák a `megoldott_feladatok.h` fájlban szerepeljenek.
- A feladatok között lehet függőség, egymásra épülés.
- A beadandó / létrehozandó fájlok: `weatherarchive.h` és `weatherarchive.cpp`, valamint a `megoldott_feladatok.h`.

Adott a `Station` osztály, amely egy meteorológiai állomást reprezentál, tárolja a város nevét (`string`) és az állomás kódját (`string`), pár alapvető függvénnyel. A feladat az állomás mellé hőmérési adatokat tárolni. A `Measurement` osztály reprezentál egy-egy hőmérsékleti mérést, amelyben a hőmérséklet (`double`) és egy címke/időpont (`string`) szerepel.

A `Station` és `Measurement` osztályok kódja nem módosítható.

1. Legyen egy `WeatherArchive` osztály a `Station` osztályból származtatva. Konstruktorban három paramétert vár: a városon és kódon kívül a mérések darabszámát (`int`). Ennyi darab `Measurement` objektumot kell tárolni egy dinamikus tömbben, ügyelve később a felszabadításra. **(2 pont)**  
   A feladat kötelező, enélkül a későbbi tesztkódok nem fognak működni.
2. Legyen egy `setMeasurement` metódus a `WeatherArchive` osztályban, ami paraméterben egy indexet és egy `Measurement`-et kap. Tárolja el az adott objektumot a tömb megadott indexű helyén. Az index érvényességét nem kell ellenőrizni. **(1 pont)**
3. Legyen a `print` metódus a `WeatherArchive` osztályban felülírva. Az állomás adatain kívül írja ki soronként a méréseket a megadott formátumban. Egy-egy `Measurement` kiírásához használható a `Measurement` osztály saját `print` metódusa. **(2 pont)**
4. Legyen egy `getAverageTemperature` metódus a `WeatherArchive` osztályban, ami visszaadja a tárolt mérések átlaghőmérsékletét (`double`). Feltételezhetjük, hogy van legalább egy mérés. **(2 pont)**
5. Legyen egy statikus `double` adattag a `WeatherArchive` osztályban, amivel egy „hőségriadóhoz tartozó átlaghőmérséklet” állítható be. Kezdeti értéke legyen `27.5`, és a `getHeatAlertLevel` valamint `setHeatAlertLevel` statikus metódusokkal lehessen lekérdezni és beállítani. **(1 pont)**
6. Legyen egy `isHeatAlert` metódus a `WeatherArchive` osztályban, ami visszaadja, hogy az állomás átlaga eléri-e a minimumot (`bool`). **(1 pont)**
7. Legyen a `WeatherArchive` osztály egy `WeatherTools` nevű névtérben. **(1 pont)**

---

## 5. ParcelDay

### FONTOS INFÓK

- A feladat során alkalmazd a megtanult objektum-orientáltsági elveket, figyelj a konstansok és referenciák megfelelő használatára.
- A megadott példakódon ne módosíts, hacsak a feladat nem kéri. A megoldásnak ugyanezekkel a fájlokkal kell működnie.
- Figyelj a kiírás megfelelő formátumára, szóközökre, sortörésekre.
- Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
- Minden pont értékeléshez szükséges, hogy az adott ponthoz tartozó define szerepeljen a `megoldott_feladatok.h` fájlban.
- A header fájlokban csak a header guard-on belülre dolgozz.
- Csak olyan kódot adj be / használj gyakorláshoz, ami nálad fordul.
- A példakimenet a `main.cpp`-ben lévő tesztek alapján a `minta-stdout.txt` fájlban is megtalálható.
- Ellenőrzéshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

### Feladat

- A `#define PART<X>` direktívák a `megoldott_feladatok.h` fájlban szerepeljenek.
- A feladatok között lehet függőség, egymásra épülés.
- A beadandó / létrehozandó fájlok: `parcelday.h` és `parcelday.cpp`, valamint a `megoldott_feladatok.h`.

Adott a `CourierDay` osztály, amely egy futár egy napi munkáját reprezentálja, tárolja a futár nevét (`string`) és a régió nevét (`string`), pár alapvető függvénnyel. A feladat ehhez csomagokat tárolni. A `Parcel` osztály reprezentál egy-egy küldeményt, amelyben a tömeg kilogrammban (`double`) és egy prioritási jelző (`bool`) szerepel.

A `CourierDay` és `Parcel` osztályok kódja nem módosítható.

1. Legyen egy `ParcelDay` osztály a `CourierDay` osztályból származtatva. Konstruktorban három paramétert vár: a futár neve és régiója mellett a csomagok darabszámát (`int`). Ennyi darab `Parcel` objektumot kell tárolni egy dinamikus tömbben, ügyelve később a felszabadításra. **(2 pont)**  
   A feladat kötelező, enélkül a későbbi tesztkódok nem fognak működni.
2. Legyen egy `setParcel` metódus a `ParcelDay` osztályban, ami paraméterben egy indexet és egy `Parcel`-t kap. Tárolja el az adott objektumot a tömb megadott indexű helyén. Az index érvényességét nem kell ellenőrizni. **(1 pont)**
3. Legyen a `print` metódus a `ParcelDay` osztályban felülírva. A napi alapadatokon kívül írja ki soronként a csomagokat a megadott formátumban. Egy-egy `Parcel` kiírásához használható a `Parcel` osztály saját `print` metódusa. **(2 pont)**
4. Legyen egy `getTotalWeight` metódus a `ParcelDay` osztályban, ami visszaadja a csomagok teljes tömegét (`double`). Feltételezhetjük, hogy van legalább egy csomag. **(2 pont)**
5. Legyen egy statikus `double` adattag a `ParcelDay` osztályban, amivel egy „nehéz nap” alsó határa állítható be. Kezdeti értéke legyen `25.0`, és a `getHeavyDayLimit` valamint `setHeavyDayLimit` statikus metódusokkal lehessen lekérdezni és beállítani. **(1 pont)**
6. Legyen egy `isHeavyDay` metódus a `ParcelDay` osztályban, ami visszaadja, hogy az adott napi össztömeg eléri-e a minimumot (`bool`). **(1 pont)**
7. Legyen a `ParcelDay` osztály egy `LogisticsTools` nevű névtérben. **(1 pont)**
