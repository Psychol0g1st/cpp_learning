TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bchair.cpp \
        bclothes.cpp \
        bproduct.cpp \
        btoy.cpp \
        main.cpp \
        shipment.cpp \
        warehouse.cpp

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
    bchair.h \
    bclothes.h \
    bproduct.h \
    btoy.h \
    json.hpp \
    shipment.h \
    warehouse.h
