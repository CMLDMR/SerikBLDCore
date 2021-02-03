#ifndef STOKV2MANAGER_H
#define STOKV2MANAGER_H

#include "stok/stokv2.h"
#include "listitem.h"
#include "user.h"

namespace SerikBLDCore {

namespace Stokv2 {




class SERIKBLDCORE_EXPORT Stokv2Manager : public SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Stok> ,
        public SerikBLDCore::ListItem<SerikBLDCore::Stokv2::Kategori>
{
public:
    explicit Stokv2Manager(SerikBLDCore::DB* _mDB);

    virtual void onList( const QVector<SerikBLDCore::Stokv2::Stok> *mlist ) override;

    virtual void onList( const QVector<SerikBLDCore::Stokv2::Kategori> *mlist ) override;

    virtual void errorOccured( const std::string &errorText ) override;

    void updateStokList( const Stokv2::Stok &filter , const SerikBLDCore::FindOptions &options = SerikBLDCore::FindOptions() );

    void updateStokKategoriList( const Stokv2::Kategori &filter , const SerikBLDCore::FindOptions &options = SerikBLDCore::FindOptions() );


};

}




}



#endif // STOKV2MANAGER_H
