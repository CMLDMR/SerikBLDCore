#include "object.h"



MongoCore::bsoncxx::object::object()
    :core(false)
{

}

MongoCore::bsoncxx::object &MongoCore::bsoncxx::object::append(const QString &key, const MongoCore::bsoncxx::element &value)
{
    this->map ().insert (key,value);
    return *this;
}

MongoCore::bsoncxx::object &MongoCore::bsoncxx::object::append(const QString &key, const MongoCore::bsoncxx::object &value)
{
    if( value.count () ){
        this->map ().insert (key,MongoCore::bsoncxx::element(value));
    }
    return *this;
}

MongoCore::bsoncxx::object &MongoCore::bsoncxx::object::append(const QString &key, const MongoCore::bsoncxx::array &value)
{
    if( value.count () ){
        this->map ().insert (key,MongoCore::bsoncxx::element(value));
    }
    return *this;
}

std::optional<MongoCore::bsoncxx::element> MongoCore::bsoncxx::object::element(const QString &key)
{
    if( this->map ().contains (key) ){
        return this->map ()[key];
    }else{
        return std::nullopt;
    }
}

MongoCore::bsoncxx::object& MongoCore::bsoncxx::object::setObject(const MongoCore::bsoncxx::object &object)
{
    this->clear ();

    for( auto key : object.view ().keys () ){
        this->map ().insert (key,object.view ().value (key));
    }
    return *this;
}

MongoCore::bsoncxx::object &MongoCore::bsoncxx::object::setObject(const QMap<QString, MongoCore::bsoncxx::element> &elementList)
{
    this->clear ();

    for( auto key : elementList.keys () ){
        this->map ().insert (key,elementList.value (key));
    }
    return *this;
}


MongoCore::bsoncxx::array::array()
    :core(true)
{

}

MongoCore::bsoncxx::array &MongoCore::bsoncxx::array::append(const MongoCore::bsoncxx::element &value)
{
    this->map ().insert (QString::number (this->map ().count ()),MongoCore::bsoncxx::element(value));
    return *this;
}

MongoCore::bsoncxx::array &MongoCore::bsoncxx::array::append(const MongoCore::bsoncxx::object &value)
{
    if( value.count () ){
        this->map ().insert (QString::number (this->map ().count ()),MongoCore::bsoncxx::element(value));
    }
    return *this;
}

MongoCore::bsoncxx::array &MongoCore::bsoncxx::array::append(const MongoCore::bsoncxx::array &value)
{
    if( value.count () ){
        this->map ().insert (QString::number (this->map ().count ()),MongoCore::bsoncxx::element(value));
    }
    return *this;
}
