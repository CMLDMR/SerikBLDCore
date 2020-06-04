#include "mimarilog.h"

const std::string SerikBLDCore::Imar::MimariLog::Collection{"MimariLog"};
const std::string SerikBLDCore::Imar::MimariLog::keyprojeOid{"projeOid"};
const std::string SerikBLDCore::Imar::MimariLog::keyType{"type"};
const std::string SerikBLDCore::Imar::MimariLog::keyAciklama{"aciklama"};
const std::string SerikBLDCore::Imar::MimariLog::keyDosyaOid{"dosyaOid"};
const std::string SerikBLDCore::Imar::MimariLog::keyEkleyen{"ekleyen"};
const std::string SerikBLDCore::Imar::MimariLog::keyJulianDay{"julianDay"};
const std::string SerikBLDCore::Imar::MimariLog::keyMSecEpoch{"mSecEpoch"};
const std::string SerikBLDCore::Imar::MimariLog::keyDuzeltildi{"duzeltildi"};

SerikBLDCore::Imar::MimariLog::MimariLog()
    :SerikBLDCore::Item (Collection)
{

}

SerikBLDCore::Imar::MimariLog::MimariLog(const bsoncxx::oid &projeOid)
    :SerikBLDCore::Item (Collection)
{
    this->setProjeOid (projeOid);

}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setProjeOid(const bsoncxx::oid &projeOid)
{
    this->append(keyprojeOid,projeOid);
    return *this;
}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setJulianDay(const int64_t &julianDay)
{
    this->append(keyJulianDay,bsoncxx::types::b_int64{julianDay});
    return *this;
}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setSecEpoch(const int64_t &mSecEpoch)
{
    this->append(keyMSecEpoch,bsoncxx::types::b_int64{mSecEpoch});
    return *this;
}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setEkleyen(const std::string &adSoyad)
{
    this->append(keyEkleyen,adSoyad);
    return *this;
}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setType(const SerikBLDCore::Imar::MimariLog::Type type)
{
    this->append(keyType,bsoncxx::types::b_int32{static_cast<std::int32_t>(type)});
    return *this;
}

SerikBLDCore::Imar::MimariLog &SerikBLDCore::Imar::MimariLog::setCurrentDateTime()
{
    setJulianDay (QDate::currentDate ().toJulianDay ());
    setSecEpoch (QDateTime::currentSecsSinceEpoch ());
    return *this;
}

