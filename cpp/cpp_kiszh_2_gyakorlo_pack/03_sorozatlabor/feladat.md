# 03 - Sorozatlabor

Ez a feladatsor **nem kirajzolos**. Itt egy `Sequence` absztrakt osztalyra kell epitened,
amely egy egesz szamsorozatot reprezental. A `print()` mar kesz, ez kiirja a sorozat hosszat,
majd a szamokat egy sorban.

A reszfeladatok ugyanugy kulon header fajlokban keszuljenek, mint a mintafeladatnal.

## PART1 - `ArithmeticSequence` (1 pont)

Keszits `arithmetic.h` fajlt `ArithmeticSequence` osztallyal.

- A `Sequence`-bol szarmazzon.
- Konstruktora:
  `ArithmeticSequence(int start, int step, int length)`
- Az `i`-edik elem erteke: `start + step*i`

## PART2 - `ZigZagSequence` (2 pont)

Keszits `zigzag.h` fajlt `ZigZagSequence` osztallyal.

- A `Sequence`-bol szarmazzon.
- Konstruktora:
  `ZigZagSequence(int low, int high, int length)`
- A sorozat `low`-tol induljon, felfele menjen `high`-ig, utana visszafele, majd ujra elore...
- Pelda: `low=2`, `high=5` es `length=9` esetben:
  `2 3 4 5 4 3 2 3 4`

## PART3 - `ReverseSequence` (2 pont)

Keszits `reversed.h` fajlt `ReverseSequence` osztallyal.

- A `Sequence`-bol szarmazzon.
- Konstruktora egy masik sorozatra mutato pointert kap:
  `ReverseSequence(const Sequence* original)`
- A kapott sorozat elemeit forditott sorrendben adja vissza.

## PART4 - `MarkedSequence` (3 pont)

Keszits `marked.h` fajlt `MarkedSequence` osztallyal.

- A `Sequence`-bol szarmazzon.
- Konstruktora:
  `MarkedSequence(const Sequence* original)`
- Legyen benne:
  `void mark(int index, int newValue);`
- Alapesetben az eredeti sorozat elemeit adja vissza.
- Ha egy indexre markolas tortent, akkor azon a helyen a felulirt erteket adja.
- Ha ugyanarra az indexre tobbszor hivjak meg a `mark`-ot, az utolso ertek szamitson.

## PART5 - `Sequence::saveToFile()` (2 pont)

Ird meg a `Sequence::saveToFile(const string& path) const` fuggvenyt ugy, hogy a fajl
tartalma byte-ra ugyanaz legyen, mint amit a `print()` kiir.

## Megjegyzes

Ez a feladatsor jo gyakorlas absztrakt osztaly, oroklodes, dekorator jellegu becsomagolas,
fajliras, ciklusok es feltetelek teren is.
