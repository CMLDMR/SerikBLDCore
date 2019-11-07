#ifndef DILEKCEACIKLAMA_H
#define DILEKCEACIKLAMA_H

#include "item.h"
#include "db.h"

class SERIKBLDCORE_EXPORT DilekceAciklama : public Item
{
    static const std::string Collection;
    const std::string KeydilekceOid{"dilekceOid"};
    const std::string Keyaciklama{"aciklama"};
    const std::string KeypersonelOid{"personelOid"};
    const std::string KeyGorunur{"Gorunur"};
    const std::string JulianDay{"julianDay"};
    const std::string KeyPersonelName{"PersonelName"};
    const std::string KeySaat{"Saat"};
public:
    DilekceAciklama( DilekceAciklama* other = nullptr );
    DilekceAciklama( const DilekceAciklama &other );
    DilekceAciklama( DilekceAciklama &&other );

    DilekceAciklama& operator=( const DilekceAciklama &other );
    DilekceAciklama& operator=( DilekceAciklama &&other );

    void setDilekceOid( const std::string &dilekceOid );
    void setAciklama( const std::string &aciklama );
    void setPersonelOid( const std::string &personelOid );
    void setPersonelName( const std::string &adSoyad );
    void setGorunur( const bool &gorunur );
    void setJulianDay( const int &julianDay );
    void setSaat( const std::string &saat );

    QString PersonelOid() const;
    QString Aciklama() const;
    QString DilekceOid() const;
    bool Gorunur() const;
    QString Tarih() const;
    QString PersonelName() const;
    QString Saat() const;
    operator bool() const;
};

#endif // DILEKCEACIKLAMA_H
