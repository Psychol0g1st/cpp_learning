---
title: 06. Absztrakt osztályok és polimorfizmus
description: A "Többalakúság" varázslata. Hogyan írjunk olyan okos kódot, ami a jövőben hozzáadott elemekkel is automatikusan működik?
---

Szia! Most, hogy már értjük az osztályokat (OOP) és az öröklődést, elérkeztünk a C++ egyik leggyönyörűbb és leginkább "mérnöki" koncepciójához.

Eddig azt láttuk, hogy az öröklődéssel kód-ismétlést tudunk megspórolni. De van egy sokkal nagyobb szuperereje is: a **Polimorfizmus** (többalakúság) és az **Absztrakt Osztályok**. Ha ezt megérted, onnantól kezdve profi szoftverarchitektúrákat fogsz tudni tervezni!

---

## 1. A Probléma: Túl általános fogalmak

Képzeld el, hogy írunk egy rajzoló programot. Vannak benne Körök, Téglalapok és Háromszögek. Mivel mindegyiknek van színe és X, Y koordinátája, logikus, hogy csinálunk nekik egy közös ősosztályt: az `Alakzat`-ot.

```cpp
class Alakzat {
protected:
    string szin;
public:
    Alakzat(string szin) { this->szin = szin; }
    void rajzol() {
        cout << "Rajzolok egy alakzatot..." << endl; // De milyet?!
    }
};
```

**Mi ezzel a gond?**
1.  A való világban nem létezik olyan dolog, hogy "csak egy alakzat". Vagy egy kört rajzolsz, vagy egy téglalapot. A puszta `Alakzat` létrehozása (`Alakzat a("piros");`) logikailag értelmetlen.
2.  Minden formának *teljesen más* a rajzolási algoritmusa vagy a területszámító képlete. Ezt nem tudjuk megírni az ősosztályban!

---

## 2. A Megoldás: Az Absztrakt Osztály

Meg kell mondanunk a C++-nak: *"Figyelj, az `Alakzat` csak egy gyűjtőfogalom. Sose engedd, hogy valaki csak úgy létrehozzon egyet! Viszont kötelezz mindenkit, aki az `Alakzat`-ból származik, hogy írja meg a SAJÁT rajzoló függvényét!"*

Ezt a **tisztán virtuális függvény (pure virtual function)** segítségével érjük el.

A szintaxis nagyon furcsa, de meg kell jegyezni: a függvény deklarációja után odaírunk egy `= 0`-t.

```cpp
class Alakzat {
protected:
    string szin;
public:
    Alakzat(string szin) { this->szin = szin; }
    
    // TISZTÁN VIRTUÁLIS FÜGGVÉNY (= 0)
    // Ezzel azt mondjuk: "Nincs megírva a kódja, a gyerekeknek KÖTELEZŐ megírni!"
    // Ettől a sortól kezdve az osztály ABSZTRAKT lett.
    virtual void rajzol() = 0; 
    
    // VIRTUÁLIS DESTRUKTOR (Erről lentebb részletesen beszélünk!)
    virtual ~Alakzat() {} 
};
```

Ha most megpróbálod a `main`-ben beírni, hogy `Alakzat a("Kek");`, a fordító azonnal hibát dob: *Cannot declare variable 'a' to be of abstract type 'Alakzat'*. Szuper, megvédtük a kódunkat a butaságoktól!

---

## 3. A Leszármazottak: A Kötelezettség Teljesítése

Most hozzuk létre a konkrét formákat. Mivel ők az `Alakzat`-ból örökölnek, a fordító pisztolyt tart a fejükhöz: *"Vagy megírod a rajzol() függvényt, vagy te is absztrakt maradsz!"*

Az `override` (felülbírálás) kulcsszóval jelezzük a gépnek (és a többi programozónak), hogy itt most az ős kötelező függvényét valósítjuk meg.

```cpp
class Kor : public Alakzat {
private:
    int sugar;
public:
    Kor(string szin, int sugar) : Alakzat(szin) {
        this->sugar = sugar;
    }

    // Megírjuk a kötelező függvényt!
    void rajzol() override {
        cout << szin << " szinu Kor rajzolasa, sugar: " << sugar << endl;
    }
};

class Teglalap : public Alakzat {
private:
    int a, b;
public:
    Teglalap(string szin, int a, int b) : Alakzat(szin) {
        this->a = a;
        this->b = b;
    }

    void rajzol() override {
        cout << szin << " szinu Teglalap rajzolasa, oldalak: " << a << ", " << b << endl;
    }
};
```

