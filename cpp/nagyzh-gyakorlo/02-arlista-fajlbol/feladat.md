# 02 - Árlista fájlból

Készíts programot, amely a `products.json` fájlból termékeket olvas be, majd összesítéseket ír ki.

## Bemenet

A `products.json` a projekt mappájában van. Egy tömböt tartalmaz. Minden elemben szerepel:

- `Id`
- `Name`
- `Price`
- `Weight`

## Konzolkimenet

A program írja ki:

1. a termékek nevét a fájl sorrendjében,
2. az összes termék árának összegét,
3. a legdrágább termék azonosítóját.

Elvárt kimenet:

```txt
Szek
Asztal
Polc
Total: 76970
Most expensive: P2
```

## Fájlkimenet

Készíts `output-prices.json` fájlt.

A fájlban minden termékhez szerepeljen:

- `Id`
- `Price`

Az elemek sorrendje egyezzen a bemeneti fájl sorrendjével.

## Ellenőrzés

1. A program találja meg a `products.json` fájlt.
2. A konzolkimenet egyezzen a `minta-stdout.txt` fájllal.
3. Az `output-prices.json` tartalmazza mindhárom terméket.
