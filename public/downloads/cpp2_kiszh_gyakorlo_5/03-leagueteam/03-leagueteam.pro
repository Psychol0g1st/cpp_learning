TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    team.cpp \
    matchresult.cpp \
    leagueteam.cpp

HEADERS += megoldott_feladatok.h \
    team.h \
    matchresult.h \
    leagueteam.h

DISTFILES += minta-stdout.txt \
    feladatleiras.md \
    ellenorzes.sh \
    ellenorzes.ps1
