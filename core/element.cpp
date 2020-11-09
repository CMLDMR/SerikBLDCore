#include "element.h"
#include "object.h"



MongoCore::bsoncxx::Oid::Oid(const QString &_oidStr)
{
    this->_oid = _oidStr;
}

MongoCore::bsoncxx::Oid::Oid(const MongoCore::bsoncxx::Oid &_oid)
{
    this->_oid = _oid._oid;
}

MongoCore::bsoncxx::Oid::Oid(MongoCore::bsoncxx::Oid &&_oid)
{
    this->_oid = _oid._oid;
}

QString MongoCore::bsoncxx::Oid::value() const
{
    return this->_oid;
}

QDataStream& MongoCore::bsoncxx::Oid::operator<<( QDataStream &stream)
{
    stream << this->value ();
    return stream;
}

MongoCore::bsoncxx::element::element()
    :mType{Type::k_unknown}
{

}

MongoCore::bsoncxx::element::element(const MongoCore::bsoncxx::Oid &value)
    :mValue {value.value ()},
      mType{Type::k_oid}
{}

MongoCore::bsoncxx::element::element(const QString &value)
    :mValue {value},
      mType{Type::k_utf8}
{}

MongoCore::bsoncxx::element::element(const std::string &value)
    :mValue {value.c_str ()},
      mType{Type::k_utf8}
{

}

MongoCore::bsoncxx::element::element(const char *value)
    :mValue {value},
      mType{Type::k_utf8}
{

}

MongoCore::bsoncxx::element::element(const bool &value)
    :mValue {value},
      mType{Type::k_bool}
{}

MongoCore::bsoncxx::element::element(const double &value)
    :mValue {value},
      mType{Type::k_double}
{}

MongoCore::bsoncxx::element::element(const qint64 &value)
    :mValue {value},
      mType{Type::k_int64}
{
}

MongoCore::bsoncxx::element::element(const qint32 &value)
    :mValue {value},
      mType{Type::k_int32}
{}

MongoCore::bsoncxx::element::element(const MongoCore::bsoncxx::object &value)
    :mType{Type::k_object}
{
    mValue.setValue(value);
}

MongoCore::bsoncxx::element::element(const MongoCore::bsoncxx::array &value)
    :mType{Type::k_array}
{
    mValue.setValue(value);
}

MongoCore::bsoncxx::element::element(const MongoCore::bsoncxx::element &other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
}

MongoCore::bsoncxx::element::element(MongoCore::bsoncxx::element &&other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
}

MongoCore::bsoncxx::element& MongoCore::bsoncxx::element::operator=(const MongoCore::bsoncxx::element &other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
    return *this;
}

MongoCore::bsoncxx::element& MongoCore::bsoncxx::element::operator=(MongoCore::bsoncxx::element &&other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
    return *this;
}

bool MongoCore::bsoncxx::element::operator==(const MongoCore::bsoncxx::element &other)
{
    if( this->type () != other.type () ){
        return false;
    }
    switch (other.type ()) {
    case Type::k_oid:
        return this->toOid ().value ().value () == other.toOid ().value ().value ();
        break;
    case Type::k_utf8:
        return this->toString ().value () == other.toString ().value ();
        break;
    case Type::k_bool:
        return this->toBool ().value () == other.toBool ().value ();
        break;
    case Type::k_double:
        return this->toDouble ().value () == other.toDouble ().value ();
        break;
    case Type::k_int64:
        return this->toInt32 ().value () == other.toInt32 ().value ();
        break;
    case Type::k_int32:
        return this->toInt64 ().value () == other.toInt64 ().value ();
        break;
    case Type::k_object:
        return this->toObject ().value () == other.toObject ().value ();
        break;
    case Type::k_array:
        return this->toObject ().value () == other.toObject ().value ();
        break;
    default:
        break;
    }
}

bool MongoCore::bsoncxx::element::operator!=(const MongoCore::bsoncxx::element &other)
{
    if( this->type () != other.type () ){
        return true;
    }
    switch (other.type ()) {
    case Type::k_oid:
        return this->toOid ().value ().value () != other.toOid ().value ().value ();
        break;
    case Type::k_utf8:
        return this->toString ().value () != other.toString ().value ();
        break;
    case Type::k_bool:
        return this->toBool ().value () != other.toBool ().value ();
        break;
    case Type::k_double:
        return this->toDouble ().value () != other.toDouble ().value ();
        break;
    case Type::k_int64:
        return this->toInt32 ().value () != other.toInt32 ().value ();
        break;
    case Type::k_int32:
        return this->toInt64 ().value () != other.toInt64 ().value ();
        break;
    case Type::k_object:
        return this->toObject ().value () != other.toObject ().value ();
        break;
    default:
        return false;
        break;
    }
}

