TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    station.cpp \
    measurement.cpp \
    weatherarchive.cpp

HEADERS += megoldott_feladatok.h \
    station.h \
    measurement.h \
    weatherarchive.h

DISTFILES += minta-stdout.txt \
    feladatleiras.md \
    ellenorzes.sh \
    ellenorzes.ps1
