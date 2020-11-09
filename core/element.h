#ifndef ELEMENT_H
#define ELEMENT_H

#include <QVariant>
#include <QString>
#include <QDataStream>
#include <QByteArray>
#include <iostream>
#include <optional>
#include <QDebug>



namespace SerikBLDCore {

namespace bsoncxx {


class object;
class array;



enum class Type{
    k_oid = 0,
    k_utf8,
    k_bool,
    k_double,
    k_int64,
    k_int32,
    k_object,
    k_array,
    k_unknown
};


class Oid{
public:
    Oid( const QString& _oidStr );
    Oid( const Oid& _oid );
    Oid( Oid&& _oid );
    QString value() const;
    QDataStream& operator<<( QDataStream& stream );
private:
    QString _oid;
};



class element
{
public:
    explicit element();
    explicit element( const Oid& value );
    explicit element( const QString& value );
    explicit element( const std::string& value );
    explicit element( const char* value );
    explicit element( const bool& value );
    explicit element( const double& value );
    explicit element( const qint64& value );
    explicit element( const qint32& value );
    explicit element( const object& value );
    explicit element( const array& value );


    element( const SerikBLDCore::bsoncxx::element& other );
    element( SerikBLDCore::bsoncxx::element&& other );

    element& operator=( const SerikBLDCore::bsoncxx::element& other );
    element& operator=( SerikBLDCore::bsoncxx::element&& other );

    bool operator==( const element& other );
    bool operator!=( const element& other );

    std::optional<Oid> toOid() const;
    std::optional<QString> toString() const;
    std::optional<bool> toBool() const;
    std::optional<double> toDouble() const;
    std::optional<qint64> toInt64() const;
    std::optional<qint32> toInt32() const;
    std::optional<SerikBLDCore::bsoncxx::object> toObject() const;
    std::optional<SerikBLDCore::bsoncxx::array> toArray() const;

    QVariant value() const;

    Type type() const;

    friend bool operator!=( const element& element1, const SerikBLDCore::bsoncxx::element& element2 );
    friend bool operator==( const element& element1, const SerikBLDCore::bsoncxx::element& element2 );
    friend std::ostream& operator<<( std::ostream& stream, const SerikBLDCore::bsoncxx::element& element );

private:
    QVariant mValue;
    Type mType;
};



}



}

Q_DECLARE_METATYPE(SerikBLDCore::bsoncxx::element);



#endif // ELEMENT_H
