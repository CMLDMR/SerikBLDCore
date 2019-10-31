#include "tcmanager.h"



TCManager::TCManager() : DB()
{
    std::cout << __LINE__ << " " << __FUNCTION__ << " " << "TCManager::TCManager()" << std::endl;

}



TCManager::TCManager(DB *mDB)
    : DB(mDB)
{
    std::cout << __LINE__ << " " << __FUNCTION__ << " " << "TCManager::TCManager(DB *mDB)" << std::endl;

}

//TCManager::TCManager(const DB *mDB) : DB(*mDB)
//{

//}

TCManager::TCManager(mongocxx::database *_db) : DB(_db)
{

}


boost::optional<TC> TCManager::Create_TC()
{
    auto item = new TC();

    try {
        auto ins = this->db ()->collection (TC::Collection).insert_one (item->view ());
        if( ins )
        {
            item->setOid (ins.value ().inserted_id ().get_oid ().value.to_string ());
            return *item;
        }else{
            return boost::none;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }


}

bool TCManager::insertTC(TC *item)
{

    {
        TC _item;
        _item.setTCNO (item->TCNO ());
        auto exist = this->countItem (*item);

        if( exist > 0 )
        {
            std::cout << TC::Collection << " " << __LINE__ << " " << __FUNCTION__ << " tcno Exist" << std::endl;
            return false;
        }
    }

    {
        TC _item;
        _item.setCepTelefonu (item->CepTelefonu ());
        auto exist = this->countItem (*item);

        if( exist > 0 )
        {
            std::cout << TC::Collection << " " << __LINE__ << " " << __FUNCTION__ << " tcno Exist" << std::endl;
            return false;
        }
    }

    auto val = this->insertItem (*item);

    if( val )
    {
        if( val.value ().result ().inserted_count () ){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }


}

boost::optional<TC *> TCManager::Load_byTCNO(const std::string &tcno)
{
    TC* item = new TC();
    item->setTCNO (tcno.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }

}

boost::optional<TC *> TCManager::Load_byTEL(const std::string &tel)
{
    TC* item = new TC();
    item->setCepTelefonu (tel.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}

boost::optional<TC *> TCManager::Load_byOID(const std::string &oid)
{
    TC* item = new TC();
    item->setOid (oid.c_str ());
    item->printView ();

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}

boost::optional<TC *> TCManager::Load_byOID(const bsoncxx::oid &oid)
{
    TC* item = new TC();
    item->setOid (oid.to_string ());
    item->printView ();

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}
