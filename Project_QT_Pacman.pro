QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ghost.cpp \
    main.cpp \
    map.cpp \
    pacman.cpp \
    point.cpp \
    powerpoint.cpp \
    textManagment.cpp \
    window.cpp

HEADERS += \
    ghost.h \
    map.h \
    pacman.h \
    point.h \
    powerpoint.h \
    textManagment.h \
    window.h

FORMS += \
    window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    Project_QT_Pacman.pro.user
