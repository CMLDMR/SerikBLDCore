#CONFIG -= qt
QT += core xml network

TEMPLATE = lib
DEFINES += SERIKBLDCORE_LIBRARY

CONFIG += c++17

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


windows{

    gcc{
    message("GCC Version")
        win32: LIBS += -L$$PWD/../Mongo/gcc10.1x64/lib/ -llibbsoncxx.dll

        INCLUDEPATH += $$PWD/../Mongo/gcc10.1x64/include/bsoncxx/v_noabi
        DEPENDPATH += $$PWD/../Mongo/gcc10.1x64/include/bsoncxx/v_noabi



        win32: LIBS += -L$$PWD/../Mongo/gcc10.1x64/lib/ -llibmongocxx.dll

        INCLUDEPATH += $$PWD/../Mongo/gcc10.1x64/include/mongocxx/v_noabi
        DEPENDPATH += $$PWD/../Mongo/gcc10.1x64/include/mongocxx/v_noabi
    }


    msvc{
    MSVC_VER = $$(VisualStudioVersion)

    !contains(QMAKE_TARGET.arch, x86_64) {
        message("msvc2017x86")
            win32: LIBS += -L$$PWD/../Mongo/msvc2017x86/lib/ -lbsoncxx
            INCLUDEPATH += $$PWD/../Mongo/msvc2017x86/include/bsoncxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x86/include/bsoncxx/v_noabi
            win32: LIBS += -L$$PWD/../Mongo/msvc2017x86/lib/ -lmongocxx
            INCLUDEPATH += $$PWD/../Mongo/msvc2017x86/include/mongocxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x86/include/mongocxx/v_noabi
            INCLUDEPATH += $$PWD/../boost/msvcx86/boost_1_71_0
            DEPENDPATH += $$PWD/../boost/msvcx86/boost_1_71_0
    } else {

            INCLUDEPATH += $$PWD/../boost/boost
            DEPENDPATH += $$PWD/../boost/boost

    equals(MSVC_VER, 14.0){
        message("msvc 2015 x64")
            win32: LIBS += -L$$PWD/../Mongo/msvc2015x64/install/lib/ -lbsoncxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2015x64/install/include/bsoncxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2015x64/include/bsoncxx/v_noabi

            win32: LIBS += -L$$PWD/../Mongo/msvc2015x64/install/lib/ -lmongocxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2015x64/install/include/mongocxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2015x64/install/include/mongocxx/v_noabi

    }

    equals(MSVC_VER, 15.0){
        message("msvc 2017 x64")

            win32: LIBS += -L$$PWD/../Mongo/msvc2017x64/lib/ -lbsoncxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2017x64/include/bsoncxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x64/include/bsoncxx/v_noabi

            win32: LIBS += -L$$PWD/../Mongo/msvc2017x64/lib/ -lmongocxx

            INCLUDEPATH += $$PWD/../Mongo/msvc2017x64/include/mongocxx/v_noabi
            DEPENDPATH += $$PWD/../Mongo/msvc2017x64/include/mongocxx/v_noabi
    }



        ## Windows x64 (64bit) specific build here

    }
}

}

