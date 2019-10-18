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
    Item(const std::string &collection);
    Item(const Item& other);

    void operator=(const document &value);
    void operator=(const bsoncxx::document::view &view);
    Item operator=(const Item &value);

    void setDocumentView( const bsoncxx::document::view &view);

    bsoncxx::document::view view() const;

    boost::optional<bsoncxx::types::value> element(std::string key);


    template<typename T>
    void append(std::string key ,const T &value){

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


        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
        }



        for( auto item : tempDoc.view () )
        {
            mDoc.append(kvp(item.key ().to_string(),item.get_value ()));
        }
    }

    QString getLastError();

    boost::optional<bsoncxx::oid> oid();

    std::string getCollection() const;

private:

#ifdef Q_OS_WINDOWS
    document mDoc;
#endif

    const std::string mCollection;

    QVector<QString> ErrorList;

};

#endif // ITEM_H
