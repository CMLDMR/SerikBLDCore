#ifndef TALEP_H
#define TALEP_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"

class SERIKBLDCORE_EXPORT TalepKey
{
public:
    static const std::string Collection;
    static const std::string TCOID;
    static const std::string Mahalle;
    static const std::string Adres;
    static const std::string Konu;
    static const std::string SecStartOfDay;
    static const std::string JulianDay;
    static const std::string Birim;

};


class SERIKBLDCORE_EXPORT Talep : public Item
{
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
    int julianDay() const;
    int mSecStartOfDay() const;

};




#endif // TALEPITEM_H
