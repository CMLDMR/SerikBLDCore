#ifndef TALEP_H
#define TALEP_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"


class SERIKBLDCORE_EXPORT Talep : public Item
{
    static const std::string Collection;
    static const std::string KeyTCOID;
    static const std::string KeyMahalle;
    static const std::string KeyAdres;
    static const std::string KeyKonu;
    static const std::string KeySecStartOfDay;
    static const std::string KeyJulianDay;


public:
    Talep(Talep* other = nullptr );

    void setTCOID( const QString &tcoid );
    void setMahalle( const QString &mahalle );
    void setAddress( const QString &address );
    void setKonu( const QString &konu );
    void setSec( const int &mSecStartOfDay );
    void setJulianDay( const int &julianDay );


    QString tcOid() const;
    QString mahalle() const;
    QString adres() const;
    QString konu() const;
    QString saat() const;
    QString tarih() const;

};




#endif // TALEPITEM_H
