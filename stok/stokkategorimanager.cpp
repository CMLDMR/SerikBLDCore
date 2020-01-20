#include "stokkategorimanager.h"


SerikBLDCore::Stok::StokKategoriManager::StokKategoriManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<SerikBLDCore::Stok::StokKategori> (_db)
{

}

void SerikBLDCore::Stok::StokKategoriManager::errorOccured(const std::string &errorText)
{

}

void SerikBLDCore::Stok::StokKategoriManager::onList(const QVector<SerikBLDCore::Stok::StokKategori> *mlist)
{

}

SerikBLDCore::Stok::StokKodManager::StokKodManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<SerikBLDCore::Stok::StokKodItem> (_db)
{

}

void SerikBLDCore::Stok::StokKodManager::onList(const QVector<SerikBLDCore::Stok::StokKodItem> *mlist)
{

}

void SerikBLDCore::Stok::StokKodManager::errorOccured(const std::string &errorText)
{

}
