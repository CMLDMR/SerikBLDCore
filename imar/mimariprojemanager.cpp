#include "mimariprojemanager.h"



SerikBLDCore::Imar::MainProjeManager::MainProjeManager( SerikBLDCore::DB* _db )
    :SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::MainProje> (_db)
{

}

void SerikBLDCore::Imar::MainProjeManager::onList(const QVector<SerikBLDCore::Imar::MimariProje::MainProje> *mlist)
{

}

void SerikBLDCore::Imar::MainProjeManager::errorOccured(const std::string &errorText)
{

}



SerikBLDCore::Imar::BaseProjeManager::BaseProjeManager(SerikBLDCore::DB *_db)
    :SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::BaseProject> (_db)
{

}

void SerikBLDCore::Imar::BaseProjeManager::onList(const QVector<SerikBLDCore::Imar::MimariProje::BaseProject> *mlist)
{

}

void SerikBLDCore::Imar::BaseProjeManager::errorOccured(const std::string &errorText)
{

}
