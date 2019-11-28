#ifndef BILGIEDINMEMANAGER_H
#define BILGIEDINMEMANAGER_H

#include "listitem.h"
#include "SerikBLDCore_global.h"
#include "bilgiedinmeitem.h"

namespace SerikBLDCore {

namespace BilgiEdinme {



class SERIKBLDCORE_EXPORT BilgiEdinmeManager : public SerikBLDCore::ListItem<BilgiEdinmeItem>
{
public:
    explicit BilgiEdinmeManager(DB* db);

};
}

}




#endif // BILGIEDINMEMANAGER_H
