# 02 - Utvonalkepek

Ez a feladatsor is az `Image` absztrakt osztalyra epul. A `print()` mar kesz, neked a
mintakat eloallito osztalyokat kell megirnod kulon header fajlokban.

## PART1 - `Border` (1 pont)

Keszits `border.h` fajlt `Border` osztallyal.

- A `Border` az `Image`-bol szarmazzon.
- Merete fixen `10x6`.
- Egy pixel akkor legyen vilagos, ha a kep szelen van
  (`x==0`, `y==0`, `x==width-1` vagy `y==height-1`).

## PART2 - `Diamond` (2 pont)

Keszits `diamond.h` fajlt `Diamond` osztallyal.

- A `Diamond` az `Image`-bol szarmazzon.
- Konstruktora:
  `Diamond(int width, int height, int centerX, int centerY, int radius)`
- Egy pixel akkor vilagos, ha
  `abs(x-centerX) + abs(y-centerY) <= radius`.

## PART3 - `Negative` (2 pont)

Keszits `negative.h` fajlt `Negative` osztallyal.

- A `Negative` az `Image`-bol szarmazzon.
- Konstruktora:
  `Negative(const Image* original)`
- A kep merete egyezzen meg az eredeti kepevel.
- Minden pixel az eredeti ellentete legyen.

## PART4 - `PathImage` (3 pont)

Keszits `pathimage.h` fajlt `PathImage` osztallyal.

- A `PathImage` az `Image`-bol szarmazzon.
- Konstruktora:
  `PathImage(int width, int height)`
- Legyen benne:
  `void addPoint(int x, int y);`
- Az egymas utan felvett pontok tengellyel parhuzamos szakaszokat hataroznak meg.
- Egy pixel legyen vilagos, ha rajta van valamelyik ilyen szakaszon.
- A tesztek csak vizszintes vagy fuggoleges lepeseket adnak.

## PART5 - `Image::saveToFile()` (2 pont)

Ird meg az `Image::saveToFile(const string& path) const` fuggvenyt ugy, hogy a fajlban
pontosan a `print()`-tel megegyezo kimenet jelenjen meg.

## Megjegyzes

A reszfeladatoknal kulon header fajlokkal dolgozz, a teljes elvart kimenet a
`minta-stdout.txt` fajlban van.
