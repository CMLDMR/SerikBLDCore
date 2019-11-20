#include "smsabstrackmanager.h"
#include <QDate>
#include <QTime>


QString SerikBLDCore::SMSAbstractManager::lastSendedSMSID() const
{
    return mLastSendedSMSID;
}

void SerikBLDCore::SMSAbstractManager::setLastSendedSMSID(const QString &lastSendedSMSID)
{
    mLastSendedSMSID = lastSendedSMSID;
}

SerikBLDCore::SMSAbstractManager::SMSAbstractManager(DB *_db) : DB(_db)
{

}

bool SerikBLDCore::SMSAbstractManager::canSend(const QString &numara)
{
    SMS::SMSItem filter;

    filter.setJulianDay (QDate::currentDate ().toJulianDay ());

    auto val = this->findOneItem (filter);

    if( val )
    {
        filter.setDocumentView (val.value ().view ());

        if( filter.secStartOfDay () + 300 * 1000 > QTime::currentTime ().msecsSinceStartOfDay ()  )
        {
            return true;
        }
    }

    return false;
}

QVector<SerikBLDCore::SMS::SMSItem> SerikBLDCore::SMSAbstractManager::listSMS(const QString &numara)
{
    SMS::SMSItem filter;
    filter.setNumara (numara);

    QVector<SMS::SMSItem> list;

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
