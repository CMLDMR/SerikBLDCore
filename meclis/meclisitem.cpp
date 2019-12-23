#include "meclisitem.h"





SerikBLDCore::Meclis::MeclisItem::MeclisItem()
    :SerikBLDCore::Item(Key::Collection)
{

}

SerikBLDCore::Meclis::MeclisItem &SerikBLDCore::Meclis::MeclisItem::setYil(const int &yil)
{
    this->append(Key::yil,bsoncxx::types::b_int32{yil});
    return *this;
}

SerikBLDCore::Meclis::MeclisItem &SerikBLDCore::Meclis::MeclisItem::setAy(const QString &ay)
{
    this->append(Key::ay,ay.toStdString ());
    return *this;
}

SerikBLDCore::Meclis::MeclisItem &SerikBLDCore::Meclis::MeclisItem::setJulianDay(const int &julianDay)
{
    this->append(Key::julianDate,bsoncxx::types::b_int64{julianDay});
    return *this;
}

SerikBLDCore::Meclis::MeclisItem &SerikBLDCore::Meclis::MeclisItem::setYayinda(const bool &yayinda)
{
    this->append(Key::yayinda,bsoncxx::types::b_bool{yayinda});
    return *this;
}

SerikBLDCore::Meclis::MeclisItem &SerikBLDCore::Meclis::MeclisItem::setGundem(const QString &gundem)
{
    this->append(Key::gundem,gundem.toStdString ());
    return *this;
}

QString SerikBLDCore::Meclis::MeclisItem::gundem() const
{
    auto val = this->element (Key::gundem);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string ());
    }
    return "";
}

QString SerikBLDCore::Meclis::MeclisItem::ay() const
{
    auto val = this->element (Key::ay);
    if( val )
    {
        return QString::fromStdString (val->get_utf8 ().value.to_string ());
    }
    return "";
}

int32_t SerikBLDCore::Meclis::MeclisItem::yil() const
{
    auto val = this->element (Key::yil);
    if( val )
    {
        return val->get_int32 ().value;
    }
    return -1;
}

std::int64_t SerikBLDCore::Meclis::MeclisItem::julianDay() const
{
    auto val = this->element (Key::julianDate);
    if( val )
    {
        return val->get_int64 ().value;
    }
    return -1;
}

bool SerikBLDCore::Meclis::MeclisItem::yayinda() const
{
    auto val = this->element (Key::yayinda);
    if( val )
    {
        return val->get_bool ().value;
    }
    return false;
}







SerikBLDCore::Meclis::YouTubeLink::YouTubeLink()
    :Item(LinkKey::Collection)
{

}

SerikBLDCore::Meclis::YouTubeLink &SerikBLDCore::Meclis::YouTubeLink::setVideoID(const std::string &videoid)
{
    this->append(LinkKey::VideoID,videoid);
    return *this;
}

SerikBLDCore::Meclis::YouTubeLink &SerikBLDCore::Meclis::YouTubeLink::setMeclisOid(const std::string &meclisoid)
{
    this->append(LinkKey::MeclisOid,bsoncxx::oid{meclisoid});
    return *this;
}

std::string SerikBLDCore::Meclis::YouTubeLink::videoid() const
{
    auto val = this->element (LinkKey::VideoID);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

std::string SerikBLDCore::Meclis::YouTubeLink::videoUrl() const
{
    auto url = "https://www.youtube.com/watch?v=" + this->videoid ();
    return url;
}

std::string SerikBLDCore::Meclis::YouTubeLink::videothump0() const
{
    auto url = "https://img.youtube.com/vi/"+this->videoid ()+"/0.jpg";
    return url;
}

std::string SerikBLDCore::Meclis::YouTubeLink::videothump1() const
{
    auto url = "https://img.youtube.com/vi/"+this->videoid ()+"/1.jpg";
    return url;
}

std::string SerikBLDCore::Meclis::YouTubeLink::videothump2() const
{
    auto url = "https://img.youtube.com/vi/"+this->videoid ()+"/2.jpg";
    return url;
}

std::string SerikBLDCore::Meclis::YouTubeLink::videothump3() const
{
    auto url = "https://img.youtube.com/vi/"+this->videoid ()+"/3.jpg";
    return url;
}

std::string SerikBLDCore::Meclis::YouTubeLink::meclisoid() const
{
    auto val = this->element (LinkKey::MeclisOid);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Meclis::KararItem::KararItem()
    :Item(KararKey::Collection)
{

}

SerikBLDCore::Meclis::KararItem::KararItem(const std::string &meclisOid)
    :Item(KararKey::Collection)
{
    this->append(KararKey::MeclisOid,bsoncxx::oid{meclisOid});
}

SerikBLDCore::Meclis::KararItem &SerikBLDCore::Meclis::KararItem::setMeclisOid(const std::string &meclisOid)
{
    this->append(KararKey::MeclisOid,bsoncxx::oid{meclisOid});
    return *this;
}

SerikBLDCore::Meclis::KararItem &SerikBLDCore::Meclis::KararItem::setKararOid(const std::string &kararOid)
{
    this->append(KararKey::KararOid,bsoncxx::oid{kararOid});
    return *this;
}

SerikBLDCore::Meclis::KararItem &SerikBLDCore::Meclis::KararItem::setSayi(const int32_t &sayi)
{
    this->append(KararKey::Sayi,bsoncxx::types::b_int32{sayi});
    return *this;
}

int32_t SerikBLDCore::Meclis::KararItem::sayi() const
{
    auto val = this->element (KararKey::Sayi);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }
    return 0;
}

std::string SerikBLDCore::Meclis::KararItem::kararOid() const
{
    auto val = this->element (KararKey::KararOid);
    if( val )
    {
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

std::string SerikBLDCore::Meclis::KararItem::meclisOid() const
{
    auto val = this->element (KararKey::MeclisOid);
    if( val )
    {
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}
