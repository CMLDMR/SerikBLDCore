#ifndef OBJECT_H
#define OBJECT_H

#include <QMap>
#include "core.h"


namespace SerikBLDCore {

namespace bsoncxx {

class array;

class object : public core
{
public:
    explicit object();
    SerikBLDCore::bsoncxx::object& append(const QString& key , const SerikBLDCore::bsoncxx::element& value );
    SerikBLDCore::bsoncxx::object& append(const QString& key , const SerikBLDCore::bsoncxx::object& value );
    SerikBLDCore::bsoncxx::object& append(const QString& key , const SerikBLDCore::bsoncxx::array& value );

    std::optional<element> element( const QString& key );

};


class array : public core
{
public:
    explicit array();
    SerikBLDCore::bsoncxx::array& append(const SerikBLDCore::bsoncxx::element& value );
    SerikBLDCore::bsoncxx::array& append(const SerikBLDCore::bsoncxx::object& value );
    SerikBLDCore::bsoncxx::array& append(const SerikBLDCore::bsoncxx::array& value );
};

}


}

Q_DECLARE_METATYPE(SerikBLDCore::bsoncxx::object);
Q_DECLARE_METATYPE(SerikBLDCore::bsoncxx::array);




#endif // OBJECT_H
