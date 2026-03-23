# C++ Programozas 2 – 5 db gyakorlo KisZH csomag

Ebben a csomagban 5 darab, a csatolt mintahoz hasonlo felepitesu gyakorlo feladatsor talalhato.

## Minden feladatsor tartalma

- `feladatleiras.md` – a reszletes feladatleiras
- `main.cpp` – reszfeladatonkent bontott, latvanyos tesztkornyezet
- `megoldott_feladatok.h` – itt kell bekapcsolni az elkeszult reszeket
- ket darab **nem modosithato** alaposztaly / segedosztaly
- `minta-stdout.txt` – a vart kimenet
- `ellenorzes.sh` es `ellenorzes.ps1` – egyszeru automatikus ellenorzes
- `.pro` fajl – ha Qt Creatorral szeretned megnyitni

## Hasznalat

1. Olvasd el a `feladatleiras.md` fajlt.
2. Hozd letre a leirasban kert `.h` / `.cpp` fajlokat.
3. A `megoldott_feladatok.h` fajlban fokozatosan kommentezd ki a megfelelo `#define PART...` sorokat.
4. Forditsd a projektet.
5. Futtasd az `ellenorzes.sh` vagy `ellenorzes.ps1` scriptet.

## Megjegyzes

A csomag szandekosan a mintahoz hasonlo vizsga-erzesu szerkezetet koveti:
- reszpontokra bontott feladatok
- stdout alapu ellenorzes
- nem modosithato kiindulo osztalyok
- egy letrehozando uj osztaly minden feladatsorban
