#!/usr/bin/env bash
set -euo pipefail

OUT_BIN="ellenorzes.out"
OUT_TXT="aktualis-stdout.txt"

g++ -std=c++20 -Wall -Wextra -pedantic -O2 \
    main.cpp courierday.cpp parcel.cpp parcelday.cpp -o "$OUT_BIN"

./"$OUT_BIN" > "$OUT_TXT"

if diff -u minta-stdout.txt "$OUT_TXT"; then
    echo
    echo "Az ellenorzes sikeres: a kimenet egyezik."
else
    echo
    echo "Elteres van a vart kimenethez kepest."
    exit 1
fi
