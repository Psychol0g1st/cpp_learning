# Visual Studio útmutató

Nyugodtan dolgozz Visual Studióban. Minden kódolós feladatnál a `projekt/` mappa tartalmazza az összes szükséges forrás- és adatfájlt.

## 1. Projekt létrehozása

Visual Studio kezdőképernyő:

```txt
Create a new project
```

Válaszd ezt:

```txt
Console App
```

vagy ezt:

```txt
Empty Project
```

A projekt neve lehet ugyanaz, mint a gyakorlómappa neve, például:

```txt
06-butorbolt
```

## 2. Fájlok bemásolása

Az adott feladat `projekt/` mappájából másolj át mindent a Visual Studio projekt mappájába.

Példa:

```txt
06-butorbolt/projekt/
  main.cpp
  stock.json
  order-ok.json
  order-fail.json
  json.hpp
```

Visual Studio projektben:

```txt
06-butorbolt-vs/
  06-butorbolt-vs.vcxproj
  main.cpp
  stock.json
  order-ok.json
  order-fail.json
  json.hpp
```

Nincs külön `input/` mappa. A program a fájlokat közvetlenül a projekt mappájából olvassa.

## 3. Fájlok hozzáadása

`.cpp` fájlok:

```txt
Solution Explorer
  Source Files
    Right click
      Add > Existing Item...
```

`.h` fájlok és `json.hpp`:

```txt
Solution Explorer
  Header Files
    Right click
      Add > Existing Item...
```

A `.json` és `.txt` adatfájlokat nem muszáj becsatolni, de ott kell lenniük a `.vcxproj` mellett.

## 4. C++20

```txt
Project > Properties
```

A Properties ablak tetején:

```txt
Configuration: All Configurations
Platform: All Platforms
```

Majd:

```txt
C/C++ > Language > C++ Language Standard
```

Választandó:

```txt
ISO C++20 Standard (/std:c++20)
```

## 5. Figyelmeztetések

```txt
C/C++ > General > Warning Level
```

Ajánlott:

```txt
Level4 (/W4)
```

## 6. Precompiled Header kikapcsolása

Ha ilyen hibát kapsz:

```txt
fatal error C1010: unexpected end of file while looking for precompiled header
```

akkor:

```txt
C/C++ > Precompiled Headers > Precompiled Header
```

Állítsd erre:

```txt
Not Using Precompiled Headers
```

## 7. Working Directory

```txt
Project > Properties > Debugging > Working Directory
```

Állítsd erre:

```txt
$(ProjectDir)
```

Így a program megtalálja az ugyanabba a mappába másolt `.json` és `.txt` fájlokat.

## 8. Futtatás és hibakeresés

Breakpointos futtatás:

```txt
F5
```

Csak futtatás:

```txt
Ctrl + F5
```

Hasznos ablak:

```txt
Debug > Windows > Watch > Watch 1
```

Figyeld például:

```txt
products.size()
quantity
money
sum
```

Lépésenkénti futtatás:

```txt
F10 = következő sor
F11 = belépés függvénybe
```
