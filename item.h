#ifndef ITEM_H
#define ITEM_H

#include "SerikBLDCore_global.h"
#include "Config.h"

#include <iostream>
#include <QString>
#include <QVector>
#include <QtGlobal>
#include "db.h"

#ifdef DESKTOP
#include "mongoheaders.h"
#include <boost/optional.hpp>
#else
#include "qbson/qelement.h"
#endif



class SERIKBLDCORE_EXPORT Item
{
public:
    explicit Item(const std::string &collection);
    Item(const Item& other);
    Item( Item &&other );
    ~Item();



    Item& operator=(const Item &value);
    Item& operator=( Item &&other );


#ifdef DESKTOP
    Item(const bsoncxx::document::view mView , const std::string _Collection);
    void operator=(const document &value);
    void operator=(const bsoncxx::document::view &view);
    void setDocumentView( const bsoncxx::document::view &view);
    bsoncxx::document::view view() const;
    boost::optional<bsoncxx::types::value> element(std::string key) const;
    boost::optional<bsoncxx::oid> oid() const;
    boost::optional<document> ItemFilter() const;
#else


#endif


    void printView() const;



    void setOid( const std::string &oid );


    std::string getCollection() const;

    void removeElement( const std::string &key );

    template<typename T>
    void pushArray(std::string key ,const T &value){

#ifdef DESKTOP
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
                    std::cout << str << std::endl;
                }
            }
        }

        try {
            arr.append (value);
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }

        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }
#else


#endif
    }



    template<typename T>
    void append( std::string key ,const T &value ){
#ifdef DESKTOP
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }
#else


#endif
    }



private:

#ifdef DESKTOP
    document mDoc;
#else


#endif
    const std::string mCollection;

};

#endif // ITEM_H
