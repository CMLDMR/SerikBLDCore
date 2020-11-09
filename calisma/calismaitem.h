#ifndef CALISMAITEM_H
#define CALISMAITEM_H

#include <item.h>

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"

namespace SerikBLDCore {


namespace Key{
static const std::string Collection{"CalismalarV2"};
static const std::string ay{"ay"};
static const std::string yil{"yil"};
static const std::string julianDate{"julianDate"};
static const std::string epochTime{"epoch"};
static const std::string birim{"birim"};
static const std::string mahalle{"mahalle"};
static const std::string aciklama{"aciklama"};
static const std::string unitBirim{"unitBirim"};
static const std::string calismaAdi{"calismaAdi"};
static const std::string images{"images"};
static const std::string miktar{"miktar"};
}

namespace KeyItem{
static const std::string Collection{"CalismaItemV2"};
//static const std::string ay{"ay"};
//static const std::string yil{"yil"};
//static const std::string julianDate{"julianDate"};
static const std::string epochTime{"epoch"};
}


class SERIKBLDCORE_EXPORT Calisma : public SerikBLDCore::Item
{
public:
    Calisma();


    Calisma& setCalimaAdi( const std::string& calismaAdi );
    Calisma& setBirim( const std::string& birim );
    Calisma& setAciklama( const std::string &aciklama );
    Calisma& setMahalle( const std::string &mahalle );
    Calisma& setJulianDay(const int64_t &julianDay );
    Calisma& setisBirimi( const std::string& isBirimi );
    Calisma& setMiktar( const double& miktar );
    Calisma& addPhoto( const bsoncxx::oid& imgOid );
};



class SERIKBLDCORE_EXPORT CalismaItem : public SerikBLDCore::Item
{
public:
    CalismaItem();
};








} // namespace Calisma




#endif // CALISMAITEM_H
