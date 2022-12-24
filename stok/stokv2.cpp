#include "stokv2.h"



SerikBLDCore::Stokv2::Stok::Stok()
    :SerikBLDCore::Item (Key::Collection)
{

}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setBirimBirim(const double &fiyat)
{
    this->append(Key::birimFiyati,fiyat);
    return *this;
}

double SerikBLDCore::Stokv2::Stok::getBirimFiyat() const
{
    auto val = this->element(Key::birimFiyati);
    if( val ){
        return val->get_double().value;
    }
    return 0;
}

//SerikBLDCore::Stokv2::Stok::Stok(const SerikBLDCore::Stokv2::Stok &other)
//{
//    this->setDocumentView (other.view ());
//}

//SerikBLDCore::Stokv2::Stok::Stok(SerikBLDCore::Stokv2::Stok &&other)
//{
//    this->setDocumentView (other.view ());
//}




//SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::operator=(const SerikBLDCore::Stokv2::Stok &other)
//{
//    setDocumentView (other.view ());
//    return *this;
//}

//SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::operator=(SerikBLDCore::Stokv2::Stok &&other)
//{
//    setDocumentView (other.view ());
//    return *this;
//}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setMiktar(const double &miktar)
{
    this->append(Key::miktar,miktar);
    return *this;
}

double SerikBLDCore::Stokv2::Stok::getMiktar() const
{
    auto val = this->element (Key::miktar);
    if( val ){
        return val.value ().get_double ().value;
    }
    return 0;
}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setKategoriOid(const std::string &kategoriOid)
{
    this->append(Key::kategoriOid,bsoncxx::oid{kategoriOid});
    return *this;
}

