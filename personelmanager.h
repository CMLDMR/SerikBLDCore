#ifndef PERSONELMANAGER_H
#define PERSONELMANAGER_H

#include "personel.h"
#include "db.h"

namespace SerikBLDCore {
class SERIKBLDCORE_EXPORT PersonelManager : virtual public DB
{
public:
    PersonelManager();
    PersonelManager( DB* _mDB );
    PersonelManager( mongocxx::database* _db );

    QVector<Personel> PersonelList( const std::string &birim );
};

}

#endif // PERSONELMANAGER_H
