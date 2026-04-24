---
title: 07. Gyakorlo 3. KisZH feladatsorok
description: 5 uj, automatikusan ellenorizheto C++ gyakorlofeladatsor a minta 3. KisZH szerkezeteben.
---

Ez az oldal 5 darab, a minta 3. KisZH szerkezetet koveto gyakorlofeladatsort tartalmaz.
Mindegyik feladatsor ugyanarra az alapelvre epul:

- van egy sablon osztaly vagy sablon alapu adatgyujto feladatmag,
- a `main.cpp` automatikusan teszteli a megoldast,
- a `megoldott_feladatok.h` fajlban lehet reszenkent bekapcsolni a feladatokat,
- a `minta-stdout.txt` tartalmazza a helyes mintakimenetet,
- a `json.hpp` fajlt nem kell szerkeszteni, csak az alapkod melle bemasolni.

## Letöltés

- [Teljes gyakorlócsomag letöltése](/cpp_learning/downloads/miniZH-3-gyakorlo-feladatok.zip)

---

# 01 - Korhazi triage

Ebben a feladatsorban egy surgossegi osztaly napi triage-cimkeit kell osszesiteni. A cel egy olyan
`TriageCounter<T>` sablon osztaly megvalositasa, amely tetszoleges tipusu azonositohoz esetszamot tarol.

## PART1 - Alapmuveletek

Keszits egy `TriageCounter` osztaly sablont a `triagecounter.h` fajlban.

Az osztaly:

- egy `vector<T>` taroloban cimkeket tarol,
- egy `vector<int>` taroloban az azokhoz tartozo esetszamokat tarolja,
- konstruktor nelkuli legyen.

Valositsd meg az alabbi metodusokat:

- `getIndexOfTag`
- `addCase`
- `getCaseCount`

## PART2 - Indexelo operator

Legyen `[]` operator, amely egy cimkehez tartozo esetszamra ad vissza modosithato `int&` referenciat.
Ha a cimke meg nincs eltárolva, 0-s kezdoertekkel kell beszurni.

## PART3 - JSON kiiras

Legyen `<<` operator, amely a teljes tartalmat JSON tombkent irja ki.
Minden elemben szerepeljen:

- `"cases"`
- `"tag"`

Az indentalas 2 szokoz legyen.

## PART4 - Fajlbeolvasas

Az `extra.h` fajlban keszits `getWardFrequency` fuggvenyt, amely egy fajlbol whitespace szeparalt
osztalykódokat olvas be, es `TriageCounter<string>` objektumban osszesiti az elofordulasokat.

---

# 02 - Varosi bejelentesek

Ebben a feladatsorban onkormanyzati hibabejelenteseket kell kategoriankent osszesiteni. A kozi
adatmodell egy `IssueCounter<T>` sablon osztaly.

## PART1 - Alapmuveletek

Keszits `IssueCounter` sablon osztalyt az `issuecounter.h` fajlban.

Az osztaly tarolja:

- a hibatipusokat egy `vector<T>` taroloban,
- a hozzajuk tartozo bejelentesszamokat egy `vector<int>` taroloban.

Valositsd meg az alabbi metodusokat:

- `getIndexOfIssue`
- `addIssue`
- `getIssueCount`

## PART2 - Indexelo operator

Legyen `[]` operator, amely modosithato referenciat ad vissza egy hibatipus darabszamara.
Hianyzo elem eseten 0-val kell beszurni.

## PART3 - JSON kiiras

Legyen `<<` operator, amely JSON tombben irja ki az adatokat, `"count"` es `"issue"` kulcsokkal,
2 szokozes indentalassal.

## PART4 - Fajlbeolvasas

Az `extra.h` fajlban legyen `getIssueFrequency` fuggveny, amely whitespace szeparalt hibakodokat olvas,
es `IssueCounter<string>` objektumba gyujti az elofordulasi szamokat.

---

# 03 - Tomegkozlekedesi kesesek

