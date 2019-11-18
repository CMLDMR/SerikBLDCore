#include "item.h"


#ifdef DESKTOP
SerikBLDCore::Item::Item(const std::string &collection)
    :mDoc(document{}),mCollection(collection)
{
    mDoc.clear ();
}


SerikBLDCore::Item::Item(const bsoncxx::document::view mView, const std::string _Collection)
    :mCollection(_Collection)
{
    this->setDocumentView (mView);
}

SerikBLDCore::Item::~Item()
{
    mDoc.clear ();
}

void SerikBLDCore::Item::operator=(const bsoncxx::builder::basic::document &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

void SerikBLDCore::Item::operator=(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}


void SerikBLDCore::Item::setDocumentView(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

boost::optional<bsoncxx::types::value> SerikBLDCore::Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        std::cout << str << std::endl;
        return boost::none;
    }
}

bsoncxx::document::view SerikBLDCore::Item::view() const
{
    return mDoc.view ();
}

boost::optional<bsoncxx::oid> SerikBLDCore::Item::oid() const
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }
}

boost::optional<bsoncxx::builder::basic::document> SerikBLDCore::Item::ItemFilter() const
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

#else


#endif

SerikBLDCore::Item::Item(const Item &other) : mCollection(other.getCollection ())
{
#ifdef DESKTOP
    this->setDocumentView (other.view ());
#else


#endif
}

SerikBLDCore::Item::Item(Item &&other)
{
#ifdef DESKTOP
    this->setDocumentView (other.view ());
#else


#endif
}

SerikBLDCore::Item& SerikBLDCore::Item::operator=(const Item &value)
{
#ifdef DESKTOP
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
#else


#endif
    return *this;


}

SerikBLDCore::Item &SerikBLDCore::Item::operator=(Item &&other)
{
#ifdef DESKTOP
    mDoc.clear ();
    for( auto item : other.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
#else


#endif
    return *this;

}

void SerikBLDCore::Item::printView() const
{
#ifdef DESKTOP
    std::cout << this->getCollection () << " " <<bsoncxx::to_json (this->view ()) << std::endl;
#else


#endif
}

SerikBLDCore::Item &SerikBLDCore::Item::setOid(const std::string &oid)
{
#ifdef DESKTOP
    this->append("_id",bsoncxx::oid{oid});
    return *this;
#else


#endif
}


std::string SerikBLDCore::Item::getCollection() const
{
    return mCollection;
}

void SerikBLDCore::Item::removeElement(const std::string &key)
{
#ifdef DESKTOP
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
#else


#endif
}