std::string SerikBLDCore::Stokv2::Stok::getKategoriOid() const
{
    auto val = this->element (Key::kategoriOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setMalzemeAdi(const std::string &malzemeAdi)
{
    this->append(Key::malzemeAdi,malzemeAdi);
    return *this;
}

std::string SerikBLDCore::Stokv2::Stok::getMalzemeAdi() const
{
    auto val = this->element (Key::malzemeAdi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setMudurluk(const std::string &mudurluk)
{
    this->append(Key::mudurluk,mudurluk);
    return *this;
}

std::string SerikBLDCore::Stokv2::Stok::getMudurluk() const
{
    auto val = this->element (Key::mudurluk);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setMetric(const std::string &metric)
{
    this->append(Key::metric,metric);
    return *this;
}

std::string SerikBLDCore::Stokv2::Stok::getMetric() const
{
    auto val = this->element (Key::metric);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Stok &SerikBLDCore::Stokv2::Stok::setTeslimOid(const std::string &teslimOid)
{
    this->append(Stokv2::Key::teslimOid,bsoncxx::oid{teslimOid});
    return *this;
}

std::string SerikBLDCore::Stokv2::Stok::getTeslimOid() const
{
    auto val = this->element (Key::teslimOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

boost::optional<SerikBLDCore::Stokv2::Giris> SerikBLDCore::Stokv2::Stok::toGiris()
{
    auto val = this->element ("type");
    if( val ){
        if( val.value ().get_utf8 ().value.to_string() == "giris" ){
            SerikBLDCore::Stokv2::Giris girisItem(*this);
            girisItem.append("type","giris");
            return girisItem;
        }else{
            return boost::none;
        }
    }else{
        return boost::none;
    }
}

boost::optional<SerikBLDCore::Stokv2::Cikis> SerikBLDCore::Stokv2::Stok::toCikis()
{
    auto val = this->element ("type");
    if( val ){
        if( val.value ().get_utf8 ().value.to_string() == "giris" ){
            SerikBLDCore::Stokv2::Cikis cikisItem(*this);
            cikisItem.append("type","cikis");
            return cikisItem;
        }else{
            return boost::none;
        }
    }else{
        return boost::none;
    }
}

SerikBLDCore::Stokv2::Kategori::Kategori()
    :SerikBLDCore::Item (KeyKategori::Collection)
{

}

SerikBLDCore::Stokv2::Kategori &SerikBLDCore::Stokv2::Kategori::setKategoriAdi(const std::string &kategoriAdi)
{
    this->append(KeyKategori::kategoriAdi,kategoriAdi);
    return *this;

}

std::string SerikBLDCore::Stokv2::Kategori::getKategoriAdi() const
{
    auto val = this->element (KeyKategori::kategoriAdi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Kategori &SerikBLDCore::Stokv2::Kategori::setBirim(const std::string &Birim)
{
    this->append(KeyKategori::birim,Birim);
    return *this;
}

std::string SerikBLDCore::Stokv2::Kategori::getBirim() const
{
    auto val = this->element (KeyKategori::birim);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Kategori &SerikBLDCore::Stokv2::Kategori::setMetric(const std::string &metric)
{
    this->append(KeyKategori::metric,metric);
    return *this;
}

std::string SerikBLDCore::Stokv2::Kategori::getMetric() const
{
    auto val = this->element (KeyKategori::metric);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Stokv2::Giris::Giris()
{
    this->append("type","giris");
}

SerikBLDCore::Stokv2::Giris::Giris(const SerikBLDCore::Stokv2::Stok &stok)
{
    this->clear ();
    this->setDocumentView (stok.view ());
}

SerikBLDCore::Stokv2::Giris::Giris(const SerikBLDCore::Stokv2::Giris &other)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stokv2::Giris::Giris(SerikBLDCore::Stokv2::Giris &&other)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stokv2::Giris &SerikBLDCore::Stokv2::Giris::operator=(const SerikBLDCore::Stokv2::Giris &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stokv2::Giris &SerikBLDCore::Stokv2::Giris::operator=( SerikBLDCore::Stokv2::Giris &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stokv2::Giris &SerikBLDCore::Stokv2::Giris::setTeslimAlimJulianDay(const int64_t &julianDay)
{
    this->append(Key::teslimAlimJulianDay,julianDay);
    return *this;
}

int64_t SerikBLDCore::Stokv2::Giris::getTeslimAlimJulianDay() const
{
    auto val = this->element (Key::teslimAlimJulianDay);
    if( val ){
        return val.value ().get_int64 ().value;
    }
    return 0;
}



SerikBLDCore::Stokv2::Cikis::Cikis()
{
    this->append("type","cikis");
}

SerikBLDCore::Stokv2::Cikis::Cikis(const SerikBLDCore::Stokv2::Stok &stok)
{
    this->setDocumentView (stok.view ());

}

SerikBLDCore::Stokv2::Cikis::Cikis(const SerikBLDCore::Stokv2::Cikis &other)
{
    this->setDocumentView (other.view ());

}

SerikBLDCore::Stokv2::Cikis::Cikis(SerikBLDCore::Stokv2::Cikis &&other)
{
    this->setDocumentView (other.view ());

}

SerikBLDCore::Stokv2::Cikis &SerikBLDCore::Stokv2::Cikis::operator=(const SerikBLDCore::Stokv2::Cikis &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stokv2::Cikis &SerikBLDCore::Stokv2::Cikis::setTeslimEtJulianDay(const int64_t &julianDay)
{
    this->append(Key::teslimEtJulianDay,julianDay);
    return *this;
}

int64_t SerikBLDCore::Stokv2::Cikis::getTeslimEtJulianDay() const
{
    auto val = this->element (Key::teslimEtJulianDay);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return 0;
    }
}

SerikBLDCore::Stokv2::Cikis &SerikBLDCore::Stokv2::Cikis::setTeslimAlanPersonel(const std::string &personelOid, const std::string &personelAdSoyad)
{
    this->append(Key::teslimEdilenPersonelOid,bsoncxx::oid{personelOid});
    this->append(Key::teslimEdilenPersonelAdSoyad,personelAdSoyad);
    return *this;
}

std::string SerikBLDCore::Stokv2::Cikis::getPersonelOid() const
{
    auto val = this->element (Key::teslimEdilenPersonelOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }else{
        return "";
    }
}

std::string SerikBLDCore::Stokv2::Cikis::getPersonelAdSoyad() const
{
    auto val = this->element (Key::teslimEdilenPersonelAdSoyad);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }else{
        return "";
    }
}

SerikBLDCore::Stokv2::Cikis &SerikBLDCore::Stokv2::Cikis::setAciklama(const std::string &aciklama)
{
    this->append(Key::cikisAciklamasi,aciklama);
    return *this;
}

std::string SerikBLDCore::Stokv2::Cikis::getAciklama() const
{
    auto val = this->element (Key::cikisAciklamasi);
    if( val ){
        return val.value ().get_utf8 ().value.to_string ();
    }else{
        return "";
    }
}

SerikBLDCore::Stokv2::Cikis &SerikBLDCore::Stokv2::Cikis::operator=( SerikBLDCore::Stokv2::Cikis &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