DISTFILES += \
    docs/annotated.html \
    docs/bc_s.png \
    docs/bdwn.png \
    docs/classes.html \
    docs/closed.png \
    docs/d0/d69/serikbldcore_8cpp_source.html \
    docs/d0/d71/class_serik_b_l_d_core_1_1_talep_key_1_1_kaynak_key.html \
    docs/d0/dc0/talepsubitem_8h_source.html \
    docs/d0/dc3/dilekcemanager_8h_source.html \
    docs/d1/d2b/class_serik_b_l_d_core_1_1_t_c_manager-members.html \
    docs/d1/d36/class_serik_b_l_d_core.html \
    docs/d1/d75/class_serik_b_l_d_core_1_1_dilekce-members.html \
    docs/d1/dff/class_serik_b_l_d_core_1_1_user.html \
    docs/d1/dff/class_serik_b_l_d_core_1_1_user.png \
    docs/d2/d2f/personelmanager_8h_source.html \
    docs/d2/d74/talep_8h_source.html \
    docs/d4/d43/qelement_8h_source.html \
    docs/d4/d71/_config_8h_source.html \
    docs/d4/da8/class_serik_b_l_d_core_1_1_talep_manager-members.html \
    docs/d4/df3/dilekcecevap_8h_source.html \
    docs/d4/df7/class_serik_b_l_d_core_1_1_d_b.html \
    docs/d4/df7/class_serik_b_l_d_core_1_1_d_b.png \
    docs/d4/dfd/struct_serik_b_l_d_core_1_1_talep_key_1_1_durum_pipeline_result.html \
    docs/d5/d6b/struct_serik_b_l_d_core_1_1_talep_key_1_1_durum_pipeline_result-members.html \
    docs/d5/da5/class_serik_b_l_d_core_1_1_personel_manager.html \
    docs/d5/da5/class_serik_b_l_d_core_1_1_personel_manager.png \
    docs/d5/de1/class_serik_b_l_d_core_1_1_personel.html \
    docs/d5/de1/class_serik_b_l_d_core_1_1_personel.png \
    docs/d6/d33/user_8cpp_source.html \
    docs/d6/d3d/class_serik_b_l_d_core_1_1_talep_key_1_1_durum_key.html \
    docs/d6/d54/class_serik_b_l_d_core_1_1_dilekce_aciklama-members.html \
    docs/d6/d5b/dilekcemanager_8cpp_source.html \
    docs/d6/d75/qoid_8h_source.html \
    docs/d6/db0/class_serik_b_l_d_core_1_1_t_c_manager.html \
    docs/d6/db0/class_serik_b_l_d_core_1_1_t_c_manager.png \
    docs/d6/df2/class_serik_b_l_d_core-members.html \
    docs/d7/d1b/talepmanager_8cpp_source.html \
    docs/d7/d57/md__c_1__serik_b_l_d_core__r_e_a_d_m_e.html \
    docs/d7/d68/tc_8h_source.html \
    docs/d7/d73/qarray_8h_source.html \
    docs/d7/d74/personel_8cpp_source.html \
    docs/d7/d7c/dilekcecevap_8cpp_source.html \
    docs/d7/d92/serikbldcore_8h_source.html \
    docs/d8/d01/class_serik_b_l_d_core_1_1_personel-members.html \
    docs/d8/d66/dilekce_8cpp_source.html \
    docs/d8/dc7/class_serik_b_l_d_core_1_1_item.html \
    docs/d8/dc7/class_serik_b_l_d_core_1_1_item.png \
    docs/d8/ddb/user_8h_source.html \
    docs/d8/dfc/class_serik_b_l_d_core_1_1_item-members.html \
    docs/d9/d00/class_serik_b_l_d_core_1_1_talep_key.html \
    docs/d9/d95/qarray_8cpp_source.html \
    docs/da/d07/personelmanager_8cpp_source.html \
    docs/da/d43/class_serik_b_l_d_core_1_1_talep-members.html \
    docs/da/d4e/db_8h_source.html \
    docs/da/d72/personel_8h_source.html \
    docs/da/d8b/class_serik_b_l_d_core_1_1_talep.html \
    docs/da/d8b/class_serik_b_l_d_core_1_1_talep.png \
    docs/da/d8b/qelement_8cpp_source.html \
    docs/da/d8c/dilekceaciklama_8h_source.html \
    docs/da/da8/struct_serik_b_l_d_core_1_1_talep_key_1_1_kaynak_pipeline_result.html \
    docs/da/dc5/class_serik_b_l_d_core_1_1_talep_manager.html \
    docs/da/dc5/class_serik_b_l_d_core_1_1_talep_manager.png \
    docs/da/df4/class_serik_b_l_d_core_1_1_talep_key_1_1_durum_key-members.html \
    docs/db/d29/tc_8cpp_source.html \
    docs/db/d6b/class_serik_b_l_d_core_1_1_t_c-members.html \
    docs/db/d74/qoid_8cpp_source.html \
    docs/db/d8c/class_serik_b_l_d_core_1_1_dilekce_manager-members.html \
    docs/db/da2/dilekce_8h_source.html \
    docs/dc/d65/class_serik_b_l_d_core_1_1_t_c.html \
    docs/dc/d65/class_serik_b_l_d_core_1_1_t_c.png \
    docs/dc/d82/class_serik_b_l_d_core_1_1_talep_sub_item.html \
    docs/dc/d82/class_serik_b_l_d_core_1_1_talep_sub_item.png \
    docs/dc/da2/class_serik_b_l_d_core_1_1_personel_manager-members.html \
    docs/dc/dcb/qdocument_8h_source.html \
    docs/dc/dd3/class_serik_b_l_d_core_1_1_dilekce_cevap.html \
    docs/dc/dd3/class_serik_b_l_d_core_1_1_dilekce_cevap.png \
    docs/dc/df0/talep_8cpp_source.html \
    docs/dc/df2/_serik_b_l_d_core__global_8h_source.html \
    docs/dd/d15/dilekceaciklama_8cpp_source.html \
    docs/dd/d99/talepsubitem_8cpp_source.html \
    docs/dd/daa/class_serik_b_l_d_core_1_1_dilekce_manager.html \
    docs/dd/daa/class_serik_b_l_d_core_1_1_dilekce_manager.png \
    docs/dd/db1/talepmanager_8h_source.html \
    docs/de/d05/tcmanager_8cpp_source.html \
    docs/de/d29/mongoheaders_8h_source.html \
    docs/de/d69/struct_serik_b_l_d_core_1_1_talep_key_1_1_kaynak_pipeline_result-members.html \
    docs/de/db5/class_serik_b_l_d_core_1_1_dilekce_cevap-members.html \
    docs/de/dc8/class_serik_b_l_d_core_1_1_user-members.html \
    docs/de/de4/item_8cpp_source.html \
    docs/de/df1/tcmanager_8h_source.html \
    docs/debug.log \
    docs/df/d08/class_serik_b_l_d_core_1_1_talep_sub_item-members.html \
    docs/df/d1f/item_8h_source.html \
    docs/df/d2b/class_serik_b_l_d_core_1_1_d_b-members.html \
    docs/df/d4e/db_8cpp_source.html \
    docs/df/d90/class_serik_b_l_d_core_1_1_dilekce.html \
    docs/df/d90/class_serik_b_l_d_core_1_1_dilekce.png \
    docs/df/d92/class_serik_b_l_d_core_1_1_talep_key-members.html \
    docs/df/daa/class_serik_b_l_d_core_1_1_dilekce_aciklama.html \
    docs/df/daa/class_serik_b_l_d_core_1_1_dilekce_aciklama.png \
    docs/df/def/class_serik_b_l_d_core_1_1_talep_key_1_1_kaynak_key-members.html \
    docs/df/def/qdocument_8cpp_source.html \
    docs/dir_83e00a2169ac40434a26818942081e0e.html \
    docs/dir_8e035d9dc690856fa4bdaf6316e5efd9.html \
    docs/dir_ca0c48d6bc5af1f8e64e6392d7d3f2db.html \
    docs/doc.png \
    docs/doxygen.css \
    docs/doxygen.png \
    docs/dynsections.js \
    docs/files.html \
    docs/folderclosed.png \
    docs/folderopen.png \
    docs/functions.html \
    docs/functions_func.html \
    docs/hierarchy.html \
    docs/index.hhc \
    docs/index.hhk \
    docs/index.hhp \
    docs/index.html \
    docs/jquery.js \
    docs/logo.png \
    docs/menu.js \
    docs/menudata.js \
    docs/nav_f.png \
    docs/nav_g.png \
    docs/nav_h.png \
    docs/open.png \
    docs/pages.html \
    docs/splitbar.png \
    docs/sync_off.png \
    docs/sync_on.png \
    docs/tab_a.png \
    docs/tab_b.png \
    docs/tab_h.png \
    docs/tab_s.png \
    docs/tabs.css









