#include "meclismanager.h"


SerikBLDCore::Meclis::MeclisManager::MeclisManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisItem> (db)
{

}

void SerikBLDCore::Meclis::MeclisManager::onList(const QVector<SerikBLDCore::Meclis::MeclisItem> *mlist)
{

}

SerikBLDCore::Meclis::KararManager::KararManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::KararItem> (db)
{

}

void SerikBLDCore::Meclis::KararManager::onList(const QVector<SerikBLDCore::Meclis::KararItem> *mlist)
{

}

SerikBLDCore::Meclis::YouTubeManager::YouTubeManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::YouTubeLink> (db)
{

}

void SerikBLDCore::Meclis::YouTubeManager::onList(const QVector<SerikBLDCore::Meclis::YouTubeLink> *mlist)
{

}

SerikBLDCore::Meclis::RaporManager::RaporManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::RaporItem> (db)
{

}

void SerikBLDCore::Meclis::RaporManager::onList(const QVector<SerikBLDCore::Meclis::RaporItem> *mlist)
{

}

SerikBLDCore::Meclis::TeklifManager::TeklifManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::TeklifItem> (db)
{

}

void SerikBLDCore::Meclis::TeklifManager::onList(const QVector<SerikBLDCore::Meclis::TeklifItem> *mlist)
{

}

SerikBLDCore::Meclis::UyeManager::UyeManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisUyesi> (db)
{

}

void SerikBLDCore::Meclis::UyeManager::onList(const QVector<SerikBLDCore::Meclis::MeclisUyesi> *mlist)
{

}

std::vector<SerikBLDCore::Meclis::MeclisDonemi> SerikBLDCore::Meclis::UyeManager::getDonemList()
{
    std::vector<SerikBLDCore::Meclis::MeclisDonemi> list;
    auto cursor = this->find (SerikBLDCore::Meclis::MeclisDonemi(),0,0);
    if( cursor )
    {
        for( auto item : *cursor )
        {
            SerikBLDCore::Meclis::MeclisDonemi donem;
            donem.setDocumentView (item);
            list.push_back (donem);
        }
    }
    return list;
}

std::vector<SerikBLDCore::Meclis::PartiItem> SerikBLDCore::Meclis::UyeManager::getPartiList()
{
    std::vector<SerikBLDCore::Meclis::PartiItem> list;
    auto cursor = this->find (SerikBLDCore::Meclis::PartiItem(),0,0);
    if( cursor )
    {
        for( auto item : *cursor )
        {
            SerikBLDCore::Meclis::PartiItem donem;
            donem.setDocumentView (item);
            list.push_back (donem);
        }
    }
    return list;
}

std::vector<SerikBLDCore::Meclis::KomisyonItem> SerikBLDCore::Meclis::UyeManager::getKomisyonList()
{
    std::vector<SerikBLDCore::Meclis::KomisyonItem> list;
    auto cursor = this->find (SerikBLDCore::Meclis::KomisyonItem(),0,0);
    if( cursor )
    {
        for( auto item : *cursor )
        {
            SerikBLDCore::Meclis::KomisyonItem donem;
            donem.setDocumentView (item);
            list.push_back (donem);
        }
    }
    return list;
}

SerikBLDCore::Meclis::DonemManager::DonemManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisDonemi> (db)
{

}

void SerikBLDCore::Meclis::DonemManager::onList(const QVector<SerikBLDCore::Meclis::MeclisDonemi> *mlist)
{

}

SerikBLDCore::Meclis::PartiManager::PartiManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::PartiItem> (db)
{

}

void SerikBLDCore::Meclis::PartiManager::onList(const QVector<SerikBLDCore::Meclis::PartiItem> *mlist)

{

}

SerikBLDCore::Meclis::KomisyonManager::KomisyonManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::KomisyonItem> (db)
{

}

void SerikBLDCore::Meclis::KomisyonManager::onList(const QVector<SerikBLDCore::Meclis::KomisyonItem> *mlist)
{

}

SerikBLDCore::Meclis::GundemManager::GundemManager(SerikBLDCore::DB *db)
    : SerikBLDCore::ListItem<SerikBLDCore::Meclis::GundemItem> (db)
{

}

void SerikBLDCore::Meclis::GundemManager::onList(const QVector<SerikBLDCore::Meclis::GundemItem> *mlist)
{

}
