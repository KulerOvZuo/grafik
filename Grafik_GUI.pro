#-------------------------------------------------
#
# Project created by QtCreator 2014-06-18T20:00:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grafik_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cperson.cpp \
    cmodel.cpp \
    cmonth.cpp \
    cgraphicmonth.cpp \
    cgraphicbutton.cpp

HEADERS  += mainwindow.h \
    cperson.h \
    constants.h \
    cmodel.h \
    cmonth.h \
    cgraphicmonth.h \
    cgraphicbutton.h

FORMS    += mainwindow.ui
