# 08 - Kuponpénztárca

Készíts kuponkezelő programot vásárlási összeg csökkentésére.

## Bemeneti fájlok

```txt
coupons.json
purchases.json
```

A vásárlási fájl tételeket és árakat tartalmaz. A kuponfájl többféle kupont tartalmaz.

## Program viselkedése

A program:

1. betölti a kuponokat,
2. betölti a vásárlási tételeket,
3. kiírja a vásárlás eredeti összegét,
4. háromszor egymás után megpróbálja alkalmazni az elérhető kuponokat,
5. minden próbálkozás után kiírja a fizetendő összeget.

## Elvárt konzolkimenet

```txt
Total: 3800
After coupons 1: 300
After coupons 2: 1300
After coupons 3: 3300
```

## Szabályok

- Egy kupon csak akkor csökkenti az összeget, ha az adott pillanatban felhasználható.
- Felhasználás után a kupon állapota változhat.
- A fizetendő összeg nem lehet negatív.
