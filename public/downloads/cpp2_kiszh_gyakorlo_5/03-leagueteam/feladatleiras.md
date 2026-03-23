# Gyakorlo KisZH 3 – LeagueTeam

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
- A beadando / letrehozando fajlok: `leagueteam.h` es `leagueteam.cpp`, valamint a `megoldott_feladatok.h`.

Adott a Team osztaly, amely egy sportcsapatot reprezental, tarolja a csapat nevet (string) es varosat (string), par alapveto fuggvennyel. A feladat a csapat melle meccseredmenyeket tarolni. A MatchResult osztaly reprezentalt egy-egy eredmenyt, amelyben a lott es kapott golok szama szerepel.

A Team es MatchResult osztalyok kodja nem modosithato!

1. Legyen egy LeagueTeam osztaly a Team osztalybol szarmaztatva. Konstruktorban harom parametert var: a csapat neven es varosan kivul az eredmenyek darabszamat (int). Ennyi darab MatchResult objektumot kell tarolni egy dinamikus tombben, ugyelve kesobb a felszabaditasra. (2 pont)
A feladat kotelezo, enelkul a kesobbi tesztkodok nem fognak mukodni.

2. Legyen egy setResult metodus a LeagueTeam osztalyban, ami parameterben egy indexet es egy MatchResultot kap. Tarolja el az adott objektumot a tomb megadott indexu helyen. Az index ervenyesseget nem kell ellenorizni. (1 pont)

3. Legyen a print metodus a LeagueTeam osztalyban felulirva. A csapat adatain kivul irja ki soronkent a meccseredmenyeket a megadott formatumban. Egy-egy MatchResult kiirasahoz hasznalhato a MatchResult osztaly sajat print metodusa. (2 pont)

4. Legyen egy getAveragePoints metodus a LeagueTeam osztalyban, ami visszaadja a csapat atlagosan szerzett bajnoki pontjait (double) a tarolt eredmenyek alapjan. Gyozelemert 3 pont, dontetlenert 1 pont, veresegert 0 pont jar. Feltehetjuk, hogy van legalabb egy eredmeny. (2 pont)

5. Legyen egy statikus double adattag a LeagueTeam osztalyban, amivel egy "rajatszast ero minimum atlagpont" allithato be. Kezdeti erteke legyen 1.8, es a getPlayoffLevel valamint setPlayoffLevel statikus metodusokkal lehessen lekerdezni es beallitani. (1 pont)

6. Legyen egy isPlayoffReady metodus a LeagueTeam osztalyban, ami visszaadja, hogy az adott csapat atlaga eleri-e a minimumot (bool). (1 pont)

7. Legyen a LeagueTeam osztaly egy LeagueStats nevu nevterben. (1 pont)

