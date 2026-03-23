TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    route.cpp \
    checkpoint.cpp \
    smartroute.cpp

HEADERS += megoldott_feladatok.h \
    route.h \
    checkpoint.h \
    smartroute.h

DISTFILES += minta-stdout.txt \
    feladatleiras.md \
    ellenorzes.sh \
    ellenorzes.ps1
