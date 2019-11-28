#ifndef BILGIEDINMEITEM_H
#define BILGIEDINMEITEM_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"


namespace SerikBLDCore {


namespace BilgiEdinme {

namespace Key {
static const std::string GeriDonus{"geriDonus"};
static const std::string JulianDay{"julianDay"};
static const std::string TCOid{"TCOid"};
static const std::string Konu{"Konu"};
static const std::string Mesaj{"Mesaj"};
static const std::string Birim{"Birim"};
static const std::string CevapOid{"CevapOid"};
}



class SERIKBLDCORE_EXPORT BilgiEdinmeItem : public SerikBLDCore::Item
{
public:
    static const std::string Collection;

    BilgiEdinmeItem( BilgiEdinmeItem* other = nullptr );
    BilgiEdinmeItem( const BilgiEdinmeItem& other );
    BilgiEdinmeItem( BilgiEdinmeItem&& other );

    BilgiEdinmeItem& operator=( const BilgiEdinmeItem& other );
    BilgiEdinmeItem& operator=( BilgiEdinmeItem&& other );

    BilgiEdinmeItem& setGeriDonus( const bool& geriDonus );
    bool geriDonus() const;

    BilgiEdinmeItem& setJulianDay( const int& julianDay );
    int julianDay() const;
    QString tarih() const;
    QString saat() const;

    BilgiEdinmeItem& setTCoid( const QString& tcoid );
    BilgiEdinmeItem& setTCoid( const bsoncxx::oid &tcoid );
    QString tcOid() const;

    BilgiEdinmeItem& setKonu( const QString& konu );
    QString konu() const;

    BilgiEdinmeItem& setMesaj( const QString& mesaj );
    QString mesaj() const;

    BilgiEdinmeItem& setBirim( const QString& birim );
    QString birim() const;

    BilgiEdinmeItem& setCevap( const QString& cevapOid );
    BilgiEdinmeItem& setCevap( const bsoncxx::oid& cevapOid );
    QString cevapOid() const;

    bool cevaplandi() const;
};


}


}



#endif // BILGIEDINMEITEM_H
