#include "calismaitem.h"



SerikBLDCore::Calisma::Calisma::Calisma()
    :SerikBLDCore::Item (Key::Collection)
{




}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setCalimaAdi(const std::string &calismaAdi)
{
    this->append(Key::calismaAdi,calismaAdi);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setBirim(const std::string &birim)
{
    this->append(Key::birim,birim);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setAciklama(const std::string &aciklama)
{
    this->append(Key::aciklama,aciklama);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setMahalle(const std::string &mahalle)
{
    this->append(Key::mahalle,mahalle);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setJulianDay(const std::int64_t &julianDay)
{
    auto date = QDate::fromJulianDay (julianDay);
    this->append(Key::ay,date.toString ("MMMM").toStdString ());
    this->append(Key::yil,bsoncxx::types::b_int64{date.year ()});
    this->append(Key::julianDate,bsoncxx::types::b_int64{julianDay});
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setisBirimi(const std::string &isBirimi)
{
    this->append(Key::unitBirim,isBirimi);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setMiktar(const double &miktar)
{
    this->append(Key::miktar,miktar);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::addPhoto(const bsoncxx::oid &imgOid)
{
    this->pushArray (Key::images,imgOid);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setIsTipi(const std::string &isTipi)
{
    this->append(Key::isTipi,isTipi);
    return *this;
}

SerikBLDCore::Calisma::Calisma &SerikBLDCore::Calisma::Calisma::setIsKategorisi(const std::string &isKategorisi)
{
    this->append(Key::isKategorisi,isKategorisi);
    return *this;
}

std::string SerikBLDCore::Calisma::Calisma::CalismaAdi() const
{
    auto val = this->element (Key::calismaAdi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Calisma::Calisma::Mahalle() const
{
    auto val = this->element (Key::mahalle);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Calisma::Calisma::IsTipii() const
{
    auto val = this->element (Key::isTipi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Calisma::Calisma::IsBirim() const
{
    auto val = this->element (Key::unitBirim);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Calisma::Calisma::tarihText() const
{
    return QDate::fromJulianDay (this->julianDay ()).toString ("dd/MM/yyyy").toStdString ();
}

int64_t SerikBLDCore::Calisma::Calisma::julianDay() const
{
    auto val = this->element (Key::julianDate);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return 0;
    }
}

std::vector<bsoncxx::oid> SerikBLDCore::Calisma::Calisma::imgOidList() const
{
    std::vector<bsoncxx::oid> oidList;

    auto val = this->element (Key::images);
    if( val ){

        auto arr = val->get_array ().value;
        //bsoncxx::v_noabi::array::element
//        std::transform(arr.begin (),arr.end (),arr.begin (),[&oidList](const bsoncxx::document::value item ){ oidList.push_back (item.get_oid().value);});

        for( auto item : arr ){
            oidList.push_back (item.get_oid ().value);
        }
    }


    return oidList;
}

std::string SerikBLDCore::Calisma::Calisma::Aciklama() const
{
    auto val = this->element (Key::aciklama);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

double SerikBLDCore::Calisma::Calisma::Miktar() const
{
    auto val = this->element (Key::miktar);
    if( val ){
        return val.value ().get_double ().value;
    }else{
        return 0;
    }
}

std::string SerikBLDCore::Calisma::Calisma::isKategorisi() const
{
    auto val = this->element (Key::isKategorisi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

void SerikBLDCore::Calisma::Calisma::errorOccured(const std::string &errorText)
{

}




SerikBLDCore::Calisma::Kategori::Kategori()
    :SerikBLDCore::Item (KategoriKey::Collection)
{

}

SerikBLDCore::Calisma::Kategori &SerikBLDCore::Calisma::Kategori::setKategoriAdi(const std::string &kategoriName)
{
    this->append(KategoriKey::kategoriAdi,kategoriName);
    return *this;
}

std::string SerikBLDCore::Calisma::Kategori::getKategoriAdi() const
{
    auto val = this->element (KategoriKey::kategoriAdi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

SerikBLDCore::Calisma::Kategori &SerikBLDCore::Calisma::Kategori::setKategoriMudurluk(const std::string &mudurluk)
{
    this->append(KategoriKey::kategoriMudurluk,mudurluk);
    return *this;
}

std::string SerikBLDCore::Calisma::Kategori::getKategoriMudurluk() const
{
    auto val = this->element (KategoriKey::kategoriMudurluk);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}

SerikBLDCore::Calisma::Kategori &SerikBLDCore::Calisma::Kategori::setKategoriBirim(const std::string &birim)
{
    this->append(KategoriKey::kategoriBirim,birim);
    return *this;
}

std::string SerikBLDCore::Calisma::Kategori::getKategoriBirimi() const
{
    auto val = this->element (KategoriKey::kategoriBirim);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }else{
        return "";
    }
}
