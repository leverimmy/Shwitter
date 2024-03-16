QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customlistitemwidget.cpp \
    custompostitemwidget.cpp \
    login.cpp \
    main.cpp \
    post.cpp \
    postelement.cpp \
    postwindow.cpp \
    subscription.cpp \
    utils.cpp \
    widget.cpp

HEADERS += \
    customlistitemwidget.h \
    custompostitemwidget.h \
    login.h \
    post.h \
    postelement.h \
    postwindow.h \
    subscription.h \
    utils.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
