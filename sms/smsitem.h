#ifndef SMSITEM_H
#define SMSITEM_H

#include "Config.h"
#include "item.h"
#include <QByteArray>
#include <QXmlStreamWriter>
#include <iostream>


namespace SerikBLDCore {


namespace SMS {


static const std::string Collection{"SMSCollection"};
static const std::string sms{"sms"};
static const std::string numara{"telefon"};
static const std::string smsID{"smsid"};
static const std::string mSecStartDay{"mSecStartDay"};
static const std::string julianday{"julianDay"};

///
/// \brief The SMSItem class : Gönderilecek SMS Item.
///
class SERIKBLDCORE_EXPORT SMSItem : public SerikBLDCore::Item
{
public:
    explicit SMSItem( SMSItem* other = nullptr );

    ///
    /// \brief SMSItem: Copy Constructor
    /// \param other
    ///
    SMSItem( const SMSItem& other );

    ///
    /// \brief SMSItem: Move Constructor
    /// \param other
    ///
    SMSItem( SMSItem&& other );

    ///
    /// \brief operator: Copy Assigment
    /// \param other
    /// \return
    ///
    SMSItem& operator=( const SMSItem& other );

    ///
    /// \brief operator: Move Assignment
    /// \param other
    /// \return
    ///
    SMSItem& operator=( SMSItem&& other );

    ///
    /// \brief setSMS: SMS SetEder
    /// \param smsText
    /// \return
    ///
    SMSItem& setSMS( const QString &smsText );

    ///
    /// \brief smsText : SMS Geri Döndürür
    /// \return
    ///
    QString smsText() const;

    ///
    /// \brief setNumara: Numarayı Set Eder
    /// \param numaraText
    /// \return
    ///
    SMSItem& setNumara( const QString& numaraText );

    ///
    /// \brief numaraText: Numarayı Geri Döndürür
    /// \return
    ///
    QString numaraText() const;

    ///
    /// \brief setID: Gönderilen SMS ID'sini Set Eder
    /// \param smsIDText
    /// \return
    ///
    SMSItem& setID( const QString& smsIDText );

    ///
    /// \brief idText: Gönderilen SMS IDsini Geri Döndürür
    /// \return
    ///
    QString idText() const;

    ///
    /// \brief setmSecStartOfDay: Günün Başlangıcından itibaren olan Saniyeyi Set Eder.
    /// \param mSecStartOfDay
    /// \return
    ///
    SMSItem& setmSecStartOfDay( const int& mSecStartOfDay );

    ///
    /// \brief secStartOfDay: Saniyeyi Geri Döndürür.
    /// \return
    ///
    int secStartOfDay() const;

    ///
    /// \brief setJulianDay: Tarihi JulianDay Olarak Set Eder.
    /// \param julianday
    /// \return
    ///
    SMSItem& setJulianDay( const int& julianday );

    ///
    /// \brief julianDay Tarih JulianDay Olarak Geri Döndürür
    /// \return
    ///
    int julianDay() const;



    friend std::ostream& operator << (std::ostream& streamer, SMSItem& item){
        streamer << "SMS: "<<item.smsText ().toStdString () << " NUMARA: " << item.numaraText ().toStdString () << " ID: " << item.idText ().toStdString () << " JulianDay: " << item.julianDay () << std::endl;
        return streamer;
    }
    friend std::ostream& operator << (std::ostream& streamer, const SMSItem& item){
        streamer << "SMS: "<<item.smsText ().toStdString () << " NUMARA: " << item.numaraText ().toStdString () << " ID: " << item.idText ().toStdString () << " JulianDay: " << item.julianDay () << std::endl;
        return streamer;
    }
};


//std::ostream &SerikBLDCore::SMS::operator <<(std::ostream &streamer, const SerikBLDCore::SMS::SMSItem &item)
//{

//}

//std::ostream &SerikBLDCore::SMS::operator <<(std::ostream &streamer, SerikBLDCore::SMS::SMSItem &item)
//{

//}




}


}



#endif // SMSITEM_H
