#ifndef TALEPITEM_H
#define TALEPITEM_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"

namespace Talep {

namespace Key {
static const std::string Collection{"Talep"};
}


class SERIKBLDCORE_EXPORT TalepItem : public Item
{
public:
    TalepItem(TalepItem* other = nullptr );
};




}



#endif // TALEPITEM_H
