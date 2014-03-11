#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T09:57:17
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Cowboy
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += src/main.cpp \
            src/scene/component.cpp \
            src/scene/gameObject.cpp
HEADERS += src/scene/component.h \
            src/scene/gameObject.h
