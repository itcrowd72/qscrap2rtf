QT       += core gui widgets

TARGET = src/qscrap2rtf
TEMPLATE = app

SOURCES += src/main.cpp\
    src/wizard.cpp \
    src/wizardpage1.cpp \
    src/wizardpage2.cpp \
    src/wizardpage3.cpp \
    src/wizardpage4.cpp \
    src/wizardpage5.cpp

HEADERS  += \
    src/wizard.h \
    src/wizardpage1.h \
    src/wizardpage2.h \
    src/wizardpage3.h \
    src/wizardpage4.h \
    src/wizardpage5.h

FORMS    += \
    data/wizard.ui \
    data/wizardpage1.ui \
    data/wizardpage2.ui \
    data/wizardpage3.ui \
    data/wizardpage4.ui \
    data/wizardpage5.ui

OBJECTS_DIR = src
MOC_DIR = src
UI_DIR = src

INSTALLS += target pixmaps language_rus mainmenu

target.path = /usr/bin

pixmaps.path = /usr/share/qscrap2rtf/pixmaps
pixmaps.files = data/pixmaps/*

TRANSLATIONS += po/ru/qscrap2rtf.ts

language_rus.files = po/ru/qscrap2rtf.qm
language_rus.path = /usr/share/locale/ru/LC_MESSAGES

mainmenu.path = /usr/share/applications
mainmenu.files = data/*.desktop
