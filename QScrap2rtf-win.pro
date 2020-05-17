QT       += core gui widgets

TARGET = src/QScrap2rtf
TEMPLATE = app

SOURCES += src/main.cpp\
    src/wizard.cpp \
    src/wizardpage1.cpp \
    src/wizardpage2.cpp \
    src/wizardpage3.cpp \
    src/wizardpage4.cpp \
    src/wizardpage5.cpp \
    src/helpers.cpp

HEADERS  += \
    src/wizard.h \
    src/wizardpage1.h \
    src/wizardpage2.h \
    src/wizardpage3.h \
    src/wizardpage4.h \
    src/wizardpage5.h \
    src/helpers.h

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

RC_FILE = QScrap2rtf-win.rc
