TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    canvas.cpp \
    example.cpp

HEADERS += megoldott_feladatok.h \
    canvas.h \
    example.h

DISTFILES += minta-stdout.txt \
    feladat.md
