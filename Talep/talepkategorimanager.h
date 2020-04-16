#ifndef TALEPKATEGORIMANAGER_H
#define TALEPKATEGORIMANAGER_H


#include "talepkategori.h"
#include "listitem.h"
#include "Config.h"


namespace SerikBLDCore {


class SERIKBLDCORE_EXPORT TalepKategoriManager : public ListItem<SerikBLDCore::TalepKategori>
{
public:
    explicit TalepKategoriManager( DB* _mDB );



    virtual void onList(const QVector<SerikBLDCore::TalepKategori> *mlist) override;

    virtual void errorOccured(const std::string &errorText) override;

    QString KategoriName(const QString& kategoriOid ) const;
};

}



#endif // TALEPKATEGORIMANAGER_H
