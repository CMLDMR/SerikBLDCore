#ifndef MIMARIPROJEMANAGER_H
#define MIMARIPROJEMANAGER_H

#include "mimariproje.h"
#include "listitem.h"


namespace SerikBLDCore {


namespace Imar {



class SERIKBLDCORE_EXPORT MainProjeManager : public SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::MainProje>
{
public:
    explicit MainProjeManager(DB *_db);
    void onList(const QVector<SerikBLDCore::Imar::MimariProje::MainProje> *mlist) override;
    void errorOccured(const std::string &errorText) override;
};





class SERIKBLDCORE_EXPORT BaseProjeManager : public SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::BaseProject>
{
public:
    explicit BaseProjeManager(DB *_db);
    void onList(const QVector<SerikBLDCore::Imar::MimariProje::BaseProject> *mlist) override;
    void errorOccured(const std::string &errorText) override;
};


}


}



#endif // MIMARIPROJEMANAGER_H
