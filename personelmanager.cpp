#include "personelmanager.h"



SerikBLDCore::PersonelManager::PersonelManager(DB *_mDB) : ListItem<IK::Personel>(_mDB)
{

}

SerikBLDCore::PersonelManager::PersonelManager(mongocxx::database *_db) : ListItem<IK::Personel>(new DB(_db))
{

}

QVector<SerikBLDCore::IK::Personel> SerikBLDCore::PersonelManager::PersonelList(const std::string &birim  , const int limit , const int skip )
{
    QVector<IK::Personel> list;
    IK::Personel personel;
    personel.setBirim (birim.c_str ());
    auto cursor = this->find (personel,limit,skip);
    if( cursor )
    {
        for( auto item : cursor.value () )
        {
            IK::Personel _item;
            _item.setDocumentView (item);
            list.push_back (_item);
        }
    }
    return list;
}

void SerikBLDCore::PersonelManager::onList(const QVector<SerikBLDCore::IK::Personel> *mlist)
{

}

void SerikBLDCore::PersonelManager::errorOccured(const std::string &errorText)
{

}

QVector<QString> SerikBLDCore::PersonelManager::birimList() const
{
    QVector<QString> list;
    SerikBLDCore::IK::BirimItem item;
    auto cursor = const_cast<SerikBLDCore::DB*>(this->getDB ())->find (item,100,0);
    if( cursor )
    {
        for( auto item__ : cursor.value () )
        {
            SerikBLDCore::IK::BirimItem __item;
            __item.setDocumentView (item__);
            list.push_back (__item.birimAdi ());
        }
    }
    return list;
}

QVector<QString> SerikBLDCore::PersonelManager::birimListResmi()
{
    QVector<QString> list;
    auto filter = document{};

    mongocxx::options::find findOptions;

    auto sortDoc = document{};
    sortDoc.append(kvp("sira",-1));



    filter.append(kvp("sira",make_document(kvp("$gte",bsoncxx::types::b_int32{0}))));

    findOptions.limit (100);
    findOptions.sort (sortDoc.view ());


    try{
        auto cursor = this->getDB ()->db ()->collection (SerikBLDCore::IK::BirimKey::Collection).find (filter.view (),findOptions);
            for( auto item__ : cursor )
            {
                SerikBLDCore::IK::BirimItem __item;
                __item.setDocumentView (item__);
                    list.push_back (__item.birimAdi ());

            }
    }catch(mongocxx::exception &e){
        errorOccured(e.what ());
    }


    return list;
}

QMap<QString, QString> SerikBLDCore::PersonelManager::altBirimList( const bsoncxx::oid& birimOid ) const
{
    QMap<QString, QString> list;
    SerikBLDCore::IK::AltBirimItem item;
    item.setBirimOid (birimOid);
    auto cursor = const_cast<SerikBLDCore::DB*>(this->getDB ())->find (item,100,0);
    if( cursor )
    {
        for( auto item__ : cursor.value () )
        {
            SerikBLDCore::IK::AltBirimItem __item;
            __item.setDocumentView (item__);
            list[__item.oid ().value ().to_string ().c_str ()] = __item.name ();
        }
    }
    return list;
}

QMap<QString, QString> SerikBLDCore::PersonelManager::altBirimList(const std::string &birimName) const
{
    QMap<QString, QString> list;
    SerikBLDCore::IK::AltBirimItem item;
    item.setName (birimName.c_str ());
    auto cursor = const_cast<SerikBLDCore::DB*>(this->getDB ())->find (item,100,0);
    if( cursor )
    {
        for( auto item__ : cursor.value () )
        {
            SerikBLDCore::IK::AltBirimItem __item;
            __item.setDocumentView (item__);
            list[__item.oid ().value ().to_string ().c_str ()] = __item.name ();
        }
    }
    return list;
}

std::string SerikBLDCore::PersonelManager::birimOid(const std::string &birimName)
{
    QMap<QString, QString> list;
    SerikBLDCore::IK::BirimItem item;
    item.setBirimAdi (birimName.c_str ());
    auto val = const_cast<SerikBLDCore::DB*>(this->getDB ())->findOneItem (item);
    if( val )
    {
        try {
            return val.value ().view ()["_id"].get_oid ().value.to_string ();
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            this->errorOccured (str);
            return "";
        }
    }else{
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__;
        this->errorOccured ("DB Değer Döndürmedi. "+str);
    }
    return "";
}

SerikBLDCore::BirimManager::BirimManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<IK::BirimItem> (_db)
{

}

void SerikBLDCore::BirimManager::onList(const QVector<IK::BirimItem> *mlist)
{

}

void SerikBLDCore::BirimManager::errorOccured(const std::string &errorText)
{

}

SerikBLDCore::AltBirimManager::AltBirimManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<IK::AltBirimItem> (_db)
{

}

void SerikBLDCore::AltBirimManager::errorOccured(const std::string &errorText)
{

}

void SerikBLDCore::AltBirimManager::onList(const QVector<SerikBLDCore::IK::AltBirimItem> *mlist)
{

}
