#include "stok.h"



SerikBLDCore::Stok::Stok::Stok( SerikBLDCore::Stok::Stok::Giris giris,
                                const std::string &mudurluk )
    : SerikBLDCore::Item ( giris == Giris::giris ? StokKey::Collection : StokKey::CollectionCikis )
{
    if( mudurluk == "none" )
    {
        errorOccured ("Birim Seçilmemiş");
        return;
    }
    this->append(StokKey::mudurluk,mudurluk);
}

SerikBLDCore::Stok::Stok::Stok(const SerikBLDCore::Stok::Stok &other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::Stok::Stok(SerikBLDCore::Stok::Stok &&other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::operator=(const SerikBLDCore::Stok::Stok &other)
{
    this->setCollection (other.getCollection ());
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::operator=(SerikBLDCore::Stok::Stok &&other)
{
    this->setCollection (other.getCollection ());
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setKategori(const bsoncxx::oid &kategoriOid)
{
    this->append(StokKey::kategori,kategoriOid);
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setAdi(const std::string &adi)
{
    this->append(StokKey::adi,adi);
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setKodu(const bsoncxx::oid &kodOid)
{
    this->append(StokKey::kodu,kodOid);
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setMiktar(const int64_t &miktar)
{
    this->append(StokKey::miktar,bsoncxx::types::b_int64{miktar});
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setTcOid(const bsoncxx::oid &tcoid)
{
    this->append( StokKey::tcoid , tcoid );
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::setMudurluk(const std::string &mudurluk)
{
    this->append( StokKey::mudurluk , mudurluk );
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::addTeslimAlan(const SerikBLDCore::Stok::Stok::TeslimAlan &alan)
{
    this->pushArray(StokKey::teslimAlan,alan.getItem ());
    return *this;
}




boost::optional<bsoncxx::oid> SerikBLDCore::Stok::Stok::kategori() const
{
    auto val = this->element (StokKey::kategori);
    if( val )
    {
        return val.value ().get_oid ().value;
    }
    return boost::none;
}

std::string SerikBLDCore::Stok::Stok::adi() const
{
    auto val = this->element (StokKey::adi);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

boost::optional<bsoncxx::oid> SerikBLDCore::Stok::Stok::kodu() const
{
    auto val = this->element (StokKey::kodu);
    if( val )
    {
        return val.value ().get_oid ().value;
    }
    return boost::none;
}

int64_t SerikBLDCore::Stok::Stok::miktar() const
{
    auto val = this->element (StokKey::miktar);
    if( val )
    {
        return val.value ().get_int64 ().value;
    }
    return 0;
}

boost::optional<bsoncxx::oid> SerikBLDCore::Stok::Stok::tcoid() const
{
    auto val = this->element (StokKey::tcoid);
    if( val )
    {
        return val.value ().get_oid ().value;
    }
    return boost::none;
}














SerikBLDCore::Stok::StokKategori::StokKategori(const std::string &mudurluk)
    :SerikBLDCore::Item (StokKategoriKey::Collection)
{
    if( mudurluk == "none" )
    {
        errorOccured ("Kategori Müdürlüğü Kay Bulunmamakta");
    }
    this->append( StokKategoriKey::mudurluk , mudurluk );
}

SerikBLDCore::Stok::StokKategori &SerikBLDCore::Stok::StokKategori::setKategoriName(const std::string &kategoriName)
{
    if( mudurlukName () == "none" )
    {
        errorOccured ("Kategori Müdürlüğü Kay Bulunmamakta");
        return *this;
    }
    this->append(StokKategoriKey::kategoriName,kategoriName);
    return *this;
}

std::string SerikBLDCore::Stok::StokKategori::kategoriName() const
{
    auto val = this->element (StokKategoriKey::kategoriName);
    if( val )
    {
        return val->get_utf8 ().value.to_string();
    }
    return "";
}

std::string SerikBLDCore::Stok::StokKategori::mudurlukName() const
{
    auto val = this->element (StokKategoriKey::mudurluk);
    if( val )
    {
        return val->get_utf8 ().value.to_string();
    }
    return "";
}

void SerikBLDCore::Stok::StokKategori::errorOccured(const std::string &errorText)
{

}


SerikBLDCore::Stok::StokKodItem::StokKodItem() : SerikBLDCore::Item (StokKodKey::Collection)
{

}

SerikBLDCore::Stok::StokKodItem::StokKodItem(const SerikBLDCore::Stok::StokKodItem &other) : SerikBLDCore::Item (StokKodKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::StokKodItem::StokKodItem(SerikBLDCore::Stok::StokKodItem &&other) : SerikBLDCore::Item (StokKodKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::StokKodItem &SerikBLDCore::Stok::StokKodItem::operator=(const SerikBLDCore::Stok::StokKodItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stok::StokKodItem &SerikBLDCore::Stok::StokKodItem::operator=(SerikBLDCore::Stok::StokKodItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stok::StokKodItem &SerikBLDCore::Stok::StokKodItem::setAdi( const std::string &adi )
{
    this->append(StokKodKey::adi,adi);
    return *this;
}

SerikBLDCore::Stok::StokKodItem &SerikBLDCore::Stok::StokKodItem::setBirim( const std::string &birim )
{
    this->append(StokKodKey::birimi,birim);
    return *this;
}

SerikBLDCore::Stok::StokKodItem &SerikBLDCore::Stok::StokKodItem::setKategoriOid(const bsoncxx::oid &kategoriOid)
{
    this->append(StokKodKey::kategoriOid,kategoriOid);
    return *this;
}

std::string SerikBLDCore::Stok::StokKodItem::adi() const
{
    auto val = this->element (StokKodKey::adi);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

std::string SerikBLDCore::Stok::StokKodItem::birim() const
{
    auto val = this->element (StokKodKey::birimi);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

boost::optional<bsoncxx::oid> SerikBLDCore::Stok::StokKodItem::kategoriOid() const
{
    auto val = this->element (StokKodKey::kategoriOid);
    if( val )
    {
        return val.value ().get_oid ().value;
    }
    return boost::none;
}



SerikBLDCore::Stok::Stok::TeslimAlan::TeslimAlan(const bsoncxx::document::view &view)
{
    try {
        this->miktar = view["miktar"].get_int64 ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
    }

    try {
        this->julianDay = view["julianday"].get_int64 ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
    }

    try {
        this->mSecSinceStartOfDay = view["StartOfDay"].get_int64 ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
    }

    try {
        this->teslimAlan = view["teslimAlan"].get_oid ().value.to_string();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
    }
}

SerikBLDCore::Item SerikBLDCore::Stok::Stok::TeslimAlan::getItem() const
{
    SerikBLDCore::Item item("none");
    item.append("miktar",bsoncxx::types::b_int64{this->miktar});
    item.append("julianday",bsoncxx::types::b_int64{julianDay});
    item.append("StartOfDay",bsoncxx::types::b_int64{mSecSinceStartOfDay});
    item.append("teslimAlan",bsoncxx::oid{this->teslimAlan});
    return item;
}