Ez a feladatsor jaratazonositokhoz tartozo kesesi percek osszesiteserol szol. A kozi osztaly a
`DelayLedger<T>` sablon.

## PART1 - Alapmuveletek

Keszits `DelayLedger` sablon osztalyt a `delayledger.h` fajlban.

Az osztaly tarolja:

- a jaratazonositokat egy `vector<T>` taroloban,
- az osszesitett kesesi perceket egy `vector<int>` taroloban.

Valositsd meg az alabbi metodusokat:

- `getIndexOfRoute`
- `addDelay`
- `getTotalDelay`

Az `addDelay` egy jaratazonositot es egy pozitiv egesz perc erteket kapjon.

## PART2 - Indexelo operator

Legyen `[]` operator, amely a jarathoz tartozo kesesi percekre ad vissza `int&` referenciat.
Hianyzo jarat eseten 0-val kell beszurni.

## PART3 - JSON kiiras

Legyen `<<` operator, amely `"route"` es `"minutes"` kulcsokkal ir ki JSON tombot.

## PART4 - Fajlbeolvasas

Az `extra.h` fajlban legyen `loadDelays` fuggveny, amely whitespace szeparalt `jarat perc` parokat
olvas es `DelayLedger<string>` objektumba osszesiti a kesesi adatokat.

---

# 04 - Energetikai meresek

Ebben a feladatsorban intezmenyi meropontokhoz tartozo fogyasztasi adatokat kell osszesiteni.
A kozi osztaly az `EnergyLedger<T>` sablon.

## PART1 - Alapmuveletek

Keszits `EnergyLedger` sablon osztalyt az `energyledger.h` fajlban.

Az osztaly tarolja:

- a meroazonositokat egy `vector<T>` taroloban,
- az osszesitett fogyasztast egy `vector<double>` taroloban.

Valositsd meg az alabbi metodusokat:

- `getIndexOfMeter`
- `addReading`
- `getTotalConsumption`

Az `addReading` egy meroazonositot es egy `double` fogyasztasi erteket kapjon.

## PART2 - Indexelo operator

Legyen `[]` operator, amely a megadott merohoz tartozo osszesitett fogyasztasra ad vissza `double&`
referenciat. Hianyzo elem eseten 0.0-val kell beszurni.

## PART3 - JSON kiiras

Legyen `<<` operator, amely `"meter"` es `"kwh"` kulcsokkal irja ki a tartalmat JSON tombkent.

## PART4 - Fajlbeolvasas

Az `extra.h` fajlban legyen `loadConsumption` fuggveny, amely whitespace szeparalt `mero ertek`
parokat olvas es `EnergyLedger<string>` objektumba osszesiti a fogyasztasi adatokat.

---

# 05 - Elelmiszerbank adomanyok

Ebben a feladatsorban egy elelmiszerbank bejovo adomanyait kell kategoriankent osszesiteni.
A kozi osztaly a `DonationLedger<T>` sablon.

## PART1 - Alapmuveletek

Keszits `DonationLedger` sablon osztalyt a `donationledger.h` fajlban.

Az osztaly tarolja:

- az adomanykategoriakat egy `vector<T>` taroloban,
- a hozzajuk tartozo darabszamokat egy `vector<int>` taroloban.

Valositsd meg az alabbi metodusokat:

- `getIndexOfCategory`
- `addDonation`
- `getDonationCount`

Az `addDonation` egy kategoriat es egy pozitiv egesz darabszamot kapjon.

## PART2 - Indexelo operator

Legyen `[]` operator, amely egy kategoriara modosithato `int&` referenciat ad vissza.
Ha a kategoria hianyzik, 0-val kell beszurni.

## PART3 - JSON kiiras

Legyen `<<` operator, amely JSON tombkent irja ki a tartalmat `"category"` es `"items"` kulcsokkal.

## PART4 - Fajlbeolvasas

Az `extra.h` fajlban legyen `loadDonations` fuggveny, amely whitespace szeparalt `kategoria darab`
parokat olvas, es `DonationLedger<string>` objektumban osszegzi az atvett mennyisegeket.
