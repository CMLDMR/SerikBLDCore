#include "firmaitem.h"


SerikBLDCore::Firma::FirmaItem::FirmaItem()
    :SerikBLDCore::Item(Key::Collection)
{

}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setName( const std::string &firmaName )

{
    this->append(Key::firmaAdi,firmaName);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setTelefon(const std::string &telefon)
{
    this->append(Key::telefon,telefon);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setMail(const std::string &email)
{
    this->append(Key::email,email);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setAdres(const std::string &adres)
{
    this->append(Key::adres,adres);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setVergi(const std::string &vergiNo)
{
    this->append(Key::vergiNo,vergiNo);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setKaydeden(const bsoncxx::oid &oid, const int64_t &mSecSinceEpoch)
{
    this->append(Key::kaydedenOid,oid);
    this->append(Key::kayitTarihEpoch,mSecSinceEpoch);
    return *this;
}

SerikBLDCore::Firma::FirmaItem &SerikBLDCore::Firma::FirmaItem::setYetkiliOid(const bsoncxx::oid &yetkiliOid)
{
    this->append(Key::yetkiliOid,yetkiliOid);
    return *this;
}



std::string SerikBLDCore::Firma::FirmaItem::name() const
{
    auto val = this->element (Key::firmaAdi);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Firma::FirmaItem::telefon() const
{
    auto val = this->element (Key::telefon);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Firma::FirmaItem::vergiNo() const
{
    auto val = this->element (Key::vergiNo);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

int64_t SerikBLDCore::Firma::FirmaItem::kayitTarihi() const
{
    auto val = this->element (Key::kayitTarihEpoch);
    if( val )
    {
        return val.value ().get_int64 ().value;
    }else{
        return 0;
    }
}

std::string SerikBLDCore::Firma::FirmaItem::mail() const
{
    auto val = this->element (Key::email);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Firma::FirmaItem::kaydedenOid() const
{
    auto val = this->element (Key::kaydedenOid);
    if( val )
    {
        return val.value ().get_oid ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Firma::FirmaItem::adres() const
{
    auto val = this->element (Key::adres);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Firma::FirmaItem::yetkiliOid() const
{
    auto val = this->element (Key::yetkiliOid);
    if( val )
    {
        return val.value ().get_oid ().value.to_string();
    }else{
        return "";
    }
}

void SerikBLDCore::Firma::FirmaItem::errorOccured(const std::string &errorText)
{

}
