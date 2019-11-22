#ifndef BILGIEDINMEMANAGER_H
#define BILGIEDINMEMANAGER_H

#include "bilgiedinmeitem.h"
#include "listitem.h"
#include "SerikBLDCore_global.h"


namespace SerikBLDCore {

namespace BilgiEdinme {
class SERIKBLDCORE_EXPORT BilgiEdinmeManager : public SerikBLDCore::ListItem<BilgiEdinmeItem>
{
public:
    BilgiEdinmeManager(DB* db);

};
}

}




#endif // BILGIEDINMEMANAGER_H
