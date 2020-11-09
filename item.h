#ifndef ITEM_H
#define ITEM_H

#include "SerikBLDCore_global.h"
#include "Config.h"

#include <iterator>
#include <iostream>

#include <QString>
#include <QVector>
#include <QtGlobal>
#include <QDate>
#include <QDateTime>


#include "mongoheaders.h"


#ifdef Q_CC_MSVC
#include <boost/optional.hpp>
#endif

#ifdef Q_CC_GNU
#include <optional>
#endif


#include <iostream>
#include <string>


namespace SerikBLDCore {





class SERIKBLDCORE_EXPORT Item
{
public:
    explicit Item(const std::string &collection);   // Alındı
    Item(const Item& other);                        //
    Item( Item &&other );
    virtual ~Item();



    Item& operator=(const Item &value);
    Item& operator=( Item &&other );

    virtual void errorOccured(const std::string& errorText ) ;



    Item(const bsoncxx::document::view mView , const std::string &_Collection);
    Item& operator=(const document &value);
    Item& operator=(const bsoncxx::document::view &view);
    SerikBLDCore::Item& setDocumentView( const bsoncxx::document::view &view);
    bsoncxx::document::view view() const;




#ifdef Q_CC_MSVC
    boost::optional<bsoncxx::types::value> element(std::string key) const;
    boost::optional<bsoncxx::oid> oid() const;
    boost::optional<bsoncxx::types::value> element(std::string key);
    boost::optional<bsoncxx::oid> oid();
    boost::optional<document> ItemFilter();
    boost::optional<QTime> getTime() const;
    boost::optional<QDate> getDate() const;
#endif

#ifdef Q_CC_GNU
    std::optional<bsoncxx::types::value> element(std::string key) const;
    std::optional<bsoncxx::oid> oid() const;
    std::optional<bsoncxx::types::value> element(std::string key);
    std::optional<bsoncxx::oid> oid();
    std::optional<document> ItemFilter();
    std::optional<QTime> getTime() const;
    std::optional<QDate> getDate() const;
#endif




    void printView() const;

    void clear();

    Item& setOid( const std::string &oid );

    Item& setOid( const bsoncxx::oid& oid );

    std::string getCollection() const;

    void setCollection( const std::string& collection );


#ifdef Q_CC_MSVC
    void removeElement( const std::string &key );
#endif

#ifdef Q_CC_GNU
    void removeElement( const std::string_view &key );
#endif



    template<typename T>
    void pushArray(std::string key ,const T &value){
        auto arr = array{};
        auto existArray = this->element (key);

        if( existArray )
        {
            this->removeElement ( key );

            for( auto item : existArray.value ().get_array ().value )
            {
                try {
                    arr.append (item.get_value ());
                } catch (bsoncxx::exception &e) {
                    std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                    errorOccured (str);
                }
            }
        }

        try {
            arr.append (value);
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }

        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
    }


//    template<Item>
    void pushArray(std::string key ,const Item &value){
        auto arr = array{};
        auto existArray = this->element (key);

        if( existArray )
        {
            this->removeElement ( key );

            for( auto item : existArray.value ().get_array ().value )
            {
                try {
                    arr.append (item.get_value ());
                } catch (bsoncxx::exception &e) {
                    std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                    errorOccured (str);
                }
            }
        }

        try {
            arr.append (value.view ());
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }

        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
    }




    void pullArray( const std::string& key , const bsoncxx::types::value &value )
    {
        auto arr = array{};
        auto existArray = this->element (key);

        if( existArray )
        {
            this->removeElement ( key );
            for( auto item : existArray.value ().get_array ().value )
            {

                if( value != item.get_value ())
                {
                    try {
                        arr.append (item.get_value ());
                    } catch (bsoncxx::exception &e) {
                        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                        errorOccured (str);
                    }
                }
            }
        }

        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }

    }




#ifdef Q_CC_MSVC
    template<typename T>
    Item& append( const std::string &key ,const T &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }
#endif

#ifdef Q_CC_GNU
    template<typename T>
    Item& append( const std::string_view &key ,const T &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }
#endif



#ifdef Q_CC_MSVC
    template<>
    Item& append( const std::string &key ,const Item &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value.view ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }
#endif

#ifdef Q_CC_GNU
    template<>
    Item& append( const std::string_view &key ,const Item &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value.view ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }
#endif






private:
    document mDoc;
    std::string mCollection;
};









class SERIKBLDCORE_EXPORT FindOptions : public Item
{
public:
    explicit FindOptions();


    FindOptions& setLimit( const int &limit );
    FindOptions& setSkip( const int &skip );

    FindOptions& setSort( const Item& sortItem);
    FindOptions& setProjection( const Item& projItem);

    int limit() const;
    int skip() const;

    Item sort() const;
    Item projection() const;


};


}


#endif // ITEM_H
