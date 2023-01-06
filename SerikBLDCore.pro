#CONFIG -= qt
QT += core xml network

TEMPLATE = lib
DEFINES += SERIKBLDCORE_LIBRARY

#CONFIG += c++17
QMAKE_CXXFLAGS      += /Zc:__cplusplus
QMAKE_CXXFLAGS += /std:c++latest
#QMAKE_CXXFLAGS_CXX2A = -std:c++20

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Talep/talep.cpp \
    Talep/talepkategori.cpp \
    Talep/talepkategorimanager.cpp \
    Talep/talepmanager.cpp \
    Talep/talepsubitem.cpp \
    bilgiEdinme/bilgiedinmeitem.cpp \
    bilgiEdinme/bilgiedinmemanager.cpp \
    calisma/calismaitem.cpp \
    calisma/calismamanager.cpp \
    core/core.cpp \
    core/element.cpp \
    core/object.cpp \
    db.cpp \
    dilekce.cpp \
    dilekceaciklama.cpp \
    dilekcecevap.cpp \
    dilekcemanager.cpp \
    faaliyetrapor/faaliyetrapor.cpp \
    firma/firmaitem.cpp \
    firma/firmamanager.cpp \
    imar/mimarilog.cpp \
    imar/mimariproje.cpp \
    imar/mimariprojemanager.cpp \
    item.cpp \
    listitem.cpp \
    meclis/meclisitem.cpp \
    meclis/meclismanager.cpp \
    meclis/meclisuyesi.cpp \
    personel.cpp \
    personelmanager.cpp \
    qbson/qarray.cpp \
    qbson/qdocument.cpp \
    qbson/qelement.cpp \
    qbson/qoid.cpp \
    serikbldcore.cpp \
    sms/smsabstrackmanager.cpp \
    sms/smsitem.cpp \
    stok/stok.cpp \
    stok/stokkategorimanager.cpp \
    stok/stokv2.cpp \
    stok/stokv2manager.cpp \
    tc.cpp \
    tcmanager.cpp \
    user.cpp

HEADERS += \
    Config.h \
    SerikBLDCore_global.h \
    Talep/talep.h \
    Talep/talepkategori.h \
    Talep/talepkategorimanager.h \
    Talep/talepmanager.h \
    Talep/talepsubitem.h \
    bilgiEdinme/bilgiedinmeitem.h \
    bilgiEdinme/bilgiedinmemanager.h \
    calisma/calismaitem.h \
    calisma/calismamanager.h \
    core/core.h \
    core/element.h \
    core/object.h \
    db.h \
    dilekce.h \
    dilekceaciklama.h \
    dilekcecevap.h \
    dilekcemanager.h \
    faaliyetrapor/faaliyetrapor.h \
    firma/firmaitem.h \
    firma/firmamanager.h \
    imar/mimarilog.h \
    imar/mimariproje.h \
    imar/mimariprojemanager.h \
    item.h \
    listitem.h \
    meclis/meclisitem.h \
    meclis/meclismanager.h \
    meclis/meclisuyesi.h \
    mongoheaders.h \
    personel.h \
    personelmanager.h \
    qbson/qarray.h \
    qbson/qdocument.h \
    qbson/qelement.h \
    qbson/qoid.h \
    serikbldcore.h \
    sms/smsabstrackmanager.h \
    sms/smsitem.h \
    stok/stok.h \
    stok/stokkategorimanager.h \
    stok/stokv2.h \
    stok/stokv2manager.h \
    tc.h \
    tcmanager.h \
    user.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

#INCLUDEPATH += $$PWD/../boost/boost
#DEPENDPATH += $$PWD/../boost/boost


win32: LIBS += -L$$PWD/../Mongo/mongo-msvc2022x64-noBoost/lib/ -lbsoncxx

INCLUDEPATH += $$PWD/../Mongo/mongo-msvc2022x64-noBoost/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/../Mongo/mongo-msvc2022x64-noBoost/include/bsoncxx/v_noabi

win32: LIBS += -L$$PWD/../Mongo/mongo-msvc2022x64-noBoost/lib/ -lmongocxx

INCLUDEPATH += $$PWD/../Mongo/mongo-msvc2022x64-noBoost/include/mongocxx/v_noabi
DEPENDPATH += $$PWD/../Mongo/mongo-msvc2022x64-noBoost/include/mongocxx/v_noabi










