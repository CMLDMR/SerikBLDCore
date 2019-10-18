#include "item.h"

Item::Item(const std::string &collection)
    :mDoc(document{}),mCollection(collection)
{
    mDoc.clear ();
}

Item::Item(const Item &other) : mCollection(other.getCollection ())
{
    this->setDocumentView (other.view ());
}

void Item::operator=(const bsoncxx::builder::basic::document &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

void Item::operator=(const bsoncxx::document::view &view)
{
    mDoc.clear ();

    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

Item Item::operator=(const Item &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;

}


void Item::setDocumentView(const bsoncxx::document::view &view)
{
    mDoc.clear ();

    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

bsoncxx::document::view Item::view() const
{
    return mDoc.view ();
}

boost::optional<bsoncxx::types::value> Item::element(std::string key)
{

    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        ErrorList.append (str.c_str ());
        return boost::none;
    }


}



QString Item::getLastError()
{
    if( ErrorList.count () )
    {
        return ErrorList.last ();
    }else{
        return "No Error";
    }
}

boost::optional<bsoncxx::oid> Item::oid()
{
    std::string _oid;
    for( auto item : this->view () )
    {
        if( item.key ().to_string() == "_id" )
        {
            _oid = item.get_oid ().value.to_string ();
            break;
        }
    }

    if( _oid.empty () )
    {
        return boost::none;
    }else{
        return bsoncxx::oid{_oid};
    }

}

std::string Item::getCollection() const
{
    return mCollection;
}

