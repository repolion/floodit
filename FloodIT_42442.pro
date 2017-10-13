#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T19:18:44
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FloodIT_42442
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    model/board.cpp \
    model/floodgame.cpp \
    model/position.cpp \
    model/square.cpp \
    observer/observable.cpp \
    observer/observer.cpp \
    view/mybutton.cpp \
    view/viewboard.cpp \
    view/buttonwidget.cpp \
    view/intro.cpp \
    view/mainwindow.cpp \
    view/menustart.cpp \
    view/options.cpp \
    view/widgetGame.cpp \
    model/HighScore.cpp

HEADERS  += \
    model/board.h \
    model/color.h \
    model/floodgame.h \
    model/position.h \
    model/square.h \
    observer/observable.h \
    observer/observer.h \
    view/buttonwidget.h \
    view/intro.h \
    view/mainwindow.h \
    view/menustart.h \
    view/mybutton.h \
    view/options.h \
    view/viewboard.h \
    view/widgetGame.h \
    model/HighScore.h

FORMS    += mainwindow.ui
