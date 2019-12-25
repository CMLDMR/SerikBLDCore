#ifndef MECLISMANAGER_H
#define MECLISMANAGER_H

#include "listitem.h"
#include "meclisitem.h"
#include "meclisuyesi.h"

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



class SERIKBLDCORE_EXPORT RaporManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::RaporItem>
{
public:
    explicit RaporManager(DB* db);


    virtual void onList(const QVector<RaporItem> *mlist) override;

};


class SERIKBLDCORE_EXPORT TeklifManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::TeklifItem>
{
public:
    explicit TeklifManager(DB* db);

    virtual void onList(const QVector<TeklifItem> *mlist) override;

};




class SERIKBLDCORE_EXPORT UyeManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisUyesi>
{
public:
    explicit UyeManager(DB* db);

    virtual void onList(const QVector<MeclisUyesi> *mlist) override;

};


class SERIKBLDCORE_EXPORT DonemManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::MeclisDonemi>
{
public:
    explicit DonemManager(DB* db);

    virtual void onList(const QVector<MeclisDonemi> *mlist) override;

};


class SERIKBLDCORE_EXPORT PartiManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::PartiItem>
{
public:
    explicit PartiManager(DB* db);

    virtual void onList(const QVector<PartiItem> *mlist) override;

};


class SERIKBLDCORE_EXPORT KomisyonManager : public SerikBLDCore::ListItem<SerikBLDCore::Meclis::KomisyonItem>
{
public:
    explicit KomisyonManager(DB* db);

    virtual void onList(const QVector<KomisyonItem> *mlist) override;

};








}



}



#endif // MECLISMANAGER_H
