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

Item::Item(const bsoncxx::document::view mView, const std::string _Collection)
    :mCollection(_Collection)
{
    this->setDocumentView (mView);
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

Item& Item::operator=(const Item &value)
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

void Item::printView() const
{
    std::cout << bsoncxx::to_json (this->view ()) << std::endl;
}

boost::optional<bsoncxx::types::value> Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        std::cout << str << std::endl;
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

boost::optional<bsoncxx::oid> Item::oid() const
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

void Item::setOid(const std::string &oid)
{
    this->append("_id",bsoncxx::oid{oid});
}

boost::optional<bsoncxx::builder::basic::document> Item::ItemFilter() const
{

    auto oid = this->oid ();

    if( oid )
    {
        auto doc = document{};

        try {
            doc.append (kvp("_id",oid.value ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return boost::none;
        }
    }else{
        return boost::none;
    }

}

std::string Item::getCollection() const
{
    return mCollection;
}

void Item::removeElement(const std::string &key)
{
    auto tempDoc = document{};

    for( auto item : mDoc.view () )
    {
        if( key != item.key ().to_string() )
        {
            try {
                tempDoc.append( kvp( item.key ().to_string() , item.get_value () ) );

            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                std::cout << str << std::endl;
            }
        }
    }
    mDoc.clear ();

    for( auto item : tempDoc.view () )
    {
        mDoc.append(kvp(item.key ().to_string(),item.get_value ()));
    }

}



