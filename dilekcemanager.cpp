#include "dilekcemanager.h"
#include "tc.h"


SerikBLDCore::DilekceManager::DilekceManager() : DB()
{

}

SerikBLDCore::DilekceManager::DilekceManager(DB *mDB) : DB(mDB)
{

}

SerikBLDCore::DilekceManager::DilekceManager(mongocxx::database *_db) : DB(_db)
{

}



boost::optional<SerikBLDCore::Dilekce *> SerikBLDCore::DilekceManager::Create_Dilekce()
{
    auto item = new SerikBLDCore::Dilekce();

    try {
        auto ins = this->db ()->collection (SerikBLDCore::Dilekce::Collection).insert_one (item->view ());
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

bool SerikBLDCore::DilekceManager::Update(SerikBLDCore::Dilekce *dilekce)
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

        auto upt = this->db ()->collection (SerikBLDCore::Dilekce::Collection).update_one (filter.view (),setDoc.view ());

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

bool SerikBLDCore::DilekceManager::insertDilekce(const SerikBLDCore::Dilekce *dilekce)
{

    try {
        auto ins = this->insertItem (*dilekce);
        if( ins )
        {
            if( ins.value ().result ().inserted_count () )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }

}

boost::optional<bsoncxx::oid> SerikBLDCore::DilekceManager::insertCevap(const SerikBLDCore::DilekceCevap *cevap)
{
    try {
        auto ins = this->insertItem (*cevap);
        if( ins )
        {
            if( ins.value ().result ().inserted_count () )
            {
                return ins.value ().inserted_id ().get_oid ().value;
            }else{
                return boost::none;
            }
        }else{
            return boost::none;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }
}

bool SerikBLDCore::DilekceManager::updateDilekce(const SerikBLDCore::Dilekce *dilekce)
{
    try {
        auto upt = this->updateItem (*dilekce);
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
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }
}

bool SerikBLDCore::DilekceManager::insertAciklama(const DilekceAciklama *aciklama)
{
    try {
        auto ins = this->insertItem (*aciklama);
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

QVector<SerikBLDCore::Dilekce> SerikBLDCore::DilekceManager::findDilekce(const Item &itemFilter, const mongocxx::options::find findOptions)
{
    QVector<SerikBLDCore::Dilekce> list;
    auto cursor = this->find (itemFilter);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            SerikBLDCore::Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<SerikBLDCore::Dilekce> SerikBLDCore::DilekceManager::findByTelefon(const QString &mTelefonNumarasi)
{
    QVector<SerikBLDCore::Dilekce> list;
    std::string TCOid;

    {
        SerikBLDCore::TC item;
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



    SerikBLDCore::Dilekce item;
    item.SetTCOid (TCOid.c_str ());

    auto cursor = this->find (item);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            SerikBLDCore::Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<SerikBLDCore::Dilekce> SerikBLDCore::DilekceManager::findByTCNO(const QString &mTCNO)
{
    QVector<SerikBLDCore::Dilekce> list;
    std::string TCOid;

    {
        SerikBLDCore::TC item;
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



    SerikBLDCore::Dilekce item;
    item.SetTCOid (TCOid.c_str ());

    auto cursor = this->find (item);
    if( cursor )
    {
        for( auto doc : cursor.get () )
        {
            SerikBLDCore::Dilekce _dilekce;
            _dilekce.setDocumentView (doc);
            list.append (_dilekce);
        }
    }
    return list;
}

QVector<SerikBLDCore::Dilekce> SerikBLDCore::DilekceManager::findBySayi(const int &sayi)
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

QVector<SerikBLDCore::DilekceAciklama> SerikBLDCore::DilekceManager::findAciklama(const std::string &dilekceOid )
{
    QVector<DilekceAciklama> list;
    DilekceAciklama item;
    item.setDilekceOid (dilekceOid);
    {
        auto cursor = this->find (item);
        if( cursor )
        {
            for( auto doc : cursor.get () )
            {
                DilekceAciklama *_dilekce = new DilekceAciklama;
                _dilekce->setDocumentView (doc);
                list.append (*_dilekce);
            }
        }
    }
    return list;
}

bool SerikBLDCore::DilekceManager::deleteAciklama(const std::string &oid)
{
    DilekceAciklama item;
    item.setOid (oid);

    auto del = this->deleteItem (item);
    if( del )
    {
        if( del.value ().deleted_count () )
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

}

boost::optional<SerikBLDCore::Dilekce *> SerikBLDCore::DilekceManager::LoadDilekce(const std::string &oid)
{
    if( oid.size () == 24 )
    {
        Dilekce *item = new Dilekce();
        item->SetOid (QString::fromStdString (oid));

        item->printView ();

        auto val = this->findOneItem (*item);
        if( val )
        {
            item->setDocumentView (val.value ().view ());
            return item;
        }else{
            return boost::none;
        }
    }else{
        return boost::none;
    }
}


boost::optional<SerikBLDCore::DilekceCevap *> SerikBLDCore::DilekceManager::LoadDilekceCevap(const std::string &cevapOid)
{
    DilekceCevap* item = new DilekceCevap();
    item->setOid (cevapOid);
    auto val = this->findOneItem (*item);
    if( val )
    {
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        return boost::none;
    }
}


QString SerikBLDCore::DilekceManager::TaranmisDilekcePath(const QString &taranmisdilekceOid)
{
    auto val = this->downloadFile (taranmisdilekceOid);
    return QString::fromStdString (val);
}

bool SerikBLDCore::DilekceManager::insertYeniKategori(const QString &yeniKategori)
{
    Item item("dilekceKategori");

    item.append("name",yeniKategori.toStdString ());

    auto count = this->countItem (item);

    if( count )
    {
        return false;
    }

    auto val = this->insertItem (item);

    if( val )
    {
        if( val.value ().result ().inserted_count () ){
            return true;
        }
    }

    return false;

}

QStringList SerikBLDCore::DilekceManager::Kategorilist()
{

    QStringList list;

    Item item("dilekceKategori");

    auto cursor = this->find (item,1000);

    if( cursor ){
        for( auto doc : cursor.value () )
        {
            list.append (doc["name"].get_utf8 ().value.to_string().c_str ());
        }
    }

    return list;
}

bool SerikBLDCore::DilekceManager::deleteKategori(const QString &kategoriName)
{
    Item item("dilekceKategori");

    item.append("name",kategoriName.toStdString ());

    auto del = this->deleteItem (item);

    if( del )
    {
        if( del.value ().deleted_count () )
        {
            return true;
        }
    }
    return false;
}

bool SerikBLDCore::DilekceManager::reNameKategori(const QString &oldName, const QString &newName)
{
    Item item("dilekceKategori");
    item.append("name",oldName.toStdString ());

    auto count  = this->countItem (item);

    if( count )
    {
        if( !this->deleteItem (item) )
        {
            return false;
        }
    }
    item.removeElement ("name");

    item.append("name",newName.toStdString ());

    auto ins = this->insertItem (item);

    if( ins )
    {
        if( ins.value ().result ().inserted_count () )
        {
            return true;
        }
    }

    return false;

}
