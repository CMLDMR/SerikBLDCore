#include "mimariproje.h"

const std::string SerikBLDCore::Imar::MimariProje::MimariProje::Collection{"MimariProjeler"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyFirmaOid{"firmaOid"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyBasvuruJulianDay{"basvuruTarihi"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyAda{"ada"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyParsel{"parsel"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyOnayli{"onayli"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyYetkiliPersonelOid{"yetkiliPersonelOid"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyAdi{"projeAdi"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyMahalle{"projeMahalle"};
const std::string SerikBLDCore::Imar::MimariProje::MimariProje::keyDWGOid{"dwgOid"};

SerikBLDCore::Imar::MimariProje::MimariProje::MimariProje()
    :SerikBLDCore::Item (Collection)
{

}

SerikBLDCore::Imar::MimariProje::MimariProje::MimariProje( const bsoncxx::oid& firmaOid , const std::int64_t& basvuruJulianday )
    :SerikBLDCore::Item (Collection)
{
    this->append(keyFirmaOid,firmaOid);
    this->append(keyBasvuruJulianDay,bsoncxx::types::b_int64{basvuruJulianday});
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setAdi(const std::string &adi)
{
    this->append(keyAdi,adi);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setAda(const int &adaNo)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyAda,bsoncxx::types::b_int64{adaNo});
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setParsel(const int &parselNo)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyParsel,bsoncxx::types::b_int64{parselNo});
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setOnayli(const bool &onay, const bsoncxx::oid &personelOid)
{
    if( this->yetkiliPersonel () == personelOid.to_string () )
    {
        this->append(keyOnayli,onay);
    }else{
        errorOccured ("Bu Proje Şuanda Başka Personelde Siz Onaylayamazsınız!");
    }
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setYetkiliPersonelOid(const bsoncxx::oid &personelOid)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyYetkiliPersonelOid,personelOid);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setMahalle(const std::string &mahalle)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyMahalle,mahalle);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setDWGFileOid(const bsoncxx::oid &fileOid)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyDWGOid,fileOid);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setFirmaOid(const bsoncxx::oid &firmaOid)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyFirmaOid,firmaOid);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MimariProje &SerikBLDCore::Imar::MimariProje::MimariProje::setBasvuruJulianDay(const int64_t &basvuruJulianDay)
{
    if( this->onayli () ){
        errorOccured ("Bu Proje Onaylandı. Değiştirilemez");
        return *this;
    }
    this->append(keyBasvuruJulianDay,bsoncxx::types::b_int64{basvuruJulianDay});
    return *this;
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::adi() const
{
    auto val = this->element (keyAdi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::firmaOid() const
{
    auto val = this->element (keyFirmaOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }else{
        return "";
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MimariProje::basvuruJulianDay() const
{
    auto val = this->element (keyBasvuruJulianDay);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MimariProje::ada() const
{
    auto val = this->element (keyAda);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MimariProje::parsel() const
{
    auto val = this->element (keyParsel);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}

bool SerikBLDCore::Imar::MimariProje::MimariProje::onayli() const
{
    auto val = this->element (keyOnayli);
    if( val ){
        return val.value ().get_bool ().value;
    }else{
        return false;
    }
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::yetkiliPersonel() const
{
    auto val = this->element (keyYetkiliPersonelOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::mahalle() const
{
    auto val = this->element (keyMahalle);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::dwgOid() const
{
    auto val = this->element (keyDWGOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }else{
        return "";
    }
}

