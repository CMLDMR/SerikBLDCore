#include "item.h"



SerikBLDCore::Item::Item(const std::string &collection)
    :mDoc(document{}),mCollection(collection)
{
    mDoc.clear ();
}

SerikBLDCore::Item::Item(const bsoncxx::document::view mView, const std::string &_Collection)
    :mCollection(_Collection)
{
    this->setDocumentView (mView);
}

SerikBLDCore::Item& SerikBLDCore::Item::setDocumentView(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
#ifdef Q_CC_MSVC
        this->append(item.key ().to_string().c_str (),item.get_value ());
#endif

#ifdef Q_CC_GNU
        this->append(item.key (),item.get_value ());
#endif
    }
    return *this;
}






SerikBLDCore::Item::~Item()
{
    mDoc.clear ();
}

SerikBLDCore::Item& SerikBLDCore::Item::operator=(const bsoncxx::builder::basic::document &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
#ifdef Q_CC_MSVC
        this->append(item.key ().to_string().c_str (),item.get_value ());
#endif

#ifdef Q_CC_GNU
        this->append(item.key (),item.get_value ());
#endif
    }
    return *this;
}

SerikBLDCore::Item& SerikBLDCore::Item::operator=(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
#ifdef Q_CC_MSVC
        this->append(item.key ().to_string().c_str (),item.get_value ());
#endif

#ifdef Q_CC_GNU
        this->append(item.key (),item.get_value ());
#endif
    }
    return *this;
}




#ifdef Q_CC_MSVC
boost::optional<bsoncxx::types::value> SerikBLDCore::Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        const_cast<SerikBLDCore::Item*>(this)->errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::oid> SerikBLDCore::Item::oid() const
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        const_cast<SerikBLDCore::Item*>(this)->errorOccured (str);
        return boost::none;
    }
}


boost::optional<bsoncxx::types::value> SerikBLDCore::Item::element(std::string key)
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::oid> SerikBLDCore::Item::oid()
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::builder::basic::document> SerikBLDCore::Item::ItemFilter()
{

    auto oid = this->oid ();

    if( oid )
    {
        auto doc = document{};

        try {
            doc.append (kvp("_id",oid.value ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
            return boost::none;
        }
        return std::move(doc);
    }else{
        return boost::none;
    }

}

boost::optional<QTime> SerikBLDCore::Item::getTime() const
{
    auto _oid = this->oid ();

    if( _oid )
    {
        return boost::none;
    }

    auto dateTime = QDateTime::fromTime_t (_oid.value ().get_time_t ());

    if( !dateTime.isValid () )
    {
        return boost::none;
    }

    return dateTime.time ();
}

boost::optional<QDate> SerikBLDCore::Item::getDate() const
{
    auto _oid = this->oid ();

    if( _oid )
    {
        return boost::none;
    }

    auto dateTime = QDateTime::fromTime_t (_oid.value ().get_time_t ());

    if( !dateTime.isValid () )
    {
        return boost::none;
    }

    return dateTime.date ();
}

#endif

#ifdef Q_CC_GNU
std::optional<bsoncxx::types::value> SerikBLDCore::Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        const_cast<SerikBLDCore::Item*>(this)->errorOccured (str);
        return std::nullopt;;
    }
}


std::optional<bsoncxx::oid> SerikBLDCore::Item::oid() const
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        const_cast<SerikBLDCore::Item*>(this)->errorOccured (str);
        return std::nullopt;
    }
}



std::optional<bsoncxx::types::value> SerikBLDCore::Item::element(std::string key)
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        errorOccured (str);
        return std::nullopt;
    }
}

std::optional<bsoncxx::oid> SerikBLDCore::Item::oid()
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        errorOccured (str);
        return std::nullopt;
    }
}


