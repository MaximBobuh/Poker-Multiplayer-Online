TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += \
    combinations.cpp \
    main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    card.h \
    card_deck.h \
    combinations.h
