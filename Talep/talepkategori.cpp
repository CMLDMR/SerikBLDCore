#include "talepkategori.h"

const std::string SerikBLDCore::TalepKategori::Collection{"SikayetKategorileri"};
const std::string SerikBLDCore::TalepKategori::Baslik{"baslik"};

SerikBLDCore::TalepKategori::TalepKategori()
    :SerikBLDCore::Item(Collection)
{

}

SerikBLDCore::TalepKategori::TalepKategori(const SerikBLDCore::TalepKategori &other)
    :SerikBLDCore::Item(other.Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TalepKategori::TalepKategori(SerikBLDCore::TalepKategori &&other)
    :SerikBLDCore::Item(other.Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::TalepKategori &SerikBLDCore::TalepKategori::operator=(const SerikBLDCore::TalepKategori &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::TalepKategori &SerikBLDCore::TalepKategori::operator=(SerikBLDCore::TalepKategori &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

void SerikBLDCore::TalepKategori::setKategoriName(const QString &name)
{
    this->append(Baslik,name.toStdString ());
}

QString SerikBLDCore::TalepKategori::KategoriName() const
{
    auto val = this->element (Baslik);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}
