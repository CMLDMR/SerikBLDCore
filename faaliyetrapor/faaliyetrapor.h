#ifndef FAALIYETRAPOR_H
#define FAALIYETRAPOR_H


#include <item.h>
#include <listitem.h>
#include <memory.h>

namespace SerikBLDCore{


namespace Faaliyet{


class RaporItem;

class SERIKBLDCORE_EXPORT FaaliyetItem : public SerikBLDCore::Item{
public:
    explicit FaaliyetItem();

    FaaliyetItem( const FaaliyetItem &other );
    FaaliyetItem( FaaliyetItem &&other );



    FaaliyetItem& operator=( const FaaliyetItem &other );
    FaaliyetItem& operator=( FaaliyetItem &&other );

    FaaliyetItem& setBirim( const std::string &birim );
    std::string getBirim() const;

    FaaliyetItem& setYil( const std::int64_t &yil );
    std::int64_t getYil() const;

    FaaliyetItem& setFaaliyet( const bsoncxx::array::view &view );
    bsoncxx::array::view getFaaliyetView() const;

    FaaliyetItem& setOnay( const bool &onay , const bsoncxx::oid &onaylayanOid );
    bool getOnay() const;
    std::string getOnaylayan() const;

    std::vector<SerikBLDCore::Faaliyet::RaporItem> getFaaliyetList() const;
};



namespace Key {
static const std::string Collection{"faaliyetRapor"};
static const std::string text{"text"};
static const std::string type{"type"};
static const std::string uuid{"uuid"};
static const std::string parentuuid{"parentUuid"};
static const std::string onayli{"onayli"};
static const std::string onaylayan{"onaylayan"};

namespace Type {
static const std::string baslik{"baslik"};
static const std::string altBaslik{"altBaslik"};
static const std::string paragraf{"paragraf"};
static const std::string img{"img"};
static const std::string table{"table"};
static const std::string pageBreak{"pageBreak"};
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
    bool isPageBreak() const;

    virtual void errorOccured(const std::string &errorText) override{

    }

};


class SERIKBLDCORE_EXPORT PageBreak : public RaporItem{
public:
    explicit PageBreak();
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

    TableItem& setHeaders( const std::vector<std::string> &headers );

    std::vector<std::string> headers() const;

    TableItem& appendCell( const int& row, const int& col , const std::string &value );
    TableItem& setCell( const int &row , const int &col , const std::string &value );
    std::string cell( const int &row , const int &col ) const;

    void resetCells();
    void resetTable();

    int row() const;
    int column() const;

    virtual void errorOccured(const std::string &errorText) override{

    }

private:
    bool _appendCell( const int &row , const int &col , const std::string &value );
};










class SERIKBLDCORE_EXPORT Manager : public SerikBLDCore::ListItem<SerikBLDCore::Faaliyet::RaporItem>{
public:
    explicit Manager( SerikBLDCore::DB* _mDB );

    virtual void onList( const QVector<SerikBLDCore::Faaliyet::RaporItem> *mlist ) override;

    virtual void errorOccured( const std::string &errorText ) override;

    bool insertFaaliyetItem( const FaaliyetItem& faaliyetItem );

    std::unique_ptr<SerikBLDCore::Faaliyet::FaaliyetItem> getFaaliyetItem( const std::string& birim , const std::int64_t& yil );


    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> ListFaaliyetItem( const std::string& birim , const std::int64_t &yil );


    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> ListFaaliyetItem( const std::string& birim );


    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> ListFaaliyetItem( const std::int64_t &yil );

    std::unique_ptr<SerikBLDCore::Faaliyet::FaaliyetItem> FaaliyetItem( const std::string &birim , const std::int64_t &yil );

};





}


}


#endif // FAALIYETRAPOR_H
