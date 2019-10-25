#include "personelmanager.h"

PersonelManager::PersonelManager() : DB()
{

}

PersonelManager::PersonelManager(DB *_mDB) : DB(_mDB)
{

}

PersonelManager::PersonelManager(mongocxx::database *_db) : DB(_db)
{

}

QVector<Personel> PersonelManager::PersonelList(const std::string &birim)
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
