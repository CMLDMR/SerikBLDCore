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
};



class SERIKBLDCORE_EXPORT BirimManager : public ListItem<IK::BirimItem>
{
public:
    explicit BirimManager( DB* _db );

    void onList(const QVector<IK::BirimItem> *mlist) override;
};

};

#endif // PERSONELMANAGER_H
