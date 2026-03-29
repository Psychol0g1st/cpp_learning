# 05 - Alakzatgyarto

Ez a csomag ujra az `Image` absztrakt osztalyra epul, de a reszfeladatok kifejezetten
alakzatokra, eltolasra, ciklusos mintakra es feltetelekkel felirt kirajzolasra mennek ra.

## PART1 - `VerticalStripes` (1 pont)

Keszits `verticalstripes.h` fajlt `VerticalStripes` osztallyal.

- A `VerticalStripes` az `Image`-bol szarmazzon.
- Konstruktora:
  `VerticalStripes(int width, int height, int stripeWidth)`
- Egy pixel akkor legyen vilagos, ha a `stripeWidth` szeles csikok kozott az aktualis oszlop
  paros sorszamú blokkba esik.
- Maskepp fogalmazva: legyen vilagos, ha `(x / stripeWidth) % 2 == 0`.

## PART2 - `Hourglass` (2 pont)

Keszits `hourglass.h` fajlt `Hourglass` osztallyal.

- A `Hourglass` az `Image`-bol szarmazzon.
- Konstruktora:
  `Hourglass(int width, int height)`
- Egy pixel akkor legyen vilagos, ha
  `abs(x - width/2) <= abs(y - height/2)`.

Ez egy homokora jellegu mintat ad.

## PART3 - `Shifted` (2 pont)

Keszits `shifted.h` fajlt `Shifted` osztallyal.

- A `Shifted` az `Image`-bol szarmazzon.
- Konstruktora:
  `Shifted(const Image* original, int dx, int dy)`
- Ugyanakkora legyen, mint az eredeti kep.
- A `pixel(x,y)` az eredeti kep `pixel(x-dx, y-dy)` helyerol jojjon.
- Ha ez a koordinata kilog a kepbol, akkor az eredmeny legyen sotet (`false`).

## PART4 - `Targets` (3 pont)

Keszits `targets.h` fajlt `Targets` osztallyal.

- A `Targets` az `Image`-bol szarmazzon.
- Konstruktora:
  `Targets(int width, int height)`
- Legyen benne:
  `void addTarget(int x, int y, int radius);`
- Egy pixel akkor legyen vilagos, ha valamelyik celpontra teljesul, hogy
  `max(abs(x-tx), abs(y-ty)) == radius`
- Vagyis a celpont korul negyzetes "gyurut" kell kirajzolni.

## PART5 - `Image::saveToFile()` (2 pont)

Ird meg az `Image::saveToFile(const string& path) const` fuggvenyt.

## Megjegyzes

Ez a csomag kulon jo gyakorlas egyszeru mintak, koordinata-transzformacio, tavolsagfogalmak,
es adatgyujteses (tobb celpont) feladatok gyakorlására.
