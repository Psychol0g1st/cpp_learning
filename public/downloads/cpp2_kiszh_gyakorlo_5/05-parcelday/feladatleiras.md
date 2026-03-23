# Gyakorlo KisZH 5 – ParcelDay

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
- A beadando / letrehozando fajlok: `parcelday.h` es `parcelday.cpp`, valamint a `megoldott_feladatok.h`.

Adott a CourierDay osztaly, amely egy futar egy napi munkajat reprezentalja, tarolja a futar nevet (string) es a regio nevet (string), par alapveto fuggvennyel. A feladat ehhez csomagokat tarolni. A Parcel osztaly reprezental egy-egy kuldemenyt, amelyben a tomeg kilogrammban (double) es egy prioritasi jelzo (bool) szerepel.

A CourierDay es Parcel osztalyok kodja nem modosithato!

1. Legyen egy ParcelDay osztaly a CourierDay osztalybol szarmaztatva. Konstruktorban harom parametert var: a futar neve es regioja mellett a csomagok darabszamat (int). Ennyi darab Parcel objektumot kell tarolni egy dinamikus tombben, ugyelve kesobb a felszabaditasra. (2 pont)
A feladat kotelezo, enelkul a kesobbi tesztkodok nem fognak mukodni.

2. Legyen egy setParcel metodus a ParcelDay osztalyban, ami parameterben egy indexet es egy Parcel-t kap. Tarolja el az adott objektumot a tomb megadott indexu helyen. Az index ervenyesseget nem kell ellenorizni. (1 pont)

3. Legyen a print metodus a ParcelDay osztalyban felulirva. A napi alapadatokon kivul irja ki soronkent a csomagokat a megadott formatumban. Egy-egy Parcel kiirasahoz hasznalhato a Parcel osztaly sajat print metodusa. (2 pont)

4. Legyen egy getTotalWeight metodus a ParcelDay osztalyban, ami visszaadja a csomagok teljes tomeget (double). Feltehetjuk, hogy van legalabb egy csomag. (2 pont)

5. Legyen egy statikus double adattag a ParcelDay osztalyban, amivel egy "nehez nap" also hatara allithato be. Kezdeti erteke legyen 25.0, es a getHeavyDayLimit valamint setHeavyDayLimit statikus metodusokkal lehessen lekerdezni es beallitani. (1 pont)

6. Legyen egy isHeavyDay metodus a ParcelDay osztalyban, ami visszaadja, hogy az adott napi ossztomeg eleri-e a minimumot (bool). (1 pont)

7. Legyen a ParcelDay osztaly egy LogisticsTools nevu nevterben. (1 pont)

