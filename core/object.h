#ifndef OBJECT_H
#define OBJECT_H

#include <QMap>
#include "core.h"


namespace MongoCore {

namespace bsoncxx {

class array;

class object : public core
{
public:
    explicit object();
    MongoCore::bsoncxx::object& append(const QString& key , const MongoCore::bsoncxx::element& value );
    MongoCore::bsoncxx::object& append(const QString& key , const MongoCore::bsoncxx::object& value );
    MongoCore::bsoncxx::object& append(const QString& key , const MongoCore::bsoncxx::array& value );

    std::optional<element> element( const QString& key );

    MongoCore::bsoncxx::object& setObject( const MongoCore::bsoncxx::object& object );
    MongoCore::bsoncxx::object& setObject( const QMap<QString,MongoCore::bsoncxx::element>& elementList );

};


class array : public core
{
public:
    explicit array();
    MongoCore::bsoncxx::array& append(const MongoCore::bsoncxx::element& value );
    MongoCore::bsoncxx::array& append(const MongoCore::bsoncxx::object& value );
    MongoCore::bsoncxx::array& append(const MongoCore::bsoncxx::array& value );
};

}


}

Q_DECLARE_METATYPE(MongoCore::bsoncxx::object);
Q_DECLARE_METATYPE(MongoCore::bsoncxx::array);




#endif // OBJECT_H
