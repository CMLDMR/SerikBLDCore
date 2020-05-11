#ifndef FIRMAMANAGER_H
#define FIRMAMANAGER_H

#include "listitem.h"
#include "firmaitem.h"


namespace SerikBLDCore{


namespace Firma {


class SERIKBLDCORE_EXPORT FirmaManager : public SerikBLDCore::ListItem<SerikBLDCore::Firma::FirmaItem>
{
public:
    explicit FirmaManager( SerikBLDCore::DB* _db );

    void onList(const QVector<FirmaItem> *mlist) override;

    void errorOccured(const std::string &errorText) override;

    bool existFirmaKey( const std::string& key , const std::string& value );
};

}



}



#endif // FIRMAMANAGER_H
