---
title: 04. Mini-Projekt - A Végzet Arénája (RPG)
description: Építsünk egy konzolos szerepjátékot! Tömbök, mutatók és objektumok egyetlen izgalmas játékban.
---

Szia! Elérkeztünk az eddigi legizgalmasabb részhez. Most, hogy már ismerjük az osztályokat (OOP), a tömböket és a mutatókat, ideje összerakni belőlük valami igazán menőt: egy saját, konzolos szerepjátékot (RPG)!

Ebben a projektben a Hősünk belép az Arénába, ahol egy tömbnyi Szörnnyel kell megküzdenie. Itt fogjuk igazán látni, **miért is kellenek a mutatók**: a Hősnek "át kell adnunk" a Szörny memóriacímét, hogy a kardcsapásával ténylegesen csökkenteni tudja a szörny HP-ját.

---

## A Játék Szabályai
1.  Van egy **Hősünk**, akinek van neve, életereje (HP) és sebzése.
2.  Van egy arénánk, ami igazából egy **mutatókat tároló tömb**, benne 3 darab **Szörnnyel**.
3.  A játék egy ciklusban fut: a Hős megtámadja a soron következő Szörnyet, majd a Szörny (ha túlélte) visszatámad.
4.  Ha egy Szörny HP-ja 0 alá csökken, jöhet a következő! Ha a Hős HP-ja fogy el, a játéknak vége.


Az Aréna és a Játék Ciklus (A `main` függvény)

Most rakjuk össze az egészet! Létrehozzuk a Hőst, és dinamikusan (a `new` kulcsszóval) legenerálunk 3 Szörnyet egy tömbbe. Ezután egy `while` ciklussal szimuláljuk a harcot.

```cpp
int main() {
    cout << "Udv a Vegzet Arenajaban!" << endl;

    // 1. Létrehozzuk a Hőst a Stack-en (sima objektum)
    Hos jatekos("Artur Kiraly", 100, 25);

    // 2. Létrehozzuk a Szörnyeket a Heap-en egy pointer-tömbben
    // Ez egy olyan tömb, aminek minden eleme egy Szörny memóriacímét tárolja!
    Szorny* arena[3];
    arena[0] = new Szorny("Goblin", 40, 5);
    arena[1] = new Szorny("Ork", 60, 15);
    arena[2] = new Szorny("Sarkany", 120, 25);

    // 3. A FŐ JÁTÉK CIKLUS
    for (int i = 0; i < 3; i++) {
        Szorny* aktualisSzorny = arena[i]; // Kijelöljük a soron következő ellenfelet
        
        cout << "\nUj ellenfel lep az arenaba: " << aktualisSzorny->getNev() << "!" << endl;

        // Addig harcolnak, amíg valaki meg nem hal
        while (!jatekos.isHalott() && !aktualisSzorny->isHalott()) {
            
            // Kiíratjuk a HP-kat
            jatekos.statusz();
            aktualisSzorny->statusz();
            cout << endl;

            // 1. A Hős támad (Átadjuk a szörny mutatóját!)
            jatekos.tamad(aktualisSzorny);

            // 2. Ha a Szörny túlélte, visszatámad
            if (!aktualisSzorny->isHalott()) {
                cout << "<--- " << aktualisSzorny->getNev() << " visszatamad!" << endl;
                jatekos.sebzestKap(aktualisSzorny->getSebzes());
                cout << "Sebzes: " << aktualisSzorny->getSebzes() << " pont!" << endl;
            } else {
                cout << "X_X " << aktualisSzorny->getNev() << " elpusztult!" << endl;
            }
        }

        // Ha a Hős halt meg, megszakítjuk az egész arénát
        if (jatekos.isHalott()) {
            cout << "\nGAME OVER! " << jatekos.getNev() << " elhullott a csataban..." << endl;
            break; // Kilépünk a for ciklusból
        }
    }

    // 4. A VÉGEREDMÉNY
    if (!jatekos.isHalott()) {
        cout << "\nGRATULALOK! Gyozedelmeskedtel a Vegzet Arenajaban!" << endl;
    }

    // 5. TAKARÍTÁS (Kötelező!)
    // Mivel a Szörnyeket a 'new' kulcsszóval hoztuk létre, nekünk kell letörölni őket!
    for (int i = 0; i < 3; i++) {
        delete arena[i];
    }

    return 0;
}
```

---

### Miért zseniális ez a projekt tanuláshoz?

* **Látod a mutatók hasznát:** A `tamad(Szorny* celpont)` metódus nélkülözhetetlen. Ha érték szerint (`tamad(Szorny celpont)`) adnád át, a Hős csak egy *másolatot* ütlegelne a memóriában, és az Arénában lévő igazi szörny HP-ja sosem csökkenne!
* **Dinamikus tömbök:** Az `arena` tömb mutatókat tárol. Ezzel felkészülsz arra, amikor komolyabb játékokban egy listában (pl. `std::vector`) tárolod majd az ellenségek memóriacímeit.
* **Memóriakezelés:** A program végén lévő `delete` ciklus rákényszerít, hogy felelősséget vállalj az általad lefoglalt adatokért.

> **Kihívás neked!**
> Szeretnéd kicsit megfűszerezni a játékot? Próbálj meg hozzáadni a Hős osztályhoz egy `gyogyital()` metódust (ami 30-cal növeli a HP-t), és a harci ciklusban kérd be a felhasználótól (`cin`), hogy a körében támadni (1) vagy gyógyulni (2) akar-e!
