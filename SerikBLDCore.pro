#CONFIG -= qt
QT += core

TEMPLATE = lib
DEFINES += SERIKBLDCORE_LIBRARY

CONFIG += c++14

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
    db.cpp \
    item.cpp \
    serikbldcore.cpp \
    user.cpp

HEADERS += \
    SerikBLDCore_global.h \
    db.h \
    item.h \
    mongoheaders.h \
    serikbldcore.h \
    user.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


windows{
    message ("Platform Windows")

    !contains(QMAKE_TARGET.arch, x86_64) {
        message("x86 build")
        msvc{
            message ("Compiler MSVC")
            win32: LIBS += -L$$PWD/../Mongo/msvc2017x86/lib/ -lbsoncxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2017x86/include/bsoncxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x86/include/bsoncxx/v_noabi

            win32: LIBS += -L$$PWD/../Mongo/msvc2017x86/lib/ -lmongocxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2017x86/include/mongocxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x86/include/mongocxx/v_noabi

            INCLUDEPATH += $$PWD/../boost/msvcx86/boost_1_71_0
            DEPENDPATH += $$PWD/../boost/msvcx86/boost_1_71_0

        }

    } else {
        message("x86_64 build")

        ## Windows x64 (64bit) specific build here

    }


}


