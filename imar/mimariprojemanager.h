#ifndef MIMARIPROJEMANAGER_H
#define MIMARIPROJEMANAGER_H

#include "mimariproje.h"
#include "listitem.h"


namespace SerikBLDCore {


namespace Imar {


class SERIKBLDCORE_EXPORT MimariProjeManager : public SerikBLDCore::ListItem<SerikBLDCore::Imar::MimariProje::MimariProje>
{
public:
    explicit MimariProjeManager(DB *_db);

    void onList(const QVector<SerikBLDCore::Imar::MimariProje::MimariProje> *mlist) override;

    void errorOccured(const std::string &errorText) override;
};


}


}



#endif // MIMARIPROJEMANAGER_H