bool MongoCore::bsoncxx::operator==(const MongoCore::bsoncxx::element &element1, const MongoCore::bsoncxx::element &element2)
{
    if( element1.type () != element2.type () ){
        return false;
    }
    switch (element2.type ()) {
    case Type::k_oid:
        return element1.toOid ().value ().value () == element2.toOid ().value ().value ();
        break;
    case Type::k_utf8:
        return element1.toString ().value () == element2.toString ().value ();
        break;
    case Type::k_bool:
        return element1.toBool ().value () == element2.toBool ().value ();
        break;
    case Type::k_double:
        return element1.toDouble ().value () == element2.toDouble ().value ();
        break;
    case Type::k_int64:
        return element1.toInt32 ().value () == element2.toInt32 ().value ();
        break;
    case Type::k_int32:
        return element1.toInt64 ().value () == element2.toInt64 ().value ();
        break;
    case Type::k_object:
        return element1.toObject ().value () == element2.toObject ().value ();
        break;
    default:
        return false;
        break;
    }
}

std::optional<MongoCore::bsoncxx::Oid> MongoCore::bsoncxx::element::toOid() const
{
    if( this->type () == Type::k_oid ){
        return Oid(this->mValue.toString ());
    }
    return std::nullopt;
}

std::optional<QString> MongoCore::bsoncxx::element::toString() const
{
    if( this->type () == Type::k_utf8 ){
        return this->mValue.toString ();
    }
    return std::nullopt;
}

std::optional<bool> MongoCore::bsoncxx::element::toBool() const
{
    if( this->type () == Type::k_bool ){
        return this->mValue.toBool ();
    }
    return std::nullopt;
}

std::optional<double> MongoCore::bsoncxx::element::toDouble() const
{
    if( this->type () == Type::k_double ){
        return this->mValue.toDouble ();
    }
    return std::nullopt;
}

std::optional<qint64> MongoCore::bsoncxx::element::toInt64() const
{
    if( this->type () == Type::k_int64 ){
        return static_cast<qint64>(this->mValue.toInt ());
    }
    return std::nullopt;
}

std::optional<qint32> MongoCore::bsoncxx::element::toInt32() const
{
    if( this->type () == Type::k_int32 ){
        return static_cast<qint32>(this->mValue.toInt ());
    }
    return std::nullopt;
}

std::optional<MongoCore::bsoncxx::object> MongoCore::bsoncxx::element::toObject() const
{
    if( this->type () == Type::k_object ){
        auto val = qvariant_cast<MongoCore::bsoncxx::object>(this->mValue);
        return std::make_optional<MongoCore::bsoncxx::object>(val);
    }
    return std::nullopt;
}

std::optional<MongoCore::bsoncxx::array> MongoCore::bsoncxx::element::toArray() const
{
    if( this->type () == Type::k_array ){
        auto val = qvariant_cast<MongoCore::bsoncxx::array>(this->mValue);
        return std::make_optional<MongoCore::bsoncxx::array>(val);
    }
    return std::nullopt;
}

MongoCore::bsoncxx::Type MongoCore::bsoncxx::element::type() const
{
    return mType;
}

bool MongoCore::bsoncxx::operator!=(const MongoCore::bsoncxx::element &element1, const MongoCore::bsoncxx::element &element2)
{
    if( element1.type () != element2.type () ){
        return true;
    }
    switch (element2.type ()) {
    case Type::k_oid:
        return element1.toOid ().value ().value () != element2.toOid ().value ().value ();
        break;
    case Type::k_utf8:
        return element1.toString ().value () != element2.toString ().value ();
        break;
    case Type::k_bool:
        return element1.toBool ().value () != element2.toBool ().value ();
        break;
    case Type::k_double:
        return element1.toDouble ().value () != element2.toDouble ().value ();
        break;
    case Type::k_int64:
        return element1.toInt32 ().value () != element2.toInt32 ().value ();
        break;
    case Type::k_int32:
        return element1.toInt64 ().value () != element2.toInt64 ().value ();
        break;
    case Type::k_object:
        return element1.toObject ().value () != element2.toObject ().value ();
        break;
    default:
        break;
    }
}

QVariant MongoCore::bsoncxx::element::value() const
{
    return mValue;
}






std::ostream& MongoCore::bsoncxx::operator<<(std::ostream& stream, const MongoCore::bsoncxx::element &element)
{
    switch (element.type ()) {
    case Type::k_oid:
        stream << "\"" + element.toOid ().value ().value ().toStdString ()+ "\"";
        break;
    case Type::k_utf8:
        stream << ( "\"" + element.toString ().value ().toStdString () + "\"");
        break;
    case Type::k_bool:
        stream << (element.toBool ().value () ? " true" : " false");
        break;
    case Type::k_double:
        stream << ( QString::number (element.toDouble ().value ()).toStdString ());
        break;
    case Type::k_int64:
        stream << ( QString::number (element.toInt64 ().value ()).toStdString ());
        break;
    case Type::k_int32:
        stream << ( QString::number (element.toInt32 ().value ()).toStdString ());
        break;
    case Type::k_object:
        stream << element.toObject ().value ();
        break;
    case Type::k_array:
        stream << element.toArray ().value ();
        break;
    default:
        break;
    }
    return stream;
}
