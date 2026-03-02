---
title: 01. Számológép
description: Egy olyan konzolos program megírása, ami képes alapvető matematikai műveleteket elvégezni, nem omlik össze, ha butaságot gépel be a felhasználó, és addig fut, amíg mi le nem állítjuk.
---
**A cél:** Egy olyan konzolos program megírása, ami képes alapvető matematikai műveleteket elvégezni, nem omlik össze, ha butaságot gépel be a felhasználó, és addig fut, amíg mi le nem állítjuk.

#### 1. Szint: Az alapok (Változók és beolvasás)

* Hozz létre két változót a számoknak. (Gondold át a típust: egy számológépnél gyakran osztunk, szóval az `int` nem biztos, hogy elég, érdemes `double`-t használni!)
* Hozz létre egy változót a műveleti jelnek (`+`, `-`, `*`, `/`). Milyen típus fér el egyetlen karakterben? Egy `char`!
* Kérd be a felhasználótól az első számot, utána a műveleti jelet, végül a második számot. (A `cin` tökéletes erre).

#### 2. Szint: A döntés (Elágazások)

* Itt az ideje irányítani a programot! Használj egy `switch` szerkezetet (vagy `if - else if` láncot), ami a beolvasott műveleti jel alapján eldönti, mit kell tenni.
* Végezd el a műveletet, és írasd ki az eredményt a képernyőre (pl.: `5 + 3 = 8`).
* **Tipp:** Ne felejts el egy `default` (vagy végső `else`) ágat is írni arra az esetre, ha a felhasználó mondjuk egy `x` betűt adna meg műveleti jelként! Ilyenkor írd ki, hogy "Érvénytelen művelet!".

#### 3. Szint: A védelem (Hibakezelés)

* A programozás egyik aranyszabálya: sose bízz a felhasználóban!
* Mi történik, ha az osztást (`/`) választja, és a második számnak `0`-t ad meg? A számítógép nullával osztásnál pánikba esik és a program összeomlik.
* Írj egy `if` feltételt az osztás ágába: ha a második szám `0`, írj ki egy hibaüzenetet (pl. "Nullával nem osztunk!"). Csak akkor végezd el az osztást, ha a második szám nem nulla.

#### 4. Szint: A végtelenített gép (Ciklusok) - *Haladó kihívás!*

* Bosszantó, hogy egy számolás után a program bezáródik, és újra el kell indítani, igaz?
* Tedd az egész beolvasós és számolós logikát egy `do-while` vagy `while` ciklusba!
* A számolás végén kérdezd meg a felhasználót: *"Szeretnél még számolni? (i/n)"*. Ha `i`-t (igaz) nyom, a ciklus induljon újra, és kérjen be új számokat. Ha `n`-t, a program köszönjön el és álljon le.
