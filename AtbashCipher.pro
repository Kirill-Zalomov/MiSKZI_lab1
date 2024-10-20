QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    controller/controller.cpp \
    model/atbash_cipher.cpp \
    model/file_interactor.cpp \
    model/frequency_analyzer.cpp \
    model/frequency_dictionary_parser.cpp

HEADERS += \
    controller/controller.h \
    model/atbash_cipher.h \
    model/file_interactor.h \
    model/frequency_analyzer.h \
    model/frequency_dictionary_parser.h

FORMS += \
    view/mainwindow.ui

INCLUDEPATH += \
    model \
    view \
    controller \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
