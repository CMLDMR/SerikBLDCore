#include "item.h"

Item::Item()
    :mDoc(document{})
{
    mDoc.clear ();
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

void Item::operator=(const Item &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }

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

