#ifndef STOKKATEGORIMANAGER_H
#define STOKKATEGORIMANAGER_H

#include "stok.h"
#include "listitem.h"

namespace SerikBLDCore {

namespace Stok {
class SERIKBLDCORE_EXPORT StokKategoriManager : public SerikBLDCore::ListItem<SerikBLDCore::Stok::StokKategori>
{
public:
    explicit StokKategoriManager( SerikBLDCore::DB* _db );

    virtual void errorOccured(const std::string &errorText) override;

    virtual void onList(const QVector<SerikBLDCore::Stok::StokKategori> *mlist) override;
};



class SERIKBLDCORE_EXPORT StokKodManager : public SerikBLDCore::ListItem<SerikBLDCore::Stok::StokKodItem>
{
public:
    explicit StokKodManager( SerikBLDCore::DB* _db );

    virtual void onList(const QVector<StokKodItem> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;
};


}


}



#endif // STOKKATEGORIMANAGER_H
