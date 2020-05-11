#include "firmamanager.h"



SerikBLDCore::Firma::FirmaManager::FirmaManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<SerikBLDCore::Firma::FirmaItem> (_db)
{

}

void SerikBLDCore::Firma::FirmaManager::onList(const QVector<SerikBLDCore::Firma::FirmaItem> *mlist)
{

}

void SerikBLDCore::Firma::FirmaManager::errorOccured(const std::string &errorText)
{

}

bool SerikBLDCore::Firma::FirmaManager::existFirmaKey(const std::string &key, const std::string &value)
{
    bool returnedValue = false;

    SerikBLDCore::Firma::FirmaItem firma;
    firma.append(key,value);

    auto count = this->countItem (firma);

    if( count )
    {
        returnedValue = true;
    }




    return returnedValue;
}
