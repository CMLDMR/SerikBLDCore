#ifndef CALISMAMANAGER_H
#define CALISMAMANAGER_H

#include "listitem.h"
#include "calisma/calismaitem.h"



namespace SerikBLDCore {


class SERIKBLDCORE_EXPORT CalismaManager : public SerikBLDCore::ListItem<SerikBLDCore::Calisma>
{
public:
    explicit CalismaManager( DB* db );

    virtual void onList(const QVector<Calisma> *mlist) override;

};


}



#endif // CALISMAMANAGER_H
