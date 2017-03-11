#-------------------------------------------------
#
# Project created by QtCreator 2017-02-20T18:51:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = figures
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    figure.cpp \
    triangle.cpp \
    polygon.cpp \
    circle.cpp

HEADERS  += mainwindow.h \
    figure.hpp \
    triangle.hpp \
    polygon.hpp \
    circle.hpp

FORMS    += mainwindow.ui
