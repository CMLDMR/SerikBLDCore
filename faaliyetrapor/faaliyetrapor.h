#ifndef FAALIYETRAPOR_H
#define FAALIYETRAPOR_H


#include <item.h>
#include <listitem.h>
#include <memory.h>

namespace SerikBLDCore{


namespace Faaliyet{



class SERIKBLDCORE_EXPORT FaaliyetItem : public SerikBLDCore::Item{
public:
    explicit FaaliyetItem();

    FaaliyetItem& setBirim( const std::string &birim );
    std::string getBirim() const;

    FaaliyetItem& setYil( const std::int64_t &yil );
    std::int64_t getYil() const;

    FaaliyetItem& setFaaliyet( const bsoncxx::array::view &view );
    bsoncxx::array::view getFaaliyetView() const;
};



namespace Key {
static const std::string Collection{"faaliyetRapor"};
static const std::string text{"text"};
static const std::string type{"type"};
static const std::string uuid{"uuid"};
static const std::string parentuuid{"parentUuid"};

namespace Type {
static const std::string baslik{"baslik"};
static const std::string altBaslik{"altBaslik"};
static const std::string paragraf{"paragraf"};
static const std::string img{"img"};
static const std::string table{"table"};
}

}




class SERIKBLDCORE_EXPORT RaporItem : public SerikBLDCore::Item{
public:
    explicit RaporItem();

    RaporItem( const RaporItem &other );
    RaporItem( RaporItem &&other );

    RaporItem& operator=( const RaporItem &other );
    RaporItem& operator=( RaporItem &&other );


    RaporItem& setText( const std::string &text );
    std::string getText() const;

    std::string uuid() const;

    RaporItem& setParentUuid( const std::string &uuid );
    std::string parentUuid() const;


    bool isBaslik() const;
    bool isAltBaslik() const;
    bool isParagraf() const;
    bool isImg() const;
    bool isTable() const;


};


class SERIKBLDCORE_EXPORT BaslikItem : public RaporItem{
public:
    explicit BaslikItem();
};

class SERIKBLDCORE_EXPORT AltBaslikItem : public RaporItem{
public:
    explicit AltBaslikItem();
};

class SERIKBLDCORE_EXPORT ParagrafItem : public RaporItem{
public:
    explicit ParagrafItem();
};


class SERIKBLDCORE_EXPORT ImgItem : public RaporItem{
public:
    explicit ImgItem();

    ImgItem& setImgOid( const std::string &imgOid );
    std::string getImgOid() const;
};


class SERIKBLDCORE_EXPORT TableItem : public RaporItem{
public:
    explicit TableItem();

    TableItem& appendCell( const int& row, const int& col , const std::string &value );
    std::string cell( const int &row , const int &col ) const;

    int row() const;
    int column() const;
};










class SERIKBLDCORE_EXPORT Manager : public SerikBLDCore::ListItem<SerikBLDCore::Faaliyet::RaporItem>{
public:
    explicit Manager( SerikBLDCore::DB* _mDB );

    virtual void onList( const QVector<SerikBLDCore::Faaliyet::RaporItem> *mlist ) override;

    virtual void errorOccured( const std::string &errorText ) override;

    bool insertFaaliyetItem( const FaaliyetItem& faaliyetItem );

    SerikBLDCore::Faaliyet::FaaliyetItem* getFaaliyetItem( const std::string& birim , const std::int64_t& yil );

    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> ListFaaliyetItem( const std::string& birim );
};





}


}


#endif // FAALIYETRAPOR_H
