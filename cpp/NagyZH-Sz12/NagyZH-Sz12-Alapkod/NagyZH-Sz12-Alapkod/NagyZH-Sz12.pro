TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dragon.cpp \
        main.cpp \
        party.cpp \
        tavern.cpp

HEADERS += \
    dragon.h \
    json.hpp \
    party.h \
    tavern.h

DISTFILES += \
    in-knights.json \
    in-mages.json \
    in-party-1.txt \
    in-party-2.txt \
    in-party-3.txt \
    in-rangers.json \
    minta-stdout.txt
