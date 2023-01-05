#include "tcmanager.h"



SerikBLDCore::TCManager::TCManager() : DB()
{

}



SerikBLDCore::TCManager::TCManager(DB *mDB)
    : DB(mDB)
{

}

//TCManager::TCManager(const DB *mDB) : DB(*mDB)
//{

//}

SerikBLDCore::TCManager::TCManager(mongocxx::database *_db) : DB(_db)
{

}


#ifndef CPP17
boost::optional<SerikBLDCore::TC> SerikBLDCore::TCManager::Create_TC()
{
    auto item = new SerikBLDCore::TC();

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

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byTCNO(const std::string &tcno)
{

    SerikBLDCore::TC *item = new SerikBLDCore::TC();
    item->setTCNO (tcno.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return (item);
    }else{
        return boost::none;
    }

}

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byTEL(const std::string &tel)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
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

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byOID(const std::string &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byOID(const bsoncxx::oid &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.to_string ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}


#endif
#ifdef CPP17
std::optional<SerikBLDCore::TC> SerikBLDCore::TCManager::Create_TC()
{
    auto item = new SerikBLDCore::TC();

    try {
        auto ins = this->db ()->collection (TC::Collection).insert_one (item->view ());
        if( ins )
        {
            item->setOid (ins.value ().inserted_id ().get_oid ().value.to_string ());
            return *item;
        }else{
            return std::nullopt;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return std::nullopt;
    }


}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byTCNO(const std::string &tcno)
{

    SerikBLDCore::TC *item = new SerikBLDCore::TC();
    item->setTCNO (tcno.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return (item);
    }else{
        return std::nullopt;
    }

}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byTEL(const std::string &tel)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setCepTelefonu (tel.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byOID(const std::string &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManager::Load_byOID(const bsoncxx::oid &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.to_string ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}


#endif





bool SerikBLDCore::TCManager::insertTC(SerikBLDCore::TC *item)
{

    {
        SerikBLDCore::TC _item;
        _item.setTCNO (item->TCNO ());
        auto exist = this->countItem (*item);

        if( exist > 0 )
        {
            return false;
        }
    }

    {
        SerikBLDCore::TC _item;
        _item.setCepTelefonu (item->CepTelefonu ());
        auto exist = this->countItem (*item);

        if( exist > 0 )
        {
            return false;
        }
    }

    auto val = this->insertItem (*item);

    if( val )
    {
        if( val.value ().result ().inserted_count () ){
            item->setOid (val.value ().inserted_id ().get_oid ().value.to_string ());
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }


}

bool SerikBLDCore::TCManager::updateTC(SerikBLDCore::TC *tcItem)
{

    {
        SerikBLDCore::TC _item;
        _item.setTCNO (tcItem->TCNO ());
        auto exist = this->countItem (*tcItem);

        if( exist > 0 )
        {
            return false;
        }
    }

    {
        SerikBLDCore::TC _item;
        _item.setCepTelefonu (tcItem->CepTelefonu ());
        auto exist = this->countItem (*tcItem);

        if( exist > 0 )
        {
            return false;
        }
    }

    auto val = this->updateItem (*tcItem);

    if( val )
    {
        if( val.value ().modified_count () )
        {
            return true;
        }
    }

    return false;

}





SerikBLDCore::TCManagerV2::TCManagerV2(SerikBLDCore::DB *_db)
    :ListItem<SerikBLDCore::TC> (_db)
{

}

void SerikBLDCore::TCManagerV2::onList(const QVector<SerikBLDCore::TC> *mlist)
{

}

void SerikBLDCore::TCManagerV2::errorOccured(const std::string &errorText)
{

}

#ifndef CPP17


boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byTCNO(const std::string &tcno)
{
    SerikBLDCore::TC *item = new SerikBLDCore::TC();
    item->setTCNO (tcno.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return (item);
    }else{
        return boost::none;
    }
}

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byTEL(const std::string &tel)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
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

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byOID(const std::string &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}

boost::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byOID(const bsoncxx::oid &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.to_string ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}

#endif
#ifdef CPP17

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byTCNO(const std::string &tcno)
{
    SerikBLDCore::TC *item = new SerikBLDCore::TC();
    item->setTCNO (tcno.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return (item);
    }else{
        return std::nullopt;
    }
}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byTEL(const std::string &tel)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setCepTelefonu (tel.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byOID(const std::string &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.c_str ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}

std::optional<SerikBLDCore::TC *> SerikBLDCore::TCManagerV2::Load_byOID(const bsoncxx::oid &oid)
{
    SerikBLDCore::TC* item = new SerikBLDCore::TC();
    item->setOid (oid.to_string ());

    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return std::nullopt;
    }
}

#endif
