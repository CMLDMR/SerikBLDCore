#include "dilekce.h"


const std::string Dilekce::Collection = "Dilekce";



Dilekce::Dilekce(Dilekce *other) : Item(Dilekce::Collection) , DB()
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

boost::optional<Dilekce *> Dilekce::Create_Dilekce()
{
    auto item = new Dilekce();

    try {
        auto ins = item->db ()->collection (Collection).insert_one (item->view ());
        if( ins )
        {
            item->append("_id",ins.value ().inserted_id ().get_oid ().value );
            return item;
        }else{
            return boost::none;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }
}

void Dilekce::SetSayi(const int &sayi)
{
    this->append(KeySayi,sayi);
}

void Dilekce::SetKonu(const QString &konu)
{
    this->append(KeyKonu,konu.toStdString ());
}

void Dilekce::SetTCOid(const QString &oid)
{
    this->append(KeyTCOid,bsoncxx::oid{oid.toStdString ()});
}

void Dilekce::SetBirim(const QString &birim)
{
    this->append(KeyBirim,birim.toStdString ());
}

void Dilekce::SetIcerikTipi(const QString &icerikTipi)
{
    this->append(KeyIcerikTipi,icerikTipi.toStdString ());
}

void Dilekce::SetIcerik(const QString &icerik)
{
    this->append(KeyIcerik,icerik.toStdString ());
}

void Dilekce::SetDilekceOid(const QString &dilekceOid)
{
    this->append(KeyDilekceOid,dilekceOid.toStdString ());
}

void Dilekce::AddEkOid(const QString &ekOid)
{
    //TODO: Array Eklenecek
}

void Dilekce::SetTarih(const int &julianDay)
{
    this->append(KeyTarihJulian,julianDay);
}

void Dilekce::SetSaat(const int &mSecsFromBeginDay)
{
    this->append(KeySaat,mSecsFromBeginDay);
}

int Dilekce::sayi()
{
    auto sayi = this->element (KeySayi);
    if( sayi )
    {
        return sayi->get_int32 ().value;
    }else{
        return -1;
    }
}

QString Dilekce::konu()
{
    auto value = this->element (KeyKonu);
    if( value )
    {
        return QString::fromStdString (value->get_utf8 ().value.to_string());
    }else{
        return "";
    }
}

bool Dilekce::Update()
{

    auto filter = document{};
    auto oid = this->element ("_id");

    if( oid )
    {
        try {
            filter.append (kvp("_id",oid->get_oid ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return false;
        }

        auto setDoc = document{};

        try {
            setDoc.append (kvp("$set",this->view ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }

        auto upt = this->db ()->collection (Collection).update_one (filter.view (),setDoc.view ());

        if( upt )
        {
            if( upt.value ().modified_count () )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
