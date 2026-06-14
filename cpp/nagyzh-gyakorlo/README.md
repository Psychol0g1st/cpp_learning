# NagyZH gyakorlórendszer

Ez a csomag önálló NagyZH-gyakorláshoz készült. A feladatok külön-külön gyakoroltatják a visszatérő C++ vizsgafeladat-részeket, majd mini-ZH jellegű feladatokban összerakják őket.

## Hogyan használd?

1. Menj sorban a mappákon.
2. Minden mappában először a `feladat.md` fájlt olvasd el.
3. A kódoláshoz a `projekt/` mappát másold vagy nyisd meg Visual Studióban.
4. Ha elakadsz, csak utána nyisd meg a `segitseg/` mappát.
5. Ha van `megoldas/` mappa, azt csak saját próbálkozás után nézd meg.
6. A `minta-stdout.txt` fájl a várt konzolkimenetet tartalmazza.
7. A hibanaplót minden komolyabb elakadás után töltsd ki.

## Visual Studio

A részletes beállításokat itt találod:

```txt
visual-studio-utmutato.md
```

Röviden:

```txt
C++ Language Standard: ISO C++20 Standard (/std:c++20)
Warning Level: Level4 (/W4)
Configuration: Debug | x64
Working Directory: $(ProjectDir)
```

Minden kódolós feladatnál a szükséges `.cpp`, `.h`, `.json`, `.txt` fájlok egy helyen vannak a `projekt/` mappában. Nem kell külön `input/` mappát beállítanod.

## Mappák

| Mappa | Téma |
|---|---|
| `00-bemelegito` | rövid kódolvasási és javítási bemelegítő |
| `01-termek-adatlap` | egyszerű termékadatok kezelése |
| `02-arlista-fajlbol` | terméklista fájlból és összesítések |
| `03-jarmuvek` | járműtípusok közös kezelése |
| `04-garazs` | többféle jármű egy garázsban |
| `05-jarmu-kereso` | járművek keresése és szűrése |
| `06-butorbolt` | készlet, rendelés és export |
| `07-babaraktar` | több termékkategória, szállítás és vásárlás |
| `08-kuponpenztarca` | kuponok, vásárlás és állapotváltozás |
| `09-kalandorcsapat` | karakterek, csapat és harci szimuláció |
| `10-hibakereso-labor` | hibás kódrészletek javítása elvárt viselkedés alapján |

## Mikor vagy kész?

Akkor tekintsd késznek a feladatot, ha:

- lefordul,
- lefut,
- a kimenet egyezik a `minta-stdout.txt` fájllal,
- fájlkiírásnál az adatok is egyeznek,
- meg tudod magyarázni, hogyan tárolod az adatokat,
- meg tudod mondani, melyik művelet változtat állapotot,
- sikertelen művelet után ellenőrizted, hogy nem romlott el az állapot.
