# 01 - Termék adatlap

Készíts programot, amely két termék adatlapját írja ki, majd kiszámolja az összárukat.

## Követelmények

Egy terméknek legyen:

- azonosítója,
- neve,
- ára.

A programnak pontosan ezt kell kiírnia:

```txt
#P1: Szek, 14990 Ft
#P2: Asztal, 39990 Ft
Total: 54980
```

## Elvárt fájlok

A `projekt/` mappában elkezdett fájlokat fejezd be:

```txt
main.cpp
product.h
product.cpp
```

A `main.cpp` tartalmát ne írd át lényegesen. A szükséges kódot a `Product` osztályban készítsd el.

## Ellenőrzés

1. Forduljon a projekt.
2. Ne legyen publikus adattag csak azért, hogy a `main.cpp` hozzáférjen.
3. A kimenet egyezzen a `minta-stdout.txt` tartalmával.
