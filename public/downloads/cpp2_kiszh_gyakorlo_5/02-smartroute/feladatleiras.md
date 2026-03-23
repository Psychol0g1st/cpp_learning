# Gyakorlo KisZH 2 – SmartRoute

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
- A beadando / letrehozando fajlok: `smartroute.h` es `smartroute.cpp`, valamint a `megoldott_feladatok.h`.

Adott a Route osztaly, amely egy utvonalat reprezental, tarolja az indulas (string) es az erkezes (string) helyet, par alapveto fuggvennyel. A feladat az utvonalhoz reszszakaszokat tarolni. A Checkpoint osztaly reprezental egy-egy szakaszt, tarolja annak hosszat kilometerben (double) es az ahhoz tartozo menetidot percben (int).

A Route es Checkpoint osztalyok kodja nem modosithato!

1. Legyen egy SmartRoute osztaly a Route osztalybol szarmaztatva. Konstruktorban harom parametert var: az indulasi es erkezesi helyen kivul a szakaszok darabszamat (int). Ennyi darab Checkpoint objektumot kell tarolni egy dinamikus tombben, ugyelve kesobb a felszabaditasra. (2 pont)
A feladat kotelezo, enelkul a kesobbi tesztkodok nem fognak mukodni.

2. Legyen egy setCheckpoint metodus a SmartRoute osztalyban, ami parameterben egy indexet es egy Checkpointot kap. Tarolja el az adott objektumot a tomb megadott indexu helyen. Az index ervenyesseget nem kell ellenorizni. (1 pont)

3. Legyen a print metodus a SmartRoute osztalyban felulirva. Az utvonal alapadatain kivul irja ki soronkent a szakaszokat a megadott formatumban. Egy-egy Checkpoint kiirasahoz hasznalhato a Checkpoint osztaly sajat print metodusa. (2 pont)

4. Legyen egy getAverageSpeed metodus a SmartRoute osztalyban, ami visszaadja a teljes utvonal atlagsebesseget km/h egysegben (double), a tarolt szakaszok alapjan. Feltehetjuk, hogy a teljes menetido pozitiv. (2 pont)

5. Legyen egy statikus double adattag a SmartRoute osztalyban, amivel egy "ajanlott minimalis atlagsebesseg" allithato be. Kezdeti erteke legyen 55.0, es a getMinimumRecommendedSpeed valamint setMinimumRecommendedSpeed statikus metodusokkal lehessen lekerdezni es beallitani. (1 pont)

6. Legyen egy isFastEnough metodus a SmartRoute osztalyban, ami visszaadja, hogy az adott utvonal atlaga eleri-e a minimumot (bool). (1 pont)

7. Legyen a SmartRoute osztaly egy NavigationTools nevu nevterben. (1 pont)

