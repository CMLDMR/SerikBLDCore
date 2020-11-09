#include "element.h"
#include "object.h"



SerikBLDCore::bsoncxx::Oid::Oid(const QString &_oidStr)
{
    this->_oid = _oidStr;
}

SerikBLDCore::bsoncxx::Oid::Oid(const SerikBLDCore::bsoncxx::Oid &_oid)
{
    this->_oid = _oid._oid;
}

SerikBLDCore::bsoncxx::Oid::Oid(SerikBLDCore::bsoncxx::Oid &&_oid)
{
    this->_oid = _oid._oid;
}

QString SerikBLDCore::bsoncxx::Oid::value() const
{
    return this->_oid;
}

QDataStream& SerikBLDCore::bsoncxx::Oid::operator<<( QDataStream &stream)
{
    stream << this->value ();
    return stream;
}

SerikBLDCore::bsoncxx::element::element()
    :mType{Type::k_unknown}
{

}

SerikBLDCore::bsoncxx::element::element(const SerikBLDCore::bsoncxx::Oid &value)
    :mValue {value.value ()},
      mType{Type::k_oid}
{}

SerikBLDCore::bsoncxx::element::element(const QString &value)
    :mValue {value},
      mType{Type::k_utf8}
{}

SerikBLDCore::bsoncxx::element::element(const std::string &value)
    :mValue {value.c_str ()},
      mType{Type::k_utf8}
{

}

SerikBLDCore::bsoncxx::element::element(const char *value)
    :mValue {value},
      mType{Type::k_utf8}
{

}

SerikBLDCore::bsoncxx::element::element(const bool &value)
    :mValue {value},
      mType{Type::k_bool}
{}

SerikBLDCore::bsoncxx::element::element(const double &value)
    :mValue {value},
      mType{Type::k_double}
{}

SerikBLDCore::bsoncxx::element::element(const qint64 &value)
    :mValue {value},
      mType{Type::k_int64}
{
}

SerikBLDCore::bsoncxx::element::element(const qint32 &value)
    :mValue {value},
      mType{Type::k_int32}
{}

SerikBLDCore::bsoncxx::element::element(const SerikBLDCore::bsoncxx::object &value)
    :mType{Type::k_object}
{
    mValue.setValue(value);
}

SerikBLDCore::bsoncxx::element::element(const SerikBLDCore::bsoncxx::array &value)
    :mType{Type::k_array}
{
    mValue.setValue(value);
}

SerikBLDCore::bsoncxx::element::element(const SerikBLDCore::bsoncxx::element &other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
}

SerikBLDCore::bsoncxx::element::element(SerikBLDCore::bsoncxx::element &&other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
}

SerikBLDCore::bsoncxx::element& SerikBLDCore::bsoncxx::element::operator=(const SerikBLDCore::bsoncxx::element &other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
    return *this;
}

SerikBLDCore::bsoncxx::element& SerikBLDCore::bsoncxx::element::operator=(SerikBLDCore::bsoncxx::element &&other)
{
    this->mType = other.type ();
    this->mValue = other.value ();
    return *this;
}

bool SerikBLDCore::bsoncxx::element::operator==(const SerikBLDCore::bsoncxx::element &other)
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

bool SerikBLDCore::bsoncxx::element::operator!=(const SerikBLDCore::bsoncxx::element &other)
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

bool SerikBLDCore::bsoncxx::operator==(const SerikBLDCore::bsoncxx::element &element1, const SerikBLDCore::bsoncxx::element &element2)
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

std::optional<SerikBLDCore::bsoncxx::Oid> SerikBLDCore::bsoncxx::element::toOid() const
{
    if( this->type () == Type::k_oid ){
        return Oid(this->mValue.toString ());
    }
    return std::nullopt;
}

std::optional<QString> SerikBLDCore::bsoncxx::element::toString() const
{
    if( this->type () == Type::k_utf8 ){
        return this->mValue.toString ();
    }
    return std::nullopt;
}

std::optional<bool> SerikBLDCore::bsoncxx::element::toBool() const
{
    if( this->type () == Type::k_bool ){
        return this->mValue.toBool ();
    }
    return std::nullopt;
}

std::optional<double> SerikBLDCore::bsoncxx::element::toDouble() const
{
    if( this->type () == Type::k_double ){
        return this->mValue.toDouble ();
    }
    return std::nullopt;
}

std::optional<qint64> SerikBLDCore::bsoncxx::element::toInt64() const
{
    if( this->type () == Type::k_int64 ){
        return static_cast<qint64>(this->mValue.toInt ());
    }
    return std::nullopt;
}

std::optional<qint32> SerikBLDCore::bsoncxx::element::toInt32() const
{
    if( this->type () == Type::k_int32 ){
        return static_cast<qint32>(this->mValue.toInt ());
    }
    return std::nullopt;
}

std::optional<SerikBLDCore::bsoncxx::object> SerikBLDCore::bsoncxx::element::toObject() const
{
    if( this->type () == Type::k_object ){
        auto val = qvariant_cast<SerikBLDCore::bsoncxx::object>(this->mValue);
        return std::make_optional<SerikBLDCore::bsoncxx::object>(val);
    }
    return std::nullopt;
}

std::optional<SerikBLDCore::bsoncxx::array> SerikBLDCore::bsoncxx::element::toArray() const
{
    if( this->type () == Type::k_array ){
        auto val = qvariant_cast<SerikBLDCore::bsoncxx::array>(this->mValue);
        return std::make_optional<SerikBLDCore::bsoncxx::array>(val);
    }
    return std::nullopt;
}

SerikBLDCore::bsoncxx::Type SerikBLDCore::bsoncxx::element::type() const
{
    return mType;
}

bool SerikBLDCore::bsoncxx::operator!=(const SerikBLDCore::bsoncxx::element &element1, const SerikBLDCore::bsoncxx::element &element2)
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

QVariant SerikBLDCore::bsoncxx::element::value() const
{
    return mValue;
}






std::ostream& SerikBLDCore::bsoncxx::operator<<(std::ostream& stream, const SerikBLDCore::bsoncxx::element &element)
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
