#ifndef SMSITEM_H
#define SMSITEM_H

#include "Config.h"
#include "item.h"
#include <QByteArray>
#include <QXmlStreamWriter>


namespace SerikBLDCore {


namespace SMS {


static const std::string Collection{"SMSCollection"};
static const std::string sms{"sms"};
static const std::string numara{"telefon"};
static const std::string smsID{"smsid"};

///
/// \brief The SMSItem class : Gönderilecek SMS Item.
///
class SMSItem : public SerikBLDCore::Item
{
public:
    SMSItem( SMSItem* other = nullptr );
    SMSItem( const SMSItem& other );
    SMSItem( SMSItem&& other );

    SMSItem& operator=( const SMSItem& other );
    SMSItem& operator=( SMSItem&& other );

    SMSItem& setSMS( const QString &smsText );
    QString smsText() const;

    SMSItem& setNumara( const QString& numaraText );
    QString numaraText() const;

    SMSItem& setID( const QString& smsIDText );
    QString idText() const;
};
}


}



#endif // SMSITEM_H
