TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cmonthly.cpp \
        cmulti.cpp \
        coupon.cpp \
        csingle.cpp \
        main.cpp \
        purchase.cpp \
        purchaseitem.cpp \
        wallet.cpp

DISTFILES += \
    coupons-1.json \
    coupons-2.json \
    export-example-A.json \
    export-example-B.json \
    minta-stdout.txt \
    purchases.json

HEADERS += \
    cmonthly.h \
    cmulti.h \
    coupon.h \
    csingle.h \
    json.hpp \
    purchase.h \
    purchaseitem.h \
    wallet.h
