#include "personelmanager.h"



SerikBLDCore::PersonelManager::PersonelManager(DB *_mDB) : ListItem<IK::Personel>(_mDB)
{

}

SerikBLDCore::PersonelManager::PersonelManager(mongocxx::database *_db) : ListItem<IK::Personel>(new DB(_db))
{

}

QVector<SerikBLDCore::IK::Personel> SerikBLDCore::PersonelManager::PersonelList(const std::string &birim)
{
    QVector<IK::Personel> list;
    IK::Personel personel;
    personel.setBirim (birim.c_str ());
    auto cursor = this->find (personel);
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

SerikBLDCore::BirimManager::BirimManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<IK::BirimItem> (_db)
{

}

void SerikBLDCore::BirimManager::onList(const QVector<IK::BirimItem> *mlist)
{

}
