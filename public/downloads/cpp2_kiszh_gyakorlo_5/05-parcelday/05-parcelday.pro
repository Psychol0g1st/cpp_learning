TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    courierday.cpp \
    parcel.cpp \
    parcelday.cpp

HEADERS += megoldott_feladatok.h \
    courierday.h \
    parcel.h \
    parcelday.h

DISTFILES += minta-stdout.txt \
    feladatleiras.md \
    ellenorzes.sh \
    ellenorzes.ps1
