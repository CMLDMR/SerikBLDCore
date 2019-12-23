#ifndef MECLISMANAGER_H
#define MECLISMANAGER_H

#include "listitem.h"
#include "meclisitem.h"

namespace SerikBLDCore {

namespace Meclis {



/**
 * @brief The MeclisManager class
 * Meclis Item, Kararlar ve Canlı Yayın Link Yönetimi
 */
class SERIKBLDCORE_EXPORT MeclisManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisItem>
{
public:
    explicit MeclisManager(DB* db);


    virtual void onList(const QVector<MeclisItem> *mlist) override;

};



class SERIKBLDCORE_EXPORT KararManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::KararItem>
{
public:
    explicit KararManager(DB* db);


    virtual void onList(const QVector<KararItem> *mlist) override;

};


class SERIKBLDCORE_EXPORT YouTubeManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::YouTubeLink>
{
public:
    explicit YouTubeManager(DB* db);


    virtual void onList(const QVector<YouTubeLink> *mlist) override;

};


}



}



#endif // MECLISMANAGER_H
