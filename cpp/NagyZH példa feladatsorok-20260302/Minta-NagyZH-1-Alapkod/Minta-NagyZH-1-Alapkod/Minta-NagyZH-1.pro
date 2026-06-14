TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

DISTFILES += \
    minta-stdout.txt \
    order1.json \
    order2.json \
    order3.json \
    stock-exported.json \
    stock.json

HEADERS += \
    json.hpp
