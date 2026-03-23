# Gyakorlo KisZH 4 – WeatherArchive

## FONTOS INFOK

- A feladat soran alkalmazd a megtanult objektum-orientaltsagi elveket, figyelj a konstansok es referenciak megfelelo hasznalatara.
- A megadott peldakodon ne modosits, hacsak a feladat nem keri. A megoldasnak ugyanezekkel a fajlokkal kell mukodnie.
- Figyelj a kiiras megfelelo formatumara, szokozokre, sortoresekre.
- Ugyelj arra, hogy minden lefoglalt memoria keruljon megfeleloen felszabaditasra.
- Minden pont ertekeleshez szukseges, hogy az adott ponthoz tartozo define szerepeljen a `megoldott_feladatok.h` fajlban.
- A header fajlokban csak a header guard-on belulre dolgozz.
- Csak olyan kodot adj be / hasznalj gyakorlashoz, ami nalad fordul.
- A peldakimenet a `main.cpp`-ben levo tesztek alapjan a `minta-stdout.txt` fajlban is megtalalhato.
- Ellenorzeshez futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

## Feladat

- A `#define PART<X>` direktivak a `megoldott_feladatok.h` fajlban szerepeljenek.
- A feladatok kozott lehet fuggoseg, egymasra epules.
- A beadando / letrehozando fajlok: `weatherarchive.h` es `weatherarchive.cpp`, valamint a `megoldott_feladatok.h`.

Adott a Station osztaly, amely egy meteorologiai allomast reprezental, tarolja a varos nevet (string) es az allomas kodjat (string), par alapveto fuggvennyel. A feladat az allomas melle homeresi adatokat tarolni. A Measurement osztaly reprezental egy-egy homersekleti merest, amelyben a homerseklet (double) es egy cimke/idopont (string) szerepel.

A Station es Measurement osztalyok kodja nem modosithato!

1. Legyen egy WeatherArchive osztaly a Station osztalybol szarmaztatva. Konstruktorban harom parametert var: a varoson es kodon kivul a meresek darabszamat (int). Ennyi darab Measurement objektumot kell tarolni egy dinamikus tombben, ugyelve kesobb a felszabaditasra. (2 pont)
A feladat kotelezo, enelkul a kesobbi tesztkodok nem fognak mukodni.

2. Legyen egy setMeasurement metodus a WeatherArchive osztalyban, ami parameterben egy indexet es egy Measurementet kap. Tarolja el az adott objektumot a tomb megadott indexu helyen. Az index ervenyesseget nem kell ellenorizni. (1 pont)

3. Legyen a print metodus a WeatherArchive osztalyban felulirva. Az allomas adatain kivul irja ki soronkent a mereseket a megadott formatumban. Egy-egy Measurement kiirasahoz hasznalhato a Measurement osztaly sajat print metodusa. (2 pont)

4. Legyen egy getAverageTemperature metodus a WeatherArchive osztalyban, ami visszaadja a tarolt meresek atlaghomersekletet (double). Feltehetjuk, hogy van legalabb egy meres. (2 pont)

5. Legyen egy statikus double adattag a WeatherArchive osztalyban, amivel egy "hosegriadohoz tartozo atlaghomerseklet" allithato be. Kezdeti erteke legyen 27.5, es a getHeatAlertLevel valamint setHeatAlertLevel statikus metodusokkal lehessen lekerdezni es beallitani. (1 pont)

6. Legyen egy isHeatAlert metodus a WeatherArchive osztalyban, ami visszaadja, hogy az allomas atlaga eleri-e a minimumot (bool). (1 pont)

7. Legyen a WeatherArchive osztaly egy WeatherTools nevu nevterben. (1 pont)

