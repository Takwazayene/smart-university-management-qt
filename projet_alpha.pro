#-------------------------------------------------
#
# Project created by QtCreator 2018-11-25T18:35:28
#
#-------------------------------------------------



QT       += core gui network
QT       += sql

QT       += printsupport

QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet_alpha

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.



# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    abonnepark.cpp \
    parking.cpp \
    secteur.cpp \
    places.cpp \
    universite.cpp \
    bloc.cpp \
    integration.cpp \
    bienvenu.cpp \
    gestionabowindow.cpp \
    etudiant.cpp \
    abonneresto.cpp \
    menu.cpp \
    menuwindow.cpp \
    note_menu.cpp \
    etudiantwindow.cpp \
    bienvenufoyer.cpp \
    gestion.cpp \
    prod.cpp \
    chambreswindow.cpp \
    bienvenuclasse.cpp \
    etudiantclasse.cpp \
    appel.cpp \
    sallewindow.cpp \
    salleclasse.cpp \
    qcustomplot.cpp \
    statistique.cpp \
    Smtp.cpp \
    mailing.cpp \
    arduino.cpp \
    arduinowindow.cpp \
    classe.cpp \
    absent.cpp \
    bienenudistr.cpp \
    produits.cpp \
    produit.cpp \
    machine.cpp \
    machinewindow.cpp \
    achat.cpp \
    vente.cpp \
    ventewindow.cpp

HEADERS += \
        mainwindow.h \
    connection.h \
    abonnepark.h \
    parking.h \
    secteur.h \
    places.h \
    universite.h \
    bloc.h \
    integration.h \
    bienvenu.h \
    gestionabowindow.h \
    etudiant.h \
    abonneresto.h \
    menu.h \
    menuwindow.h \
    note_menu.h \
    etudiantwindow.h \
    bienvenufoyer.h \
    gestion.h \
    prod.h \
    chambreswindow.h \
    bienvenuclasse.h \
    etudiantclasse.h \
    appel.h \
    sallewindow.h \
    salleclasse.h \
    qcustomplot.h \
    statistique.h \
    Smtp.h \
    mailing.h \
    arduino.h \
    arduinowindow.h \
    classe.h \
    absent.h \
    bienenudistr.h \
    produits.h \
    produit.h \
    machine.h \
    machinewindow.h \
    achat.h \
    vente.h \
    ventewindow.h

FORMS += \
        mainwindow.ui \
    integration.ui \
    bienvenu.ui \
    gestionabowindow.ui \
    menuwindow.ui \
    etudiantwindow.ui \
    bienvenufoyer.ui \
    gestion.ui \
    chambreswindow.ui \
    bienvenuclasse.ui \
    appel.ui \
    statistique.ui \
    mailing.ui \
    arduinowindow.ui \
    classe.ui \
    bienenudistr.ui \
    produit.ui \
    machinewindow.ui \
    achat.ui \
    ventewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
