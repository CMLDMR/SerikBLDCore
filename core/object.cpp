#include "object.h"



SerikBLDCore::bsoncxx::object::object()
    :core(false)
{

}

SerikBLDCore::bsoncxx::object &SerikBLDCore::bsoncxx::object::append(const QString &key, const SerikBLDCore::bsoncxx::element &value)
{
    this->map ().insert (key,value);
    return *this;
}

SerikBLDCore::bsoncxx::object &SerikBLDCore::bsoncxx::object::append(const QString &key, const SerikBLDCore::bsoncxx::object &value)
{
    if( value.count () ){
        this->map ().insert (key,SerikBLDCore::bsoncxx::element(value));
    }
    return *this;
}

SerikBLDCore::bsoncxx::object &SerikBLDCore::bsoncxx::object::append(const QString &key, const SerikBLDCore::bsoncxx::array &value)
{
    if( value.count () ){
        this->map ().insert (key,SerikBLDCore::bsoncxx::element(value));
    }
    return *this;
}

std::optional<SerikBLDCore::bsoncxx::element> SerikBLDCore::bsoncxx::object::element(const QString &key)
{
    if( this->map ().contains (key) ){
        return this->map ()[key];
    }else{
        return std::nullopt;
    }
}


SerikBLDCore::bsoncxx::array::array()
    :core(true)
{

}

SerikBLDCore::bsoncxx::array &SerikBLDCore::bsoncxx::array::append(const SerikBLDCore::bsoncxx::element &value)
{
    this->map ().insert (QString::number (this->map ().count ()),SerikBLDCore::bsoncxx::element(value));
    return *this;
}

SerikBLDCore::bsoncxx::array &SerikBLDCore::bsoncxx::array::append(const SerikBLDCore::bsoncxx::object &value)
{
    if( value.count () ){
        this->map ().insert (QString::number (this->map ().count ()),SerikBLDCore::bsoncxx::element(value));
    }
    return *this;
}

SerikBLDCore::bsoncxx::array &SerikBLDCore::bsoncxx::array::append(const SerikBLDCore::bsoncxx::array &value)
{
    if( value.count () ){
        this->map ().insert (QString::number (this->map ().count ()),SerikBLDCore::bsoncxx::element(value));
    }
    return *this;
}