std::string SerikBLDCore::Imar::MimariLog::projeOid() const
{
    auto val = this->element (keyprojeOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

int64_t SerikBLDCore::Imar::MimariLog::julianDay() const
{
    auto val = this->element (keyJulianDay);
    if( val ){
        return val.get ().get_int64 ().value;
    }
    return -1;
}

int64_t SerikBLDCore::Imar::MimariLog::mSecEpoch() const
{
    auto val = this->element (keyMSecEpoch);
    if( val ){
        return val.get ().get_int64 ().value;
    }
    return -1;
}

std::string SerikBLDCore::Imar::MimariLog::ekleyen() const
{
    auto val = this->element (keyEkleyen);
    if( val ){
        return val.get ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Imar::MimariLog::Type SerikBLDCore::Imar::MimariLog::LogType() const
{
    auto val = this->element (keyType);
    if( val ){
        return static_cast<Type>(val.value ().get_int64 ().value);

//        switch (val.value ().get_int64 ().value) {
//        case 0:
//            return Type::Aciklama;
//            break;
//        case 1:
//            return Type::Duzeltme;
//            break;
//        case 2:
//            return Type::Dosya;
//            break;
//        case 3:
//            return Type::Dosya;
//            break;

//        default:
//            return Type::bilinmeyen;
//            break;
//        }
    }

    return Type::bilinmeyen;
}

SerikBLDCore::Imar::DuzeltmeLog SerikBLDCore::Imar::MimariLog::toDuzeltmeLog()
{
    auto duzeltme = new DuzeltmeLog();
    duzeltme->setDocumentView (this->view ());
    return *duzeltme;
}

SerikBLDCore::Imar::AciklamaLog SerikBLDCore::Imar::MimariLog::toAciklamaLog()
{
    auto duzeltme = new AciklamaLog();
    duzeltme->setDocumentView (this->view ());
    return *duzeltme;
}

SerikBLDCore::Imar::DosyaLog SerikBLDCore::Imar::MimariLog::toDosyaLog()
{
    auto duzeltme = new DosyaLog();
    duzeltme->setDocumentView (this->view ());
    return *duzeltme;
}

SerikBLDCore::Imar::IslemLog SerikBLDCore::Imar::MimariLog::toIslemLog()
{
    auto duzeltme = new IslemLog();
    duzeltme->setDocumentView (this->view ());
    return *duzeltme;
}






SerikBLDCore::Imar::DuzeltmeLog::DuzeltmeLog()
{
    this->setType (MimariLog::Type::Duzeltme);
}

SerikBLDCore::Imar::DuzeltmeLog &SerikBLDCore::Imar::DuzeltmeLog::setDuzeltme(const std::string &duzeltme)
{
    this->append(MimariLog::keyAciklama,duzeltme);
    return *this;
}

SerikBLDCore::Imar::DuzeltmeLog &SerikBLDCore::Imar::DuzeltmeLog::setDuzeltildi(const bool &duzeltildi)
{
    this->append(MimariLog::keyDuzeltildi,duzeltildi);
    return *this;
}

std::string SerikBLDCore::Imar::DuzeltmeLog::duzeltme() const
{
    auto val = this->element (keyAciklama);
    if( val ){
        return val.get ().get_utf8 ().value.to_string();
    }
    return "";
}

bool SerikBLDCore::Imar::DuzeltmeLog::duzeltildi() const
{
    auto val = this->element (keyDuzeltildi);
    if( val ){
        return val.get ().get_bool ().value;
    }
    return false;
}

SerikBLDCore::Imar::AciklamaLog::AciklamaLog()
{
    this->setType (MimariLog::Type::Aciklama);
}

SerikBLDCore::Imar::AciklamaLog &SerikBLDCore::Imar::AciklamaLog::setAciklama(const std::string &aciklama)
{
    this->append(MimariLog::keyAciklama,aciklama);
    return *this;
}

std::string SerikBLDCore::Imar::AciklamaLog::aciklama() const
{
    auto val = this->element (keyAciklama);
    if( val ){
        return val.get ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Imar::MimariLogManager::MimariLogManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<MimariLog> (_db)
{

}

void SerikBLDCore::Imar::MimariLogManager::onList(const QVector<SerikBLDCore::Imar::MimariLog> *mlist)
{

}

void SerikBLDCore::Imar::MimariLogManager::errorOccured(const std::string &errorText)
{

}

SerikBLDCore::Imar::DosyaLog::DosyaLog()
{
    this->setType (MimariLog::Type::Dosya);
}

SerikBLDCore::Imar::DosyaLog &SerikBLDCore::Imar::DosyaLog::setFileOid(const bsoncxx::oid &fileOid)
{
    this->append(MimariLog::keyDosyaOid,fileOid);
    return *this;
}

SerikBLDCore::Imar::DosyaLog &SerikBLDCore::Imar::DosyaLog::setFileName(const std::string &fileName)
{
    this->append(MimariLog::keyAciklama,fileName);
    return *this;
}

std::string SerikBLDCore::Imar::DosyaLog::fileOid() const
{
    auto val = this->element (keyDosyaOid);
    if( val ){
        return val.get ().get_oid ().value.to_string();
    }
    return "";
}

std::string SerikBLDCore::Imar::DosyaLog::fileName() const
{
    auto val = this->element (keyAciklama);
    if( val ){
        return val.get ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Imar::IslemLog::IslemLog()
{
    this->setType (MimariLog::Type::Log);
}

SerikBLDCore::Imar::IslemLog &SerikBLDCore::Imar::IslemLog::setLog(const std::string &fileOid)
{
    this->append(MimariLog::keyAciklama,fileOid);
    return *this;
}

std::string SerikBLDCore::Imar::IslemLog::log() const
{
    auto val = this->element (keyAciklama);
    if( val ){
        return val.get ().get_utf8 ().value.to_string();
    }
    return "";
}
