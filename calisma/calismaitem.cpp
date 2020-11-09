#include "calismaitem.h"



SerikBLDCore::Calisma::Calisma()
    :SerikBLDCore::Item (Key::Collection)
{




}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setCalimaAdi(const std::string &calismaAdi)
{
    this->append(Key::calismaAdi,calismaAdi);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setBirim(const std::string &birim)
{
    this->append(Key::birim,birim);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setAciklama(const std::string &aciklama)
{
    this->append(Key::aciklama,aciklama);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setMahalle(const std::string &mahalle)
{
    this->append(Key::mahalle,mahalle);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setJulianDay(const std::int64_t &julianDay)
{
    auto date = QDate::fromJulianDay (julianDay);
    this->append(Key::ay,date.toString ("MMMM").toStdString ());
    this->append(Key::yil,bsoncxx::types::b_int64{date.year ()});
    this->append(Key::julianDate,bsoncxx::types::b_int64{julianDay});
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setisBirimi(const std::string &isBirimi)
{
    this->append(Key::unitBirim,isBirimi);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::setMiktar(const double &miktar)
{
    this->append(Key::miktar,miktar);
    return *this;
}

SerikBLDCore::Calisma &SerikBLDCore::Calisma::addPhoto(const bsoncxx::oid &imgOid)
{
    this->pushArray (Key::images,imgOid);
    return *this;
}

SerikBLDCore::CalismaItem::CalismaItem()
    :SerikBLDCore::Item (KeyItem::Collection)
{

}
