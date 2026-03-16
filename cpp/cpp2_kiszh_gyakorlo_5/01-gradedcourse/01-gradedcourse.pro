TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    course.cpp \
    grade.cpp \
    gradedcourse.cpp

HEADERS += megoldott_feladatok.h \
    course.h \
    grade.h \
    gradedcourse.h

DISTFILES += minta-stdout.txt \
    feladatleiras.md \
    ellenorzes.sh \
    ellenorzes.ps1
