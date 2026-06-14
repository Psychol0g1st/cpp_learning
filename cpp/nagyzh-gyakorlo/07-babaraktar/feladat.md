# 07 - Babaraktár

Készíts raktárprogramot, amely több termékkategóriát kezel.

## Bemeneti fájlok

A projekt mappájában vannak:

```txt
toys.json
clothes.json
chairs.json
```

Mindegyik fájl az adott kategória termékeit tartalmazza.

## Program viselkedése

A program:

1. betölti mindhárom fájlt,
2. kiírja az összes terméket,
3. végrehajt három vásárlási próbát,
4. minden vásárlás után kiírja, sikeres volt-e, és mennyi pénz maradt.

## Elvárt konzolkimenet

```txt
10 x #T1(toy): Kocka, 3000 Ft, age: 3
2 x #T2(toy): Auto, 7000 Ft, age: 4
4 x #C1(clothes): Pulover, 6000 Ft, size: S
1 x #H1(chair): Etetoszek, 25000 Ft, can be set? Yes
Vasarlas 1 sikeres, penz: 43000
Vasarlas 2 SIKERTELEN, penz: 43000
Vasarlas 3 SIKERTELEN, penz: 43000
```

## Vásárlási szabályok

Egy vásárlás akkor sikeres, ha:

- létezik a termékazonosító,
- van elég darab készleten,
- van elég pénz.

Sikertelen vásárlásnál sem a pénz, sem a készlet nem változhat.
