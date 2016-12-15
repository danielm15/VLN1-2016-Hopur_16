#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T12:45:48
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeniusList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        repositories/geniusrepository.cpp \
        repositories/computerrepository.cpp \
        models/computermodel.cpp \
        models/geniusmodel.cpp \
        services/geniusservice.cpp \
        services/computerservice.cpp\
        repositories/computergeniusrepository.cpp \
        repositories/databasemanager.cpp \
        services/computergeniusservice.cpp \
    addcomputer.cpp \
    addgenius.cpp \
    edithcpdialog.cpp

HEADERS  += mainwindow.h\
            repositories/geniusrepository.h \
            repositories/computerrepository.h \
            models/computermodel.h \
            models/geniusmodel.h \
            services/geniusservice.h \
            services/computerservice.h \
            repositories/computergeniusrepository.h \
            repositories/databasemanager.h \
            services/computergeniusservice.h \
    addcomputer.h \
    addgenius.h \
    edithcpdialog.h

FORMS    += mainwindow.ui \
    addcomputer.ui \
    addgenius.ui \
    edithcpdialog.ui

RESOURCES += \
    resources.qrc
