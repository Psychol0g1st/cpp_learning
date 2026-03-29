TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    image.cpp \
    example.cpp

HEADERS += megoldott_feladatok.h \
    image.h \
    example.h

DISTFILES += minta-stdout.txt \
    feladat.md
