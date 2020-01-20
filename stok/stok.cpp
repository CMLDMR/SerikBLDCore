#include "stok.h"



SerikBLDCore::Stok::Stok::Stok(const std::string &mudurluk)
    :SerikBLDCore::Item (StokKey::Collection)
{
    this->append(StokKey::mudurluk,mudurluk);
}

SerikBLDCore::Stok::Stok::Stok(const SerikBLDCore::Stok::Stok &other)
    :SerikBLDCore::Item (StokKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::Stok::Stok(SerikBLDCore::Stok::Stok &&other)
    :SerikBLDCore::Item (StokKey::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::operator=(const SerikBLDCore::Stok::Stok &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Stok::Stok &SerikBLDCore::Stok::Stok::operator=(SerikBLDCore::Stok::Stok &&other)
{
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
