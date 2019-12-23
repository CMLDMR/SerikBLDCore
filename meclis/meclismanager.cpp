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
