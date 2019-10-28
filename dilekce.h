#ifndef DILEKCE_H
#define DILEKCE_H

#include <QtGlobal>
#include "item.h"
#include "db.h"
#include <QString>
#include "SerikBLDCore_global.h"
#include "personel.h"


namespace DilekceDurum {
static const QString Acik{"Açik"};
static const QString Cevaplandi{"Cevaplandı"};
static const QString RedEdildi{"RedEdildi"};
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
    QString dilekceOid();
    QStringList EkOidList();
    QVector<Personel> GorevliList() const;
    QString Durum() const;
    QString cevapOid() const;
};






#endif // DILEKCE_H
