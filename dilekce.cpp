#include "dilekce.h"


 const std::string Dilekce::Collection = "Dilekce";

Dilekce::Dilekce(DB *_db) : Item() , DB(_db)
{

}

boost::optional<Dilekce *> Dilekce::Create_Dilekce(DB *_db)
{
    auto item = new Dilekce(_db);

    try {
        auto ins = _db->db ()->collection (Collection).insert_one (item->view ());
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
