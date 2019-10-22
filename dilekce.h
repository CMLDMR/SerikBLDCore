#ifndef DILEKCE_H
#define DILEKCE_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"



class SERIKBLDCORE_EXPORT Dilekce : public Item /*, public DB*/
{
public:
    static const std::string Collection;
    static const std::string KeySayi;
    static const std::string KeyKonu;
    static const std::string KeyTCOid;
    static const std::string KeyBirim;
    static const std::string KeyIcerikTipi;
    static const std::string KeyIcerik;
    static const std::string KeyDilekceOid;
    static const std::string KeyEkler;
    static const std::string KeyTarihJulian;
    static const std::string KeySaat;
    static const std::string KeyBilgiBirimler;
public:
    explicit Dilekce(Dilekce* other = nullptr);



    void SetSayi( const int &sayi );
    void SetKonu( const QString &konu);
    void SetTCOid( const QString &oid);
    void SetBirim( const QString &birim);
    void SetIcerikTipi(const QString &icerikTipi);
    void SetIcerik( const QString &icerik);
    void SetDilekceOid( const QString &dilekceOid);
    void AddEkOid( const QString &ekOid );
    void SetTarih( const int &julianDay );
    void SetSaat( const int &mSecsFromBeginDay );
    void AddBilgiBirim( const QString &bilgiBirim );

    int sayi();
    QString konu();
    QString tcoid();
    QString birim();
    QString icerikTipi();
    QString icerik();
    int tarihJulian();
    QString tarihText();
    int saatMSecStartofDay();
    QString saatText();





private:

};

#endif // DILEKCE_H
