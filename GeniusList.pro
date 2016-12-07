QT += core sql
QT -= gui

CONFIG += c++11

TARGET = GeniusList
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    repositories/geniusrepository.cpp \
    services/servicelayer.cpp \
    ui/consoleui.cpp \
    repositories/datalayer.cpp \
    repositories/computerrepository.cpp \
    models/computermodel.cpp \
    models/geniusmodel.cpp \
    services/geniusservice.cpp \
    services/computerservice.cpp\
    repositories/computergeniusrepository.cpp \
    validation/computervalidation.cpp \
    validation/geniusvalidation.cpp \
    repositories/databasemanager.cpp

HEADERS += \
    repositories/geniusrepository.h \
    services/servicelayer.h \
    ui/consoleui.h \
    repositories/datalayer.h \
    repositories/computerrepository.h \
    models/computermodel.h \
    models/geniusmodel.h \
    services/geniusservice.h \
    services/computerservice.h \
    repositories/computergeniusrepository.h \
    validation/computervalidation.h \
    validation/geniusvalidation.h \
    repositories/databasemanager.h

