#ifndef CORE_H
#define CORE_H

#include <QMap>
#include "element.h"



namespace SerikBLDCore {

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

    friend std::ostream& operator<<( std::ostream& stream, const SerikBLDCore::bsoncxx::core& object );


    QMap<QString,SerikBLDCore::bsoncxx::element>& map();

    QMap<QString,SerikBLDCore::bsoncxx::element>& view() const;

    int count() const;


    bool isArray() const;

    void clear();

private:
    bool mIsArray = false;
    QMap<QString,SerikBLDCore::bsoncxx::element> mMap;
};


}


}

Q_DECLARE_METATYPE(SerikBLDCore::bsoncxx::core);

#endif // CORE_H
