# 03 - Járművek

Készíts programot három járműtípus adatainak kezelésére.

## Típusok

A programban ezek a járművek szerepelnek:

- bicikli,
- autó,
- teherautó.

Minden járműnek van:

- azonosítója,
- ára.

További adatok:

- bicikli: elektromos-e,
- autó: ülések száma,
- teherautó: teherbírás tonnában.

## Kimenet

A `main.cpp` három járművet hoz létre és kiírja őket.

Elvárt kimenet:

```txt
Bike B1, price: 120000, electric: yes
Car C1, price: 2500000, seats: 5
Truck T1, price: 9000000, capacity: 7.5
```

## Feladat

Fejezd be a `vehicle.h` és `vehicle.cpp` fájlokat úgy, hogy a megadott `main.cpp` működjön.

## Ellenőrzés

1. Ne legyen duplikált adattárolás.
2. A kimeneti formátum pontosan egyezzen.
3. Az árakat ne szövegként tárold.
