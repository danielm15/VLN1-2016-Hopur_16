QT += core
QT -= gui

CONFIG += c++11

TARGET = GeniusList
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    servicelayer.cpp \
    genius.cpp \
    datalayer.cpp

HEADERS += \
    consoleui.h \
    servicelayer.h \
    genius.h \
    datalayer.h
