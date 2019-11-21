#include "smsabstrackmanager.h"
#include <QDate>
#include <QTime>


QString SerikBLDCore::SMSAbstractManager::lastSendedSMSID() const
{
    if( !mManagerValid ){
        std::cout << __LINE__ << " " << __FUNCTION__ << " SMS Manager Veritabanı Yok" << std::endl;
        return "";
    }
    return mLastSendedSMSID;
}

void SerikBLDCore::SMSAbstractManager::setLastSendedSMSID(const QString &lastSendedSMSID)
{
    if( !mManagerValid ){
        std::cout << __LINE__ << " " << __FUNCTION__ << " SMS Manager Veritabanı Yok" << std::endl;
        return;
    }
    mLastSendedSMSID = lastSendedSMSID;
}

SerikBLDCore::SMSAbstractManager::SMSAbstractManager(DB *_db) : DB(_db)
{
    if( _db == nullptr )
    {
        mManagerValid = false;
    }else{
        mManagerValid = true;
    }

}

SerikBLDCore::SMSAbstractManager::SMSAbstractManager(const SerikBLDCore::DB *_db) : DB(_db)
{
    if( _db == nullptr )
    {
        mManagerValid = false;
    }else{
        mManagerValid = true;
    }
}





bool SerikBLDCore::SMSAbstractManager::isManagerValid() const
{
    return mManagerValid;
}

bool SerikBLDCore::SMSAbstractManager::canSend(const QString &numara, int &kalanSure)
{
    if( !mManagerValid ){
        std::cout << __LINE__ << " " << __FUNCTION__ << " SMS Manager Veritabanı Yok" << std::endl;
        return false;
    }

    SMS::SMSItem filter;

    filter.setJulianDay (QDate::currentDate ().toJulianDay ());

    SMS::SMSItem findOptions;
    findOptions.append("_id",-1);

    auto val = this->findOneItem (filter,findOptions);
    kalanSure = -1;
    if( val )
    {
        filter.setDocumentView (val.value ().view ());

        kalanSure = QTime::currentTime ().msecsSinceStartOfDay () - filter.secStartOfDay ();

        if( kalanSure > 60000  )
        {
            return true;
        }
    }

    return false;
}

QVector<SerikBLDCore::SMS::SMSItem> SerikBLDCore::SMSAbstractManager::listSMS(const QString &numara)
{
    QVector<SMS::SMSItem> list;

    if( !mManagerValid ){
        std::cout << __LINE__ << " " << __FUNCTION__ << " SMS Manager Veritabanı Yok" << std::endl;
        return list;
    }

    SMS::SMSItem filter;
    filter.setNumara (numara);


    auto cursor = this->find (filter);

    if( cursor )
    {
        for( auto item : cursor.value () )
        {
            SMS::SMSItem smsItem;
            smsItem.setDocumentView (item);
            list.push_back (std::move(smsItem));
        }
    }
    return list;
}

bool SerikBLDCore::SMSAbstractManager::updateSMS(const SerikBLDCore::SMS::SMSItem &item)
{
    if( !mManagerValid ){
        std::cout << __LINE__ << " " << __FUNCTION__ << " SMS Manager Veritabanı Yok" << std::endl;
        return false;
    }
    auto ins = this->updateItem (item);
    if( ins )
    {
        if( ins.value ().modified_count () )
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
