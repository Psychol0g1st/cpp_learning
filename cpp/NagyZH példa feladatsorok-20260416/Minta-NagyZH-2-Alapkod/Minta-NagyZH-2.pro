TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

DISTFILES += \
    minta-stdout.txt \
    output-chairs.json \
    output-clothes.json \
    output-toys.json \
    stock-toys.json \
    stock-clothes.json \
    stock-chairs.json \
    shipment-1.json \
    shipment-2.json

HEADERS += \
    json.hpp
