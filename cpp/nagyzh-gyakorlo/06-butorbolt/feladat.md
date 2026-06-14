# 06 - Bútorbolt

Készíts bútorboltos programot készletkezeléssel és rendelésekkel.

## Bemeneti fájlok

A projekt mappájában vannak:

```txt
stock.json
order-ok.json
order-fail.json
```

A `stock.json` termékeket és kezdő készletet tartalmaz. A rendelésfájlok termékazonosítókat és darabszámokat tartalmaznak.

## Bútoradatok

Minden bútornak van:

- azonosítója,
- faanyaga,
- tömege,
- ára.

A fájlban több bútortípus szerepel, eltérő extra adatokkal.

## Program viselkedése

A program:

1. betölti a készletet,
2. kiírja az aktuális darabszámokat,
3. betölt két rendelést,
4. kiszámolja mindkét rendelés árát,
5. megpróbálja teljesíteni őket,
6. kiírja a végső készletet,
7. létrehoz egy `output-stock.json` fájlt a végső darabszámokkal.

## Elvárt konzolkimenet

```txt
CH1: 5 db
TB1: 2 db
WR1: 1 db
Order ok price: 69000
Order fail price: 198000
Deliver ok: 1
Deliver fail: 0
CH1: 3 db
TB1: 1 db
WR1: 1 db
```

## Állapotkövetelmény

Ha egy rendelés nem teljesíthető, a készlet egyetlen terméknél sem változhat.
