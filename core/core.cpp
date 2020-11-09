#include "core.h"



MongoCore::bsoncxx::core::core(const bool &isArray)
    :mIsArray(isArray)
{

}

MongoCore::bsoncxx::core::core(const MongoCore::bsoncxx::core &other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
}

MongoCore::bsoncxx::core::core(MongoCore::bsoncxx::core &&other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
}

MongoCore::bsoncxx::core &MongoCore::bsoncxx::core::operator=(const MongoCore::bsoncxx::core &other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
    return *this;
}

MongoCore::bsoncxx::core &MongoCore::bsoncxx::core::operator=(MongoCore::bsoncxx::core &&other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
    return *this;
}

bool MongoCore::bsoncxx::core::operator==(const MongoCore::bsoncxx::core &other)
{
    if( mIsArray != other.mIsArray ){
        return false;
    }
    bool returnValue = true;
    for( auto key1 : this->mMap.keys () ){
        for( auto key2 : other.mMap.keys () ){
            if( key1 != key2 && returnValue ){
                returnValue = false;
                break;
            }else{
                if( this->mMap[key1] != other.mMap[key2]){
                    returnValue = false;
                    break;
                }
            }
        }
    }
    return returnValue;
}

bool MongoCore::bsoncxx::core::operator!=(const MongoCore::bsoncxx::core &other)
{
    if( *this == other ) return false;
    else return true;
}

QMap<QString, MongoCore::bsoncxx::element> &MongoCore::bsoncxx::core::map()
{
    return mMap;
}

QMap<QString, MongoCore::bsoncxx::element> MongoCore::bsoncxx::core::view() const
{
    return mMap;
}

int MongoCore::bsoncxx::core::count() const
{
    return this->mMap.count ();
}

bool MongoCore::bsoncxx::core::isArray() const
{
    return mIsArray;
}

void MongoCore::bsoncxx::core::clear()
{
    this->mMap.clear ();
}

std::ostream &MongoCore::bsoncxx::operator<<(std::ostream &stream, const MongoCore::bsoncxx::core &object)
{
    if( object.mIsArray ){

        if( object.mMap.keys ().count () == 0 ){
            return stream;
        }
        if( object.mMap.keys ().count () == 1 ){
            stream << "[ " << object.mMap.first () << " ]";
            return stream;
        }
        stream << " [";
        for( auto key : object.mMap.keys () ){
            stream <<object.mMap[key];
            if( key != object.mMap.lastKey () ){
                stream << " , ";
            }
        }
        stream << " ]";


    }else{

        if( object.mMap.keys ().count () == 0 ){
            return stream;
        }
        if( object.mMap.keys ().count () == 1 ){
            stream << "{ \"" << object.mMap.firstKey ().toStdString () << "\" : " << object.mMap.first () << " }";
            return stream;
        }
        stream << " {";
        for( auto key : object.mMap.keys () ){
            stream << "\"" << key.toStdString () << "\" : " <<object.mMap[key];
            if( key != object.mMap.lastKey () ){
                stream << " , ";
            }
        }
        stream << " }";
    }

    return stream;
}
