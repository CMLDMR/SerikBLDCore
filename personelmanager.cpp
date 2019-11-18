#include "personelmanager.h"

SerikBLDCore::PersonelManager::PersonelManager() : DB()
{

}

SerikBLDCore::PersonelManager::PersonelManager(DB *_mDB) : DB(_mDB)
{

}

SerikBLDCore::PersonelManager::PersonelManager(mongocxx::database *_db) : DB(_db)
{

}

QVector<SerikBLDCore::Personel> SerikBLDCore::PersonelManager::PersonelList(const std::string &birim)
{
    QVector<Personel> list;
    Personel personel;
    personel.setBirim (birim.c_str ());
    auto cursor = this->find (personel);
    if( cursor )
    {
        for( auto item : cursor.value () )
        {
            Personel _item;
            _item.setDocumentView (item);
            list.push_back (_item);
        }
    }
    return list;
}
