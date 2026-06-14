TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fchair.cpp \
        ftable.cpp \
        furniture.cpp \
        fwardrobe.cpp \
        main.cpp \
        order.cpp \
        store.cpp

DISTFILES += \
    minta-stdout.txt \
    order1.json \
    order2.json \
    order3.json \
    stock-exported.json \
    stock.json

HEADERS += \
    fchair.h \
    ftable.h \
    furniture.h \
    fwardrobe.h \
    json.hpp \
    order.h \
    store.h
