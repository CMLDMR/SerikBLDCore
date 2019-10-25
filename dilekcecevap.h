#ifndef DILEKCECEVAP_H
#define DILEKCECEVAP_H


#include "item.h"

class SERIKBLDCORE_EXPORT DilekceCevap : public Item
{
    static const std::string Collection;
    const std::string KeyDilekceOid{"dilekceOid"};
    const std::string KeyPersonelOid{"PersonelOid"};
    const std::string KeyPersonelName{"PersonelName"};
    const std::string KeySaat{"Saat"};
    const std::string KeyJulianDay{"JulianDay"};
    const std::string KeyCevapOid{"CevapOid"};
    const std::string KeyCevapIcerik{"CevapIcerik"};
    const std::string KeyEkler{"EklerOid"};
public:
    DilekceCevap( DilekceCevap* other = nullptr );
    DilekceCevap( const DilekceCevap &other );
    DilekceCevap( DilekceCevap &&other );

    DilekceCevap& operator=( const DilekceCevap& other);
    DilekceCevap& operator=( DilekceCevap&& other );


    void setDilekceOid( const QString &dilekceOid );
    void setPersonelOid( const QString &personelOid );
    void setPersonelName( const QString &personelName );
    void setSaat( const QString &saat );
    void setJulianDay( const int &julianDay );
    void setCevapOid(const QString &cevapOid );
    void setCevapIcerik( const QString &cevapIcerik );
    void addEkOid( const QString &ekOid );


    QString dilekceOid() const;
    QString personelOid() const;
    QString personelName() const;
    QString saat() const;
    int julianDay() const;
    QString Tarih() const;
    QString cevapOid() const;
    QString cevapIcerik() const;
    QVector<QString> ekList() const;

};

#endif // DILEKCECEVAP_H
