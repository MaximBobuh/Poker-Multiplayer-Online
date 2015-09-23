TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    combinations.cpp \
    game.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    card.h \
    card_deck.h \
    combinations.h \
    game.h

