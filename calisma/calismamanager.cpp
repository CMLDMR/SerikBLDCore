#include "calismamanager.h"



SerikBLDCore::CalismaManager::CalismaManager(DB *db)
: SerikBLDCore::ListItem<SerikBLDCore::Calisma::Calisma> (db)
{

}

void SerikBLDCore::CalismaManager::onList(const QVector<SerikBLDCore::Calisma::Calisma> *mlist)
{

}

SerikBLDCore::CalismaKategoriManager::CalismaKategoriManager(SerikBLDCore::DB *db)
: SerikBLDCore::ListItem<SerikBLDCore::Calisma::Kategori> (db)
{

}

void SerikBLDCore::CalismaKategoriManager::onList(const QVector<SerikBLDCore::Calisma::Kategori> *mlist)
{

}
