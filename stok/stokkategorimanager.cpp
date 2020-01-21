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

SerikBLDCore::Stok::StokManager::StokManager(SerikBLDCore::User *_mUser)
    :SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok> (_mUser->getDB ()),
      SerikBLDCore::Stok::StokKodManager (_mUser->getDB ()),
      SerikBLDCore::Stok::StokKategoriManager (_mUser->getDB ()),
      mUser(_mUser)
{

}

std::string SerikBLDCore::Stok::StokManager::createStok(SerikBLDCore::Stok::Stok &stok)
{
    auto countItem = SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::countItem (stok);
    if( countItem )
    {
        return "";
    }
    return SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::InsertItem (stok);
}

void SerikBLDCore::Stok::StokManager::onList(const QVector<SerikBLDCore::Stok::Stok> *mlist)
{

}

void SerikBLDCore::Stok::StokManager::errorOccured(const std::string &errorText)
{

}

bool SerikBLDCore::Stok::StokManager::addStok(const SerikBLDCore::Stok::Stok &stok)
{
    if( stok.getCollection () != StokKey::Collection )
    {
        SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::setLastError ("Stok Item Giriş Collection Değil");
        return false;
    }
    if( SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::InsertItem (stok).size () )
    {
        return true;
    }
    return false;
}

bool SerikBLDCore::Stok::StokManager::reduceStok(const SerikBLDCore::Stok::Stok &stok, const int64_t &miktar)
{
    if( stok.getCollection () != StokKey::CollectionCikis )
    {
        SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::setLastError ("Stok Item Çıkış Collection Değil");
        return false;
    }
    if( SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::InsertItem (stok).size () )
    {
        return true;
    }
    return false;
}

void SerikBLDCore::Stok::StokManager::onList(const QVector<SerikBLDCore::Stok::StokKodItem> *mlist)
{

}

void SerikBLDCore::Stok::StokManager::updateStokList(const SerikBLDCore::Stok::Stok filter)
{
    SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok>::UpdateList (filter);
}

void SerikBLDCore::Stok::StokManager::updateStokKodList(const SerikBLDCore::Stok::StokKodItem filter)
{
    SerikBLDCore::Stok::StokKodManager::UpdateList (filter);
}

void SerikBLDCore::Stok::StokManager::updateKategoriList(const SerikBLDCore::Stok::StokKategori filter)
{
    SerikBLDCore::Stok::StokKategoriManager::UpdateList (filter);

}

void SerikBLDCore::Stok::StokManager::onList(const QVector<SerikBLDCore::Stok::StokKategori> *mlist)
{

}

SerikBLDCore::User *SerikBLDCore::Stok::StokManager::user() const
{
    return mUser;
}
