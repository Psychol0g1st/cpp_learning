# 09 - Kalandorcsapat

Készíts programot, amely karaktereket tölt be, csapatot állít össze, majd sárkány elleni harcot szimulál.

## Bemeneti fájlok

```txt
knights.json
rangers.json
mages.json
party-1.txt
```

A JSON fájlok karaktereket tartalmaznak. A `party-1.txt` a csapat karakterazonosítóit sorolja fel.

## Program viselkedése

A program:

1. betölti az összes karaktert,
2. kiírja őket,
3. betölti a csapatot az azonosítók alapján,
4. kiírja a csapat összköltségét,
5. lefuttat egy harcot egy sárkány ellen.

## Kezdő konzolkimenet

A karakterlista és költség kiírásának így kell kezdődnie:

```txt
[Knight K1, price: 120, strength: 80]
[Knight K2, price: 150, strength: 110]
[Ranger R1, price: 90, agility: 35]
[Mage M1, price: 200, magic: 0.1]
Total cost: 410
```

## Harci szabály

A csapat körökben támad. Egy körben minden életben lévő csapattag támad egyszer. Ha a sárkány életereje elfogy, a csapat győz. Ha a kör végén a sárkány még él, elvesz egy csapattagot. Ha nincs több csapattag, a csapat veszít.

## Ellenőrzés

- Hibás azonosító esetén ne legyen összeomlás.
- A csapat költsége a kiválasztott karakterek áraiból álljon össze.
- A harc véges időn belül fejeződjön be.
