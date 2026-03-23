# Gyakorlo KisZH 1 – GradedCourse

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
- A beadando / letrehozando fajlok: `gradedcourse.h` es `gradedcourse.cpp`, valamint a `megoldott_feladatok.h`.

Adott a Course osztaly, amely egy egyetemi kurzust reprezental, tarolja a kurzus nevet (string) es kreditjeinek szamat (int), par alapveto fuggvennyel. A feladat a kurzusok melle a pontszamokat tarolni. A Grade osztaly reprezental egy-egy pontszamot es rovid megjegyzest, amibol a feladat szempontjabol a pontszam (getPoints) lesz erdekes.

A Course es Grade osztalyok kodja nem modosithato!

1. Legyen egy GradedCourse osztaly a Course osztalybol szarmaztatva. Konstruktorban harom parametert var: a kurzus neven (string) es kreditjein (int) kivul a tarolt ertekelesek darabszamat (int). Ennyi darab Grade objektumot kell tarolni egy dinamikus tombben, ugyelve kesobb a felszabaditasra. (2 pont)
A feladat kotelezo, enelkul a kesobbi tesztkodok nem fognak mukodni.

2. Legyen egy setGrade metodus a GradedCourse osztalyban, ami parameterben egy indexet es egy Grade-et kap. Tarolja el az adott Grade-et a tomb megadott indexu helyen. Az index ervenyesseget nem kell ellenorizni. (1 pont)

3. Legyen a print metodus a GradedCourse osztalyban felulirva. A kurzus neve es kreditje mellett irja ki soronkent a pontszamokat a megadott formatumban. Egy-egy Grade kiirasahoz hasznalhato a Grade osztaly sajat print metodusa. (2 pont)

4. Legyen egy getAveragePoints metodus a GradedCourse osztalyban, ami visszaadja a tarolt Grade-ek alapjan a kurzus atlagpontszamat (double). Feltehetjuk, hogy van legalabb egy Grade. (2 pont)

5. Legyen egy statikus double adattag a GradedCourse osztalyban, amivel egy "minimum atmeno pontszam" allithato be. Kezdeti erteke legyen 60.0, es a getPassLimit valamint setPassLimit statikus metodusokkal lehessen lekerdezni es beallitani. (1 pont)

6. Legyen egy isPassed metodus a GradedCourse osztalyban, ami visszaadja, hogy a kurzus atlagpontszama eleri-e a minimumot (bool). Ez akkor teljesul, ha az adott kurzus atlagpontszama legalabb akkora, mint az elozo feladatban emlitett minimum. (1 pont)

7. Legyen a GradedCourse osztaly egy AcademicTools nevu nevterben. (1 pont)

