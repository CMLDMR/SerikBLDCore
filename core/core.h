#ifndef CORE_H
#define CORE_H

#include <QMap>
#include "element.h"



namespace MongoCore {

namespace bsoncxx {

class core
{
public:
    explicit core( const bool& isArray = false );
    core( const core& other );
    core( core&& other );


    core& operator=( const core& other );
    core& operator=( core&& other );

    bool operator==( const core& other );
    bool operator!=( const core& other );

    friend std::ostream& operator<<( std::ostream& stream, const MongoCore::bsoncxx::core& object );


    QMap<QString,MongoCore::bsoncxx::element>& map();

    QMap<QString,MongoCore::bsoncxx::element> view() const;

    int count() const;


    bool isArray() const;

    void clear();

private:
    bool mIsArray = false;
    QMap<QString,MongoCore::bsoncxx::element> mMap;
};


}


}

Q_DECLARE_METATYPE(MongoCore::bsoncxx::core);

#endif // CORE_H
