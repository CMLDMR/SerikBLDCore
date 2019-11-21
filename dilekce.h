#ifndef DILEKCE_H
#define DILEKCE_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"
#include "personel.h"


namespace SerikBLDCore {
namespace DilekceDurum {
static const std::string Acik{"Acik"};
static const std::string Cevaplandi{"Cevaplandi"};
static const std::string RedEdildi{"RedEdildi"};
} // namespace DilekceDurum


class SERIKBLDCORE_EXPORT Dilekce : public Item
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
    static const std::string KeyOid;
    static const std::string KeyGorevliPersonel;
    static const std::string KeyDilekceDurum;
    static const std::string KeyCevapOid;
    static const std::string KeyYil;
    static const std::string KeyAy;
public:
    explicit Dilekce(Dilekce* other = nullptr);

    operator bool() const;

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
    void SetOid( const QString &oid );
    void AddGorevliPersonel(const Personel &personel );
    void DeleteGorevliPersonel( const Personel &personel );
    void SetDurum( const QString &dilekceDurum);
    void SetCevapOid( const QString &cevapOid );
    Dilekce& setYil( const int& yil );
    Dilekce& setAy( const QString& ay);

    int sayi() const;
    QString konu() const;
    QString tcoid() const;
    QString birim() const;
    QString icerikTipi() const;
    QString icerik() const;
    int tarihJulian() const;
    QString tarihText() const;
    int saatMSecStartofDay() const;
    QString saatText() const;
    QString dilekceOid() const;
    QStringList EkOidList() const;
    QVector<Personel> GorevliList() const;
    QVector<QString> BilgiBirimList() const;
    QString Durum() const;
    QString cevapOid() const;
};


}






#endif // DILEKCE_H
