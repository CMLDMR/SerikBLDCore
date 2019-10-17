#include "dilekce.h"


 const std::string Dilekce::Collection = "Dilekce";

Dilekce::Dilekce() : Item() , DB()
{

}

Dilekce::Dilekce(Dilekce *other) : Item() , DB()
{
    this->setDocumentView (other->view ());
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

void Dilekce::SetKonu(const std::string &konu)
{
    this->append(KeyKonu,konu);
}

void Dilekce::SetTCOid(const std::string &oid)
{
    this->append(KeyTCOid,bsoncxx::oid{oid});
}

void Dilekce::SetBirim(const std::string &birim)
{
    this->append(KeyBirim,birim);
}

void Dilekce::SetIcerikTipi(const std::string &icerikTipi)
{
    this->append(KeyIcerikTipi,icerikTipi);
}

void Dilekce::SetIcerik(const std::string &icerik)
{
    this->append(KeyIcerik,icerik);
}

void Dilekce::SetDilekceOid(const std::string &dilekceOid)
{
    this->append(KeyDilekceOid,dilekceOid);
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
