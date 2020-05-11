#ifndef PERSONELMANAGER_H
#define PERSONELMANAGER_H

#include "personel.h"
#include "listitem.h"

namespace SerikBLDCore {
class SERIKBLDCORE_EXPORT PersonelManager : public ListItem<IK::Personel>
{
public:
    explicit PersonelManager( DB* _mDB );
    explicit PersonelManager( mongocxx::database* _db );

    QVector<IK::Personel> PersonelList( const std::string &birim );

    void onList(const QVector<IK::Personel> *mlist) override;

    void errorOccured(const std::string &errorText) override;

    QVector<QString> birimList() const;

    QMap<QString,QString> altBirimList( const bsoncxx::oid &birimOid ) const;

    QMap<QString,QString> altBirimList( const std::string &birimName ) const;

    std::string birimOid( const std::string& birimName );
};



class SERIKBLDCORE_EXPORT BirimManager : public ListItem<IK::BirimItem>
{
public:
    explicit BirimManager( DB* _db );

    void onList(const QVector<IK::BirimItem> *mlist) override;

    void errorOccured(const std::string &errorText) override;
};


class SERIKBLDCORE_EXPORT AltBirimManager : public ListItem<IK::AltBirimItem>
{
public:
    explicit AltBirimManager( DB* _db );

    void errorOccured(const std::string &errorText) override;

    void onList(const QVector<IK::AltBirimItem> *mlist) override;
};

};

#endif // PERSONELMANAGER_H
