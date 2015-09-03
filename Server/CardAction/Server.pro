TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cardmanager.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cardmanager.h \
    pokermode.h \
    card.h



