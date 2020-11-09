#include "core.h"



SerikBLDCore::bsoncxx::core::core(const bool &isArray)
    :mIsArray(isArray)
{

}

SerikBLDCore::bsoncxx::core::core(const SerikBLDCore::bsoncxx::core &other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
}

SerikBLDCore::bsoncxx::core::core(SerikBLDCore::bsoncxx::core &&other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
}

SerikBLDCore::bsoncxx::core &SerikBLDCore::bsoncxx::core::operator=(const SerikBLDCore::bsoncxx::core &other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
    return *this;
}

SerikBLDCore::bsoncxx::core &SerikBLDCore::bsoncxx::core::operator=(SerikBLDCore::bsoncxx::core &&other)
{
    this->mMap.clear ();
    mIsArray = other.mIsArray;
    for( auto key : other.mMap.keys () ){
        this->mMap.insert (key,other.mMap.value (key));
    }
    return *this;
}

bool SerikBLDCore::bsoncxx::core::operator==(const SerikBLDCore::bsoncxx::core &other)
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

bool SerikBLDCore::bsoncxx::core::operator!=(const SerikBLDCore::bsoncxx::core &other)
{
    if( *this == other ) return false;
    else return true;
}

QMap<QString, SerikBLDCore::bsoncxx::element> &SerikBLDCore::bsoncxx::core::map()
{
    return mMap;
}

QMap<QString, SerikBLDCore::bsoncxx::element> &SerikBLDCore::bsoncxx::core::view() const
{
    return mMap;
}

int SerikBLDCore::bsoncxx::core::count() const
{
    return this->mMap.count ();
}

bool SerikBLDCore::bsoncxx::core::isArray() const
{
    return mIsArray;
}

void SerikBLDCore::bsoncxx::core::clear()
{
    this->mMap.clear ();
}

std::ostream &SerikBLDCore::bsoncxx::operator<<(std::ostream &stream, const SerikBLDCore::bsoncxx::core &object)
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
