#ifndef BILGIEDINMEMANAGER_H
#define BILGIEDINMEMANAGER_H

#include "listitem.h"
#include "SerikBLDCore_global.h"
#include "bilgiedinmeitem.h"

namespace SerikBLDCore {


class SERIKBLDCORE_EXPORT BilgiEdinmeManager : public SerikBLDCore::ListItem<BilgiEdinmeItem>
{
public:
    explicit BilgiEdinmeManager(DB* db);

protected:
    virtual void onList( const QVector<BilgiEdinmeItem>  *mlist ) override {}

};


}




#endif // BILGIEDINMEMANAGER_H
