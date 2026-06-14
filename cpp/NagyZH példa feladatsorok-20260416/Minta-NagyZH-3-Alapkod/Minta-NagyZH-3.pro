TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

DISTFILES += \
    coupons-1.json \
    coupons-2.json \
    export-example-A.json \
    export-example-B.json \
    minta-stdout.txt \
    purchases.json

HEADERS += \
    json.hpp
