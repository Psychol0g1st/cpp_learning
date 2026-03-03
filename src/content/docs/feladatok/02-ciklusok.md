---
title: 02. Ciklusok
description: A ciklusok megértése a programozás egyik legfontosabb lépése. 5 izgalmas, C++ feladatot kifejezetten mindhárom ciklusfajtát (for, while, do-while) gyarkolásra.
---

### 1. Feladat: A Varázslótanonc Vizsgája (`for` ciklus)

**A sztori:** Kezdő varázsló vagy, és a vizsgádon a "Tűzgolyó" varázslatot kell tökéletesítened. A mestered azt kéri, hogy süss el pontosan 10 tűzgolyót egymás után. Minden egyes kilőtt tűzgolyó egyre erősebb lesz.
**A feladat:**
Készíts egy programot, ami egy `for` ciklus segítségével 10-szer kiírja a képernyőre, hogy "Tűzgolyó kilőve!". Emellett a varázslat erejét is írd ki, ami az elsőnél 10, a másodiknál 20, és így tovább egészen 100-ig.

### 2. Feladat: Mentőakció a Marson (`while` ciklus)

**A sztori:** A marsi bázisról elindítottál egy mentő drónt, de megsérült az akkumulátora. Jelenleg 100%-os töltöttségen van. A drón minden megtett kilométer után veszít 7% energiát. Csak addig repülhet biztonságosan, amíg az energiája 15% alá nem esik, különben lezuhan.
**A feladat:**
Írj egy `while` ciklust, ami addig fut, amíg a drón energiája nagyobb vagy egyenlő, mint 15. Minden kilométer megtétele után vond le a 7%-ot, és írd ki a képernyőre: *"Megtett táv: X km. Hátralévő energia: Y%."
* (A kilométereket egy külön változóban számold!)

### 3. Feladat: A Kalózok Elátkozott Kincsesládája (`do-while` ciklus)

**A sztori:** Megtaláltad Feketeszakáll kincsesládáját, amit egy számkódos lakat véd. A zárat mindenképpen meg kell próbálnod kinyitni (legalább egyszer), de ha rossz kódot adsz meg, a láda kinevet, és újra próbálkozhatsz. A helyes kód: **7355**.
**A feladat:**
Használj egy `do-while` ciklust! A program kérjen be a felhasználótól (tőled) egy PIN kódot a `cin` segítségével. Ha a kód nem 7355, írja ki, hogy *"Haha, rossz jelszó, te tengeri patkány! Próbáld újra!"*. A ciklus addig ismétlődjön, amíg be nem ütöd a helyes kódot. Ha sikerül, írja ki: *"A láda kinyílt!"*.

* *Miért `do-while`?* Mert a kódot mindenképp be kell kérni legalább egyszer, mielőtt ellenőriznéd!

### 4. Feladat: Sárkányetetés Extrákkal (`for` ciklus + `if` feltétel)

**A sztori:** Te vagy a királyi sárkánygondozó. A sárkányodnak pontosan 20 darab húst kell adnod egy nap. Csakhogy a sárkány nagyon válogatós: minden 3. húsdarab után (3., 6., 9. stb.) egy hatalmasat tüsszent a fűszerezés miatt, és lángcsóvát lő az égre.
**A feladat:**
Írj egy `for` ciklust, ami elszámol 1-től 20-ig. Minden számnál írja ki, hogy *"A sárkány megevett X darab húst. Nyamm!"*. DE ha a szám osztható 3-mal (használd a modulo `%` operátort!), akkor a "Nyamm!" helyett azt írja ki: *"Hatalmas lángcsóva! A sárkány tüsszentett!"*.

### 5. Feladat: A Végtelen Útvesztő (`while` vagy `do-while` ciklus)

**A sztori:** Egy sötét katakombában bolyongsz. Minden kereszteződésnél döntened kell, merre mész: Észak (W), Dél (S), Kelet (D) vagy Nyugat (A). A bolyongásnak csak akkor van vége, ha megtalálod a titkos kijáratot, amit az 'E' (Escape) gomb megnyomása szimbolizál.
**A feladat:**
Hozz létre egy karakter (char) változót az iránynak. Készíts egy ciklust, ami folyamatosan bekér egy betűt a játékostól (cin). A program reagáljon a betűkre (pl. ha 'W', írja ki: *"Észak felé haladsz."*). A ciklus fusson mindaddig, amíg a játékos be nem gépeli az 'E' betűt. Ekkor a program lépjen ki a ciklusból, és írja ki: *"Kijutottál az útvesztőből!"*.

---

**Tipp a teszteléshez:** Érdemes mindegyik feladatot egy külön C++ projektben, vagy egy projekten belül, de külön fájlokban amelyeket kizársz a fordítási folyamatból, hogy ne akadjanak össze a kódjaid.
