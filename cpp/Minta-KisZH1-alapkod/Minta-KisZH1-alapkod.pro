TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    product.cpp \
    review.cpp

HEADERS += megoldott_feladatok.h \
    product.h \
    review.h

DISTFILES += minta-stdout.txt
