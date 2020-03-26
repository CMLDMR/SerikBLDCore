#ifndef STOKKATEGORIMANAGER_H
#define STOKKATEGORIMANAGER_H

#include "stok.h"
#include "listitem.h"
#include "user.h"

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


class SERIKBLDCORE_EXPORT StokManager :
        public SerikBLDCore::ListItem<SerikBLDCore::Stok::Stok> ,
        public SerikBLDCore::Stok::StokKodManager,
        public SerikBLDCore::Stok::StokKategoriManager
{
public:
    explicit StokManager( SerikBLDCore::User* _mUser );


    /**
     * @brief createStok: 0 miktarında Stok Oluşturur.
     * @param stok
     * @return Stok varsa false eğer stok yok ise true döndürür.
     */
    virtual std::string createStok( SerikBLDCore::Stok::Stok& stok );

    virtual void onList(const QVector<Stok> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;

    virtual bool addStok(const SerikBLDCore::Stok::Stok& stok );

    virtual bool reduceStok(const SerikBLDCore::Stok::Stok& stok , const std::int64_t& miktar );

    virtual void onList(const QVector<StokKodItem> *mlist) override;

    void updateStokList( const SerikBLDCore::Stok::Stok filter = SerikBLDCore::Stok::Stok() );

    void updateStokKodList( const SerikBLDCore::Stok::StokKodItem filter = SerikBLDCore::Stok::StokKodItem() );

    void updateKategoriList( const SerikBLDCore::Stok::StokKategori filter = SerikBLDCore::Stok::StokKategori() );

    virtual void onList(const QVector<SerikBLDCore::Stok::StokKategori> *mlist) override;

    SerikBLDCore::User* user() const;

private:
    SerikBLDCore::User* mUser;
};



}


}



#endif // STOKKATEGORIMANAGER_H
