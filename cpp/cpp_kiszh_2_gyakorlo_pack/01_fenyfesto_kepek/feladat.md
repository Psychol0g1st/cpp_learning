# 01 - Fenyfesto kepek

Az alapkod egy `Image` absztrakt osztalyt ad, amelynek a `pixel(x,y)` fuggvenye mondja meg,
hogy az adott pixel vilagos (`true`) vagy sotet (`false`). A `print()` mar keszen van:
pontot (`.`) ir ki a vilagos es `#` jelet a sotet pixelekre.

A feladatokhoz a `megoldott_feladatok.h` fajlban kell az egyes `#define PART...`
sorokat bekapcsolni. Az 1-4. reszfeladatoknal uj **header fajlt** kell letrehozni, a
megadott osztalyokkal. A 5. reszfeladatnal a `saveToFile()` fuggvenyt kell megirni.

## PART1 - `Cross` (1 pont)

Hozz letre egy `cross.h` fajlt, benne egy `Cross` osztallyal.

- A `Cross` az `Image`-bol szarmazzon.
- Merete fixen `9x9`.
- Azok a pixelek legyenek vilagosak, amelyek a kozepso sorban vagy a kozepso oszlopban vannak.

## PART2 - `Triangle` (2 pont)

Hozz letre egy `triangle.h` fajlt, benne egy `Triangle` osztallyal.

- A `Triangle` az `Image`-bol szarmazzon.
- Konstruktora:
  `Triangle(int width, int height, int centerX, int topY, int bottomY)`
- Egy pixel akkor vilagos, ha:
  - `topY <= y <= bottomY`
  - es `abs(x-centerX) <= y-topY`

Ez egy lefelé novekvo, egyenlo szaru haromszoget rajzol.

## PART3 - `MirrorX` (2 pont)

Hozz letre egy `mirrorx.h` fajlt, benne egy `MirrorX` osztallyal.

- A `MirrorX` az `Image`-bol szarmazzon.
- Konstruktora egy letezo kepre mutato pointert kap:
  `MirrorX(const Image* original)`
- A kep merete egyezzen meg az eredeti kep meretevel.
- A `pixel(x,y)` a kapott kep vizszintes tukorkepe legyen.

## PART4 - `Lanterns` (3 pont)

Hozz letre egy `lanterns.h` fajlt, benne egy `Lanterns` osztallyal.

- A `Lanterns` az `Image`-bol szarmazzon.
- Konstruktora: `Lanterns(int width, int height)`
- Legyen benne egy
  `void addLantern(int x, int y, int radius);`
  fuggveny.
- Egy pixel akkor vilagos, ha legalabb egy lampasra teljesul:
  `abs(x-lx) + abs(y-ly) <= radius`

Vagyis minden lampas Manhattan-tavolsag alapjan vilagit.

## PART5 - `Image::saveToFile()` (2 pont)

Ird meg az `Image::saveToFile(const string& path) const` fuggvenyt az `image.cpp` fajlban.

- A fajl tartalma pontosan ugyanabban a formatumban keszuljon, mint a `print()` kimenete.
- Az elso sor a szelesseg es magassag legyen.
- Utana soronkent jojjon a kep, `.` es `#` karakterekkel.

## Megjegyzes

A `main.cpp` mar tartalmaz teszteket minden reszfeladatra. A teljes jo kimenet a
`minta-stdout.txt` fajlban talalhato.
