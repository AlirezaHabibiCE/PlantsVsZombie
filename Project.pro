QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Controller.cpp \
    Oak.cpp \
    Plant.cpp \
    Score.cpp \
    Shooter.cpp \
    Sun.cpp \
    SunFlower.cpp \
    View.cpp \
    Zombie.cpp \
    main.cpp \
    Block.cpp \
    Shooterboard.cpp \
    Sunflowerboard.cpp \
    OakBoard.cpp \
    CherryBoard.cpp \
    Plantboard.cpp \
    Cherry.cpp \
    Shovel.cpp \
    Button.cpp \
    Masterzombie.cpp

HEADERS += \
    Bullet.h \
    Controller.h \
    Oak.h \
    Plant.h \
    Score.h \
    Shooter.h \
    Sun.h \
    SunFlower.h \
    View.h \
    Zombie.h \
    Block.h \
    Shooterboard.h \
    Sunflowerboard.h \
    OakBoard.h \
    CherryBoard.h \
    Plantboard.h \
    Cherry.h \
    Shovel.h \
    Button.h \
    Masterzombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc
