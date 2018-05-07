#-------------------------------------------------
#
# Project created by QtCreator 2018-05-04T10:01:05
#
#-------------------------------------------------

QT       += core gui
QT += sql

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VivaAvion
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    vervuelos.cpp \
    verhoteles.cpp \
    verreservas.cpp \
    vervuelosadmin.cpp \
    verhotelesadmin.cpp \
    agregarvuelo.cpp \
    agregarhotel.cpp \
    reservasvuelos.cpp \
    reservashoteles.cpp \
    infocliente.cpp \
    verinfocliente.cpp

HEADERS += \
        mainwindow.h \
    vervuelos.h \
    verhoteles.h \
    verreservas.h \
    vervuelosadmin.h \
    verhotelesadmin.h \
    agregarvuelo.h \
    agregarhotel.h \
    reservasvuelos.h \
    reservashoteles.h \
    infocliente.h \
    verinfocliente.h

FORMS += \
        mainwindow.ui \
    vervuelos.ui \
    verhoteles.ui \
    verreservas.ui \
    vervuelosadmin.ui \
    verhotelesadmin.ui \
    agregarvuelo.ui \
    agregarhotel.ui \
    reservasvuelos.ui \
    reservashoteles.ui \
    infocliente.ui \
    verinfocliente.ui

DISTFILES += \
    ../Cuarto Semestre/Bases de datos/Consultar.sql \
    ../Cuarto Semestre/Bases de datos/Crear.sql \
    ../Cuarto Semestre/Bases de datos/Insertar.sql \
    Crear.sql \
    Insertar.sql