---

## 4. A Polimorfizmus (Többalakúság) Varázslata

Oké, eddig sok volt a gépelés, de mi benne a jó? **A mutatók!** A C++ legszebb szabálya: **Egy ősosztály típusú mutatóval (`Alakzat*`) rámutathatsz a gyerekosztályok objektumaira (`Kor`, `Teglalap`)!**

Így egyetlen közös tömbbe tudod pakolni az összes különböző formádat, és egyetlen egyszerű ciklussal tudod kezelni őket. A gép majd futás közben (dinamikusan) kitalálja, hogy épp melyik alakzat `rajzol()` függvényét kell lefuttatnia. Ez a Polimorfizmus!

```cpp
int main() {
    // 1. Csinálunk egy tömböt, ami Alakzat MUTATÓKAT tárol
    Alakzat* vaszon[3];

    // 2. Beleteszünk teljesen KÜLÖNBÖZŐ gyerek objektumokat
    vaszon[0] = new Kor("Piros", 10);
    vaszon[1] = new Teglalap("Kek", 20, 30);
    vaszon[2] = new Kor("Zold", 5);

    // 3. A Varázslat: Egyetlen ciklus kezeli az összeset!
    cout << "--- Rajzolas inditasa ---" << endl;
    for (int i = 0; i < 3; i++) {
        // Bár a mutató "Alakzat*" típusú, a gép tudja, hogy a memóriában 
        // valójában egy Kör vagy Téglalap van, és a JÓ függvényt hívja meg!
        vaszon[i]->rajzol(); 
    }

    // 4. Memória felszabadítása
    for (int i = 0; i < 3; i++) {
        delete vaszon[i];
    }

    return 0;
}
```

**Kimenet:**
```text
--- Rajzolas inditasa ---
Piros szinu Kor rajzolasa, sugar: 10
Kek szinu Teglalap rajzolasa, oldalak: 20, 30
Zold szinu Kor rajzolasa, sugar: 5
```

Látod, miért zseniális ez? Ha jövőre egy kollégád hozzáad egy `Haromszog` osztályt a programhoz, a `main` függvényben lévő rajzoló `for` ciklushoz **hozzá sem kell nyúlnia**! Automatikusan működni fog az új alakzattal is.

---

## 5. A Csendes Gyilkos: Miért kell a Virtuális Destruktor?

Az `Alakzat` osztályban írtunk egy ilyet: `virtual ~Alakzat() {}`. Ezt hajlamosak vagyunk elfelejteni, pedig enélkül a programunk egy időzített bomba.

**Mi történik, ha nincs ott a `virtual` szó a destruktornál?**
Amikor a `main` végén kiadjuk a `delete vaszon[i];` parancsot, a gép megnézi a mutató típusát. *"Aha, ez egy `Alakzat*`. Akkor lefuttatom az `Alakzat` destruktorát, és letörlöm."*

CSAKHOGY a memóriában igazából egy `Kor` vagy `Teglalap` van! Ha a `Teglalap`-nak véletlenül lenne saját dinamikus memóriája (pl. fájlokat nyitott meg, vagy `new`-val foglalt saját tömböt), az ő saját destruktora **sosem futna le**, mert a gép leragadt az ősosztály szintjén. Eredmény: brutális memóriaszivárgás.

**A Szabály:** Ha egy osztályban van legalább egy `virtual` függvény (vagyis polimorfizmusra használod), akkor a **destruktorának is KÖTELEZŐEN `virtual`-nak kell lennie!** Így a `delete` parancsnál a gép tudni fogja: *"Hoppá, várjunk csak, ez egy virtuális cucc! Megnézem a memóriában, mi ez valójában... Aha, ez egy Téglalap! Akkor a Téglalap destruktorát hívom meg!"*

---

### Összefoglalás
* **Absztrakt Osztály:** Olyan osztály, amiben van legalább egy `= 0` (tisztán virtuális) függvény. Nem lehet belőle objektumot példányosítani.
* **Polimorfizmus:** Amikor egy ősosztály mutatóján (`Alakzat*`) keresztül egy leszármazott objektumot (`Kor`) kezelünk, és a rendszer futásidőben dinamikusan dönt a helyes függvényhívásról.
* **Virtuális Destruktor:** Életmentő dolog, ami biztosítja, hogy a leszármazottak memóriája is rendesen kitakarítódjon polimorf törlés (`delete`) esetén.
