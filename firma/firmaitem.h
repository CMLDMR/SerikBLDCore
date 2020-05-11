#ifndef FIRMAITEM_H
#define FIRMAITEM_H

#include "item.h"

namespace SerikBLDCore {

namespace Firma {

namespace Key {
static const std::string Collection{"Firmalar"};
static const std::string firmaAdi{"firmaAdi"};
static const std::string telefon{"telefon"};
static const std::string email{"mail"};
static const std::string adres{"adres"};
static const std::string kayitTarihEpoch{"kayitTarih"};
static const std::string kaydedenOid{"kaydedenOid"};
static const std::string vergiNo{"vergiNo"};
}

class SERIKBLDCORE_EXPORT FirmaItem : public Item
{
public:
    explicit FirmaItem();

    FirmaItem& setName( const std::string& firmaName );
    FirmaItem& setTelefon( const std::string& telefon );
    FirmaItem& setMail( const std::string& email );
    FirmaItem& setAdres( const std::string& adres );
    FirmaItem& setVergi( const std::string& vergiNo );
    FirmaItem& setKaydeden(const bsoncxx::oid& oid , const std::int64_t& mSecSinceEpoch );

    std::string name() const;
    std::string telefon() const;
    std::string vergiNo() const;
    std::int64_t kayitTarihi() const;
    std::string mail() const;

    void errorOccured(const std::string &errorText) override;
};

}



}

#endif // FIRMAITEM_H
