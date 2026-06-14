---
title: 08. NagyZH gyakorlórendszer
description: Önálló C++ NagyZH gyakorlócsomag Visual Studio-barát projektmappákkal, feladatokkal, segítségekkel és mintakimenetekkel.
---

Ez a gyakorlócsomag önálló NagyZH-felkészüléshez készült. A feladatok úgy vannak felépítve, hogy a követelményekből kelljen felismerned a megfelelő megoldási szerkezetet.

Minden feladatmappában van:

- `feladat.md` — teljes feladatleírás, megoldási spoiler nélkül,
- `projekt/` — a Visual Studióba bemásolható vagy becsatolható fájlok,
- `segitseg/` — tippek, ha elakadsz,
- `minta-stdout.txt` — ahol van konzolkimenet, ez alapján ellenőrizz,
- `megoldas/` — csak ott, ahol külön minta megoldás is készült.

## Letöltés

- [NagyZH gyakorlócsomag letöltése ZIP-ben](/cpp_learning/downloads/nagyzh-gyakorlo.zip)

A ZIP a teljes `nagyzh-gyakorlo/` mappát tartalmazza minden létrehozott feladattal, projektfájllal, adatfájllal, mintakimenettel és útmutatóval.

## Visual Studio használat

A kódolós feladatoknál a `projekt/` mappában minden szükséges fájl egy helyen van. Nincs külön `input/` mappa.

Példa:

```txt
06-butorbolt/projekt/
  main.cpp
  stock.json
  order-ok.json
  order-fail.json
  json.hpp
```

Ezeket másold be a Visual Studio projekted mappájába, majd csatold be a `.cpp` és `.h` fájlokat.

Ajánlott beállítás:

```txt
C++ Language Standard: ISO C++20 Standard (/std:c++20)
Warning Level: Level4 (/W4)
Configuration: Debug | x64
Working Directory: $(ProjectDir)
```

## Feladatok

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

## Javasolt sorrend

1. Olvasd el a `README.md` fájlt.
2. Ha Visual Studiót használsz, olvasd el a `visual-studio-utmutato.md` fájlt.
3. Kezdd a `00-bemelegito` mappával.
4. A feladatleírás alapján próbáld meg önállóan megoldani.
5. Csak elakadás után nyisd meg a `segitseg/` mappát.
6. A megoldást csak saját próbálkozás után nézd meg.

## Mikor vagy kész?

Akkor tekintsd késznek a feladatot, ha:

- lefordul,
- lefut,
- a konzolkimenet egyezik a `minta-stdout.txt` fájllal,
- a létrehozott fájlok tartalma is helyes,
- meg tudod magyarázni, hogyan tárolod az adatokat,
- sikertelen műveleteknél ellenőrizted, hogy nem romlik el az állapot.
