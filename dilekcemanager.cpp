#include "dilekcemanager.h"
#include "tc.h"


DilekceManager::DilekceManager() : DB()
{

}



boost::optional<Dilekce *> DilekceManager::Create_Dilekce()
{
        auto item = new Dilekce();

        try {
            auto ins = this->db ()->collection (Dilekce::Collection).insert_one (item->view ());
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

bool DilekceManager::Update(Dilekce *dilekce)
{
        auto filter = document{};
        auto oid = dilekce->element ("_id");

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
                setDoc.append (kvp("$set",dilekce->view ()));
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                std::cout << str << std::endl;
            }

            auto upt = this->db ()->collection (Dilekce::Collection).update_one (filter.view (),setDoc.view ());

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

bool DilekceManager::insertDilekce(const Dilekce *dilekce)
{

    try {
        auto ins = this->insertItem (*dilekce);
        if( ins )
        {
            return true;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }

}

QVector<Dilekce> DilekceManager::findDilekce(const Item &itemFilter)
{
    QVector<Dilekce> list;
    auto cursor = this->find (itemFilter);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<Dilekce> DilekceManager::findByTelefon(const QString &mTelefonNumarasi)
{
    QVector<Dilekce> list;
    std::string TCOid;

    {
        TC item;
        item.setCepTelefonu (mTelefonNumarasi);

        auto val = this->findOneItem (item);

        if( val )
        {
            item.setDocumentView (val.value ().view ());
            TCOid = item.oid ().value ().to_string ();
        }else{
            return list;
        }

    }



    Dilekce item;
    item.SetTCOid (TCOid.c_str ());

    auto cursor = this->find (item);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<Dilekce> DilekceManager::findByTCNO(const QString &mTCNO)
{
    QVector<Dilekce> list;
    std::string TCOid;

    {
        TC item;
        item.setTCNO (mTCNO);

        auto val = this->findOneItem (item);

        if( val )
        {
            item.setDocumentView (val.value ().view ());
            TCOid = item.oid ().value ().to_string ();
        }else{
            return list;
        }

    }



    Dilekce item;
    item.SetTCOid (TCOid.c_str ());

    auto cursor = this->find (item);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<Dilekce> DilekceManager::findBySayi(const int &sayi)
{
    QVector<Dilekce> list;
    Dilekce item;
    item.SetSayi (sayi);

    auto cursor = this->find (item);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}
