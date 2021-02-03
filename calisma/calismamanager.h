#ifndef CALISMAMANAGER_H
#define CALISMAMANAGER_H

#include "listitem.h"
#include "calisma/calismaitem.h"



namespace SerikBLDCore {


class SERIKBLDCORE_EXPORT CalismaManager : public SerikBLDCore::ListItem<SerikBLDCore::Calisma::Calisma>
{
public:
    explicit CalismaManager( DB* db );
    virtual void onList(const QVector<Calisma::Calisma> *mlist) override;

};

class SERIKBLDCORE_EXPORT CalismaKategoriManager : public SerikBLDCore::ListItem<SerikBLDCore::Calisma::Kategori>
{
public:
    explicit CalismaKategoriManager( DB* db );
    virtual void onList(const QVector<Calisma::Kategori> *mlist) override;

};



}



#endif // CALISMAMANAGER_H
