#-------------------------------------------------
#
# Project created by QtCreator 2013-10-09T12:26:45
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = ForkStabilityDisplay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    stabilitybarcanvas.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    stabilitybarcanvas.h

LIBS	+= -lGL

FORMS    += mainwindow.ui
