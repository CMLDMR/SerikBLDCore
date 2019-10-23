#ifndef ITEM_H
#define ITEM_H

#include "SerikBLDCore_global.h"

#include <iostream>
#include <QString>
#include <QVector>
#include <QtGlobal>
#include "db.h"

#ifdef Q_OS_WINDOWS

#include "mongoheaders.h"
#include <boost/optional.hpp>

#endif



class SERIKBLDCORE_EXPORT Item
{
public:
    explicit Item(const std::string &collection);
    Item(const Item& other);
    Item(const bsoncxx::document::view mView , const std::string _Collection);

    void operator=(const document &value);
    void operator=(const bsoncxx::document::view &view);
    Item& operator=(const Item &value);

    void setDocumentView( const bsoncxx::document::view &view);

    bsoncxx::document::view view() const;

    void printView() const;

    boost::optional<bsoncxx::types::value> element(std::string key) const;

    QString getLastError();

    boost::optional<bsoncxx::oid> oid() const;

    void setOid( const std::string &oid );

    boost::optional<document> ItemFilter() const;

    std::string getCollection() const;

    void removeElement( const std::string &key );

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


    }

    template<typename T>
    void append( std::string key ,const T &value ){


        this->removeElement (key);

        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }

    }



private:

#ifdef Q_OS_WINDOWS
    document mDoc;
#endif

    const std::string mCollection;

    QVector<QString> ErrorList;

};

#endif // ITEM_H
