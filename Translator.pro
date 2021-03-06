#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T10:13:35
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandyTranslator
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
    wordtranslator.cpp \
    translatorengine.cpp \
    bab_latranslatorengine.cpp \
    clipboardtranslator.cpp \
    mainwindow.cpp \
    applicationdescription.cpp

HEADERS  += \
    wordtranslator.h \
    translatorengine.h \
    bab_latranslatorengine.h \
    clipboardtranslator.h \
    mainwindow.h \
    applicationdescription.h

FORMS    += \
    clipboardtranslator.ui \
    mainwindow.ui \
    applicationdescription.ui
RC_FILE=translator.rc

RESOURCES += \
    resources.qrc
