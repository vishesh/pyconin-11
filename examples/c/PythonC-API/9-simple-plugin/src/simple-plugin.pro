#-------------------------------------------------
#
# Project created by QtCreator 2011-09-03T01:19:13
#
#-------------------------------------------------

QT       += core gui

TARGET = simple-plugin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp 

HEADERS  += mainwindow.h \
    canvas.h

CONFIG += link_pkgconfig
PKGCONFIG += python-2.7
