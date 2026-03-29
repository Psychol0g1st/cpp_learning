---
title: C++ 2. KisZH gyakorlócsomag
description: 5 új, automatikusan ellenőrizhető C++ gyakorlófeladatsor a minta 2. KisZH szerkezetében.
---

## Letöltés

- [Teljes gyakorlócsomag letöltése](/cpp_learning/downloads/kiszh_2-gyakorlo-feladatok.zip)

## Mit tartalmaz a csomag?

Az összeállítás 5 külön feladatsort ad, mindegyik a mintafeladat logikáját követi:

- van egy absztrakt alaposztály
- a `main.cpp` automatikusan teszteli a részeket
- a `megoldott_feladatok.h` kapcsolja a `PART1..PART5` részeket
- van teljes mintakimenet (`minta-stdout.txt`)
- van külön szöveges leírás (`feladat.md`)

A csomagok:

1. **Fényfestő képek**
2. **Útvonalképek**
3. **Sorozatlabor**
4. **ASCII-plakát**
5. **Alakzatgyártó**

---

## 1. Fényfestő képek

Ebben a feladatsorban egy `Image` absztrakt osztályra kell építeni.

### Részek

- **PART1 – `Cross`**  
  Fix méretű kereszt alakú kép.

- **PART2 – `Triangle`**  
  Paraméterezhető, lefelé növekvő háromszög kirajzolása.

- **PART3 – `MirrorX`**  
  Egy meglévő kép vízszintes tükrözése.

- **PART4 – `Lanterns`**  
  Több lámpás Manhattan-távolság alapú fénykörrel.

- **PART5 – `Image::saveToFile()`**  
  A konzolos képkimenet fájlba mentése.

### Mit gyakorol?

- absztrakt osztály
- öröklődés
- koordinátaalapú minták
- feltételek
- fájlírás

---

## 2. Útvonalképek

Ez is képes feladat, de itt hangsúlyosabb a szakaszok és útvonalak kezelése.

### Részek

- **PART1 – `Border`**  
  Keret rajzolása fix méretben.

- **PART2 – `Diamond`**  
  Manhattan-távolsággal megadott rombusz.

- **PART3 – `Negative`**  
  Egy másik kép invertáltja.

- **PART4 – `PathImage`**  
  Felvett pontokból felépített vízszintes és függőleges szakaszok.

- **PART5 – `Image::saveToFile()`**  
  Szöveges formátumú fájlmentés.

### Mit gyakorol?

- ciklusok
- feltételek
- absztrakt osztály
- dekorátor jellegű becsomagolás
- adatstruktúra használat

---

## 3. Sorozatlabor

Ez a csomag **nem kirajzolós**, hanem egy `Sequence` absztrakt osztályra épül.  
Kifejezetten jó gyakorlás absztrakt osztályra, öröklődésre és polimorf használatra.

### Részek

- **PART1 – `ArithmeticSequence`**  
  Számtani sorozat.

- **PART2 – `ZigZagSequence`**  
  Alsó és felső határ között oda-vissza lépkedő sorozat.

- **PART3 – `ReverseSequence`**  
  Egy meglévő sorozat fordított sorrendű nézete.

- **PART4 – `MarkedSequence`**  
  Egy meglévő sorozat egyes elemeinek felülírása.

- **PART5 – `Sequence::saveToFile()`**  
  A kiírt sorozat fájlba mentése.

### Mit gyakorol?

- absztrakt osztály példányosításának logikája
- öröklődés
- pointeres becsomagolás
- ciklusok
- feltételek
- fájlírás

---

## 4. ASCII-plakát

Ebben a feladatsorban nem logikai pixelekkel, hanem közvetlen karakterekkel kell dolgozni.  
Az üres helyet a `'.'` karakter jelöli.

### Részek

- **PART1 – `Frame`**  
  Csillagos keret.

- **PART2 – `Stairs`**  
  Soronként növekvő lépcső alak.

- **PART3 – `Overlay`**  
  Két vászon egymásra helyezése.

- **PART4 – `Labels`**  
  Koordinátákra elhelyezett karakterek.

- **PART5 – `Canvas::saveToFile()`**  
  Vászon mentése fájlba.

### Mit gyakorol?

- karakteres kirajzolás
- öröklődés
- összetétel
- felülírás
- fájlkezelés

---

## 5. Alakzatgyártó

Ez a csomag ismét az `Image` absztrakt osztályra épül, kifejezetten alakzatokra és koordináta-transzformációkra.

### Részek

- **PART1 – `VerticalStripes`**  
  Váltakozó függőleges csíkok.

- **PART2 – `Hourglass`**  
  Homokóra alakzat feltételes kirajzolással.

- **PART3 – `Shifted`**  
  Egy másik kép eltolása.

- **PART4 – `Targets`**  
  Több célpont körüli négyzetes gyűrűk kirajzolása.

- **PART5 – `Image::saveToFile()`**  
  Képkimenet mentése fájlba.

### Mit gyakorol?

- koordináta-transzformáció
- egyszerű alakzatok
- távolságfogalmak
- több objektum kezelése
- fájlírás

---

## Javasolt használat

Nyisd meg valamelyik feladatsor mappáját, olvasd el a `feladat.md` fájlt, majd a `megoldott_feladatok.h` fájlban mindig csak azt a `PART...` sort kapcsold be, amelyiket épp meg akarod oldani.  
A futtatás után a kimenetet hasonlítsd össze a `minta-stdout.txt` fájllal.
