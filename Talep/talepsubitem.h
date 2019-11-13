#ifndef TALEPSUBITEM_H
#define TALEPSUBITEM_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"
#include "talep.h"

class SERIKBLDCORE_EXPORT TalepSubItem : public Item
{
public:

    enum class ItemType{
        none = 0,
        Aciklama,
        Fotograf,
        Pdf,
        Konum,
        Video,
        Sms
    };

    TalepSubItem();
    TalepSubItem( const TalepSubItem& other );
    TalepSubItem( TalepSubItem&& other );

    TalepSubItem& operator=( const TalepSubItem& other );
    TalepSubItem& operator=( TalepSubItem&& other );

    void setType(TalepSubItem::ItemType type);
    ItemType type() const;

    void setTalepOid( const QString& talepOid );
    QString talepOid() const;

    void setAciklama( const QString& aciklama );
    QString aciklama() const;

    void setFotograf( const QString& fotoOid );
    QString fotografOid() const;

    void setPdf( const QString& pdfOid );
    QString pdfOid() const;

    void setKonum( double x , double y );
    double xCoordinate() const;
    double yCoordinate() const;

    void setVideoOid( const QString& videoOid );
    QString videoOid() const;

    void setSms( const QString& sms );
    QString sms() const;

    void setPersonelName( const QString& personelName );
    QString personelName() const;

    void setPersonelOid( const QString& personelOid );
    QString personelOid() const;

    QString tarih() const;
    int julianDay() const;
    QString saat() const;

    QString typeColor() const;
    QString typeStr() const;


    QJsonObject toJson() const;

public:
    static const std::string Collection;
    static const std::string Type;
    static const std::string TalepOid;
    static const std::string Aciklama;
    static const std::string Fotograf;
    static const std::string Pdf;
    static const std::string Konum;
    static const std::string Video;
    static const std::string Sms;
    static const std::string PersonelName;
    static const std::string PersonelOid;
};

#endif // TALEPITEM_H
