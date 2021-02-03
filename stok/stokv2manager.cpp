#include "stokv2manager.h"

SerikBLDCore::Stokv2::Stokv2Manager::Stokv2Manager(DB *_mDB)
    :SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Stok> (_mDB),
      SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Kategori> (_mDB)
{

}

void SerikBLDCore::Stokv2::Stokv2Manager::onList(const QVector<SerikBLDCore::Stokv2::Stok> *mlist)
{

}

void SerikBLDCore::Stokv2::Stokv2Manager::onList(const QVector<SerikBLDCore::Stokv2::Kategori> *mlist)
{

}

void SerikBLDCore::Stokv2::Stokv2Manager::errorOccured(const std::string &errorText)
{

}

void SerikBLDCore::Stokv2::Stokv2Manager::updateStokList(const SerikBLDCore::Stokv2::Stok &filter, const SerikBLDCore::FindOptions &options)
{
    SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Stok>::UpdateList (filter,options);
}

void SerikBLDCore::Stokv2::Stokv2Manager::updateStokKategoriList(const SerikBLDCore::Stokv2::Kategori &filter, const SerikBLDCore::FindOptions &options)
{
    SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Kategori>::UpdateList (filter,options);
}


