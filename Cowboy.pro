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


SOURCES +=  src/main.cpp \
            src/scene/component.cpp \
            src/scene/gameObject.cpp \
            src/scene/components/gocVisual.cpp \
            src/scene/components/gocVisualSphere.cpp \
            src/scene/components/gocVisualRectangle.cpp \
            src/math/float3.cpp
    src/scene/components/gocVisualRectangle.cpp
HEADERS +=  src/scene/component.h \
            src/scene/gameObject.h \
            src/scene/components/gocVisual.h \
            src/scene/components/gocVisualSphere.h \
            src/scene/components/gocVisualRectangle.h \
            src/math/float3.h \
            src/commonTypeDefs.h

QMAKE_CXXFLAGS_RELEASE += -D_NDEBUG
CONFIG += c++11
