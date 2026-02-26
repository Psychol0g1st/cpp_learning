---
title: 0. alkalom - A gép felkészítése
description: Fejlesztői környezet (IDE) telepítése, fordító beállítása és az első Hello World programunk.
---

Szia! Mielőtt belevágnánk a memóriacímek és mutatók sűrűjébe, fel kell készítenünk a gépünket arra, hogy megértse a C++ kódunkat. 

Mivel a számítógép (pontosabban a processzor) csak a nullákat és egyeseket érti (gépi kód), a mi C++ szövegünket le kell fordítani neki. Ehhez kell egy **fordító** (compiler). Emellett jó, ha van egy kényelmes kódszerkesztőnk, ami kiszínezi a kódot és segít megtalálni a hibákat. Ezt a kettőt együtt **IDE**-nek (Integrált Fejlesztői Környezetnek) hívjuk.

Két opciót mutatok be. Válaszd azt, amelyik szimpatikusabb!

---

## 1. Opció: Code::Blocks (A gyors és egyszerű)

Ha nem akarsz sokat bajlódni a beállításokkal, a Code::Blocks a legjobb barátod. Ez egy kicsit régies kinézetű, de kifejezetten C/C++-ra tervezett szoftver, ami (ha a jó verziót töltöd le) mindent tartalmaz, amire szükségünk lesz.

1. Menj a [Code::Blocks letöltési oldalára](https://www.codeblocks.org/downloads/binaries/).
2. Keresd meg a **Windows** szekciót.
3. **Nagyon fontos:** Olyan verziót válassz, aminek a nevében benne van a `mingw-setup.exe` (pl. `codeblocks-20.03mingw-setup.exe`). Ez tartalmazza magát a fordítót (GCC) is!
4. Telepítsd fel (Next, Next, Finish), indítsd el, és már kész is vagy.

---

## 2. Opció: Visual Studio Code (A modern és profi)

A Visual Studio Code (röviden VS Code) manapság a legnépszerűbb kódszerkesztő. Gyönyörű, testreszabható, de alapból "csak" egy szövegszerkesztő. Nekünk kell megmondani neki, hogy hol találja a C++ fordítót. Ha a modern utat választod, csináld végig ezt a pár lépést (kicsit hosszabb, de megéri!).

### 1. lépés: VS Code telepítése
Töltsd le és telepítsd fel a [Visual Studio Code](https://code.visualstudio.com/)-ot.

### 2. lépés: A fordító (MinGW-w64) letöltése MSYS2-vel
Windows alatt a legfrissebb GCC fordítót az MSYS2 nevű csomagkezelővel a legkönnyebb felrakni.

1. Töltsd le az [MSYS2 telepítőt](https://www.msys2.org/) és telepítsd fel (nyugodtan hagyd az alapértelmezett `C:\msys64` mappában).
2. A telepítés végén hagyd bepipálva a *Run MSYS2 now* opciót. Megnyílik egy fekete parancssor.
3. Másold be az alábbi parancsot a fekete ablakba, majd nyomj Entert:
```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

4. Amikor megkérdezi, hány csomagot akarsz telepíteni, csak nyomj egy **Enter**-t (így mindet felrakja). Amikor engedélyt kér a folytatásra, írj be egy **Y**-t és nyomj Entert. Várd meg, amíg lefut.

### 3. lépés: A Környezeti Változók (Path) beállítása

A Windowsnak tudnia kell, hol vannak ezek az új programok (a fordító).

1. A Windows Start menü keresőjébe írd be, hogy **Környezeti változók szerkesztése** (Edit environment variables for your account), és nyisd meg.
2. A felső (Felhasználói változók) listában keresd meg a **Path** nevű sort, kattints rá, majd válaszd a **Szerkesztés** (Edit) gombot.
3. Kattints az **Új** (New) gombra, és másold be ezt az útvonalat: `C:\msys64\ucrt64\bin`
4. Nyomj OK-t minden ablakon, hogy bezáruljanak.

*Ellenőrzés:* Nyiss egy teljesen új Windows Parancssort (cmd), és írd be: `g++ --version`. Ha kiír egy csomó szöveget a verziószámról, akkor jól csináltuk!

### Opcionális lépés: A fordító letöltése Linux Ubuntu operációs rendszerre
Kövesd a [VS Code dokumentációban](https://code.visualstudio.com/docs/cpp/config-linux) leírt lépéseket és telepítsd fel a g++ és gdb-t linux Ubuntu-ra.


### 4. lépés: A C++ bővítmény a VS Code-ban

Nyisd meg a VS Code-ot, kattints a bal oldali menüben az **Extensions** (Bővítmények) ikonra (vagy nyomj `Ctrl+Shift+X`-et). Keress rá a **C++** szóra, és telepítsd a Microsoft által készített "C/C++" bővítményt.

---

## Az első programunk: Hello World

Most, hogy megvagyunk a nehezével, próbáljuk is ki!

1. Hozz létre valahol a gépeden egy új mappát (pl. `cpp_tanulas`).
2. Nyisd meg ezt a mappát a VS Code-ban (`File -> Open Folder...`).
3. Hozz létre benne egy új fájlt `helloworld.cpp` néven.
4. Másold be az alábbi kódot, majd mentsd el (`Ctrl+S`):

```cpp
#include <iostream>

using namespace std;

int main() {

    cout << "Hello world!" << endl;

    return 0;
}
```

### Futatás VS Code-ban

1. Jobb felül keress egy kis lejátszás (Play) gombot, és kattints rá (vagy a mellette lévő kis lefelé mutató nyílra, és válaszd a **Run C/C++ File**-t).
2. Felül felugrik egy menü: válaszd a **C/C++: g++.exe build and debug active file** opciót.
3. A VS Code a háttérben létrehoz neked egy `.vscode` mappát (ebben tárolja a beállításokat), lefordítja a kódodat, és az alul megjelenő **Terminal** ablakban ki fogja írni, hogy: *Hello C++ Világ a VS Code-ból!*

Gratulálok! Megírtad, lefordítottad és lefuttattad a "Hello World!" C++ programot!

---

> Mi történt a háttérben? A `g++.exe` fogta a `helloworld.cpp` fájlodat, lefordította a gép nyelvére, és csinált belőle egy `helloworld.exe` futtatható programot. A Play gomb megnyomása után ezt indította el neked a terminálban.

### Fordítás és futtatás parancssorból (Windows) hiba elhárítás
[Ebben a cíkkben](https://medium.com/@chandanarajiv01/solved-c-code-not-compiling-in-vs-code-clock-gettime64-entry-point-not-found-error-gcc-15-2-0-b98ad83f42a2) olvasható néhány felmerülő probléma parancssorban való futtatás során és azokra való megoldások
