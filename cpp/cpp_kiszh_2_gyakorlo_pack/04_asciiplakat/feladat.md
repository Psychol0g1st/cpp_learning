# 04 - Asciiplakat

Ebben a feladatsorban nem logikai pixelekkel, hanem kozvetlen karakterekkel dolgozol.
A `Canvas` absztrakt osztaly egy `cell(x,y)` fuggvenyt var, amely egy karaktert ad vissza.
Az ures helyet mindenhol a `'.'` karakter jeloli.

## PART1 - `Frame` (1 pont)

Keszits `frame.h` fajlt `Frame` osztallyal.

- A `Canvas`-bol szarmazzon.
- Merete fixen `9x5`.
- A keret karaktere legyen `'*'`.
- Belul mindenhol `'.'` legyen.

## PART2 - `Stairs` (2 pont)

Keszits `stairs.h` fajlt `Stairs` osztallyal.

- A `Canvas`-bol szarmazzon.
- Konstruktora:
  `Stairs(int width, int height)`
- Az `y`-adik sorban az elso `y+1` karakter legyen `'#'`, a tobbi `'.'`.
- Ha `y+1` nagyobb, mint a szelesseg, akkor az egesz sor `'#'`.

## PART3 - `Overlay` (2 pont)

Keszits `overlay.h` fajlt `Overlay` osztallyal.

- A `Canvas`-bol szarmazzon.
- Konstruktora:
  `Overlay(const Canvas* bottom, const Canvas* top)`
- A meret egyezzen meg az also vaszon meretevel.
- Ha a felso vaszon adott helyen nem `'.'`, akkor azt a karaktert adja vissza.
- Kulonben az also vaszon karakteret.

Feltetelezheted, hogy a ket vaszon merete megegyezik.

## PART4 - `Labels` (3 pont)

Keszits `labels.h` fajlt `Labels` osztallyal.

- A `Canvas`-bol szarmazzon.
- Konstruktora:
  `Labels(int width, int height)`
- Legyen benne:
  `void addLabel(int x, int y, char c);`
- Alapbol mindenhol `'.'` legyen.
- Ha egy koordinatara karakter lett felveve, azon a helyen azt kell visszaadni.
- Ha ugyanarra a helyre tobbszor teszel karaktert, az utolso maradjon ervenyes.

## PART5 - `Canvas::saveToFile()` (2 pont)

Ird meg a `Canvas::saveToFile(const string& path) const` fuggvenyt a `canvas.cpp` fajlban
a `print()`-tel egyezo formatumban.

## Megjegyzes

Ez a feladatsor jo gyakorlas oroklodesre, polimorfizmusra, feltetelekre es egyszeru
karakteres "rajzolasra".