std::optional<bsoncxx::builder::basic::document> SerikBLDCore::Item::ItemFilter()
{

    auto oid = this->oid ();

    if( oid )
    {
        auto doc = document{};

        try {
            doc.append (kvp("_id",oid.value ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
            return std::nullopt;
        }
        return std::move(doc);
    }else{
        return std::nullopt;
    }

}

std::optional<QTime> SerikBLDCore::Item::getTime() const
{
    auto _oid = this->oid ();

    if( _oid )
    {
        return std::nullopt;
    }

    auto dateTime = QDateTime::fromTime_t (_oid.value ().get_time_t ());

    if( !dateTime.isValid () )
    {
        return std::nullopt;
    }

    return dateTime.time ();
}

std::optional<QDate> SerikBLDCore::Item::getDate() const
{
    auto _oid = this->oid ();

    if( _oid )
    {
        return std::nullopt;
    }

    auto dateTime = QDateTime::fromTime_t (_oid.value ().get_time_t ());

    if( !dateTime.isValid () )
    {
        return std::nullopt;
    }

    return dateTime.date ();
}


#endif



bsoncxx::document::view SerikBLDCore::Item::view() const
{
    return mDoc.view ();
}



SerikBLDCore::Item::Item(const Item &other) : mCollection(other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Item::Item(Item &&other)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Item& SerikBLDCore::Item::operator=(const Item &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

SerikBLDCore::Item &SerikBLDCore::Item::operator=(Item &&other)
{
    mDoc.clear ();
    for( auto item : other.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

void SerikBLDCore::Item::errorOccured(const std::string &errorText)
{

}

void SerikBLDCore::Item::printView() const
{
    std::cout << __LINE__ << " " << __FUNCTION__ << " Coll: " <<this->getCollection () << " : " <<bsoncxx::to_json (this->view ()) << std::endl;
}

void SerikBLDCore::Item::clear()
{
    this->mDoc.clear ();
}

SerikBLDCore::Item &SerikBLDCore::Item::setOid(const std::string &oid)
{
    this->append("_id",bsoncxx::oid{oid});
    return *this;
}

SerikBLDCore::Item &SerikBLDCore::Item::setOid(const bsoncxx::oid &oid)
{
    this->append("_id",oid);
    return *this;
}


std::string SerikBLDCore::Item::getCollection() const
{
    return mCollection;
}

void SerikBLDCore::Item::setCollection(const std::string &collection)
{
    this->mCollection = collection;
}


#ifdef Q_CC_MSVC
void SerikBLDCore::Item::removeElement(const std::string &key)
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
                errorOccured (str);
            }
        }
    }
    mDoc.clear ();

    for( auto item : tempDoc.view () )
    {
        mDoc.append(kvp(item.key ().to_string(),item.get_value ()));
    }
}
#endif

#ifdef Q_CC_GNU
void SerikBLDCore::Item::removeElement(const std::string_view &key)
{
    auto tempDoc = document{};
    for( auto item : mDoc.view () )
    {
        if( key != item.key () )
        {
            try {
                tempDoc.append( kvp( item.key () , item.get_value () ) );
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                errorOccured (str);
            }
        }
    }
    mDoc.clear ();

    for( auto item : tempDoc.view () )
    {
        mDoc.append(kvp(item.key (),item.get_value ()));
    }
}
#endif








SerikBLDCore::FindOptions::FindOptions()
    :Item("none")
{

}



SerikBLDCore::FindOptions &SerikBLDCore::FindOptions::setLimit(const int &limit)
{
    this->append("limit",bsoncxx::types::b_int64{limit});
    return *this;
}






SerikBLDCore::FindOptions &SerikBLDCore::FindOptions::setSkip(const int &skip)
{
    this->append("skip",bsoncxx::types::b_int64{skip});
    return *this;
}






SerikBLDCore::FindOptions &SerikBLDCore::FindOptions::setProjection(const SerikBLDCore::Item &projItem)
{
    this->append("projection",projItem);
    return *this;
}






SerikBLDCore::FindOptions &SerikBLDCore::FindOptions::setSort(const SerikBLDCore::Item &sortItem)
{
    this->append("sort",sortItem);
    return *this;
}






int SerikBLDCore::FindOptions::limit() const
{
    auto val = this->element ("limit");

    if( val )
    {
        return static_cast<int>(val.value ().get_int64 ().value);
    }else{
        return 20;
    }
}





int SerikBLDCore::FindOptions::skip() const
{
    auto val = this->element ("skip");

    if( val )
    {
        return static_cast<int>(val.value ().get_int64 ().value);
    }else{
        return 0;
    }
}






SerikBLDCore::Item SerikBLDCore::FindOptions::sort() const
{
    auto val = this->element ("sort");
    if( val )
    {
        return SerikBLDCore::Item(val.value ().get_document (),"none");
    }
    return SerikBLDCore::Item("none");
}






SerikBLDCore::Item SerikBLDCore::FindOptions::projection() const
{    auto val = this->element ("projection");
     if( val )
     {
         SerikBLDCore::Item item(val.value ().get_document ().value,"none");
         return item;
     }
     return SerikBLDCore::Item("none");
}










