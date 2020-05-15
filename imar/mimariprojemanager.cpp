#include "mimariprojemanager.h"



SerikBLDCore::Imar::MimariProjeManager::MimariProjeManager( SerikBLDCore::DB* _db )
    :SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::MimariProje> (_db)
{

}

void SerikBLDCore::Imar::MimariProjeManager::onList(const QVector<SerikBLDCore::Imar::MimariProje::MimariProje> *mlist)
{

}

void SerikBLDCore::Imar::MimariProjeManager::errorOccured(const std::string &errorText)
{

}
