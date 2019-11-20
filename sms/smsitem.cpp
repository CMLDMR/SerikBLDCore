#include "smsitem.h"

SerikBLDCore::SMS::SMSItem::SMSItem(SMSItem *other) : Item(Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

SerikBLDCore::SMS::SMSItem::SMSItem(const SerikBLDCore::SMS::SMSItem &other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::SMS::SMSItem::SMSItem(SerikBLDCore::SMS::SMSItem &&other) : Item(Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::SMS::SMSItem &SerikBLDCore::SMS::SMSItem::operator=(const SerikBLDCore::SMS::SMSItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::SMS::SMSItem &SerikBLDCore::SMS::SMSItem::operator=(SerikBLDCore::SMS::SMSItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::SMS::SMSItem &SerikBLDCore::SMS::SMSItem::setSMS(const QString &smsText)
{
    this->append(sms,smsText.toStdString ());
    return *this;
}

QString SerikBLDCore::SMS::SMSItem::smsText() const
{
    auto val = this->element (sms);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

SerikBLDCore::SMS::SMSItem &SerikBLDCore::SMS::SMSItem::setNumara(const QString &numaraText)
{
    this->append(numara,numaraText.toStdString ());
    return *this;
}

QString SerikBLDCore::SMS::SMSItem::numaraText() const
{
    auto val = this->element (sms);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}

SerikBLDCore::SMS::SMSItem &SerikBLDCore::SMS::SMSItem::setID(const QString &smsIDText)
{
    this->append(smsID,smsIDText.toStdString ());
    return *this;
}

QString SerikBLDCore::SMS::SMSItem::idText() const
{
    auto val = this->element (smsID);
    if( val )
    {
        return QString::fromStdString (val.value ().get_utf8 ().value.to_string());
    }
    return "";
}
