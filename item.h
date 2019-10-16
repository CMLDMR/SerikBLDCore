#ifndef ITEM_H
#define ITEM_H

#include <QtGlobal>
#include "SerikBLDCore_global.h"

#include <iostream>

#ifdef Q_OS_WINDOWS

#include "mongoheaders.h"
#include <boost/optional.hpp>

#endif


class SERIKBLDCORE_EXPORT Item
{
public:
    Item();




    void operator=(const document &value);
    void operator=(const bsoncxx::document::view &view);
    void operator=(const Item &value);

    void setDocumentView( const bsoncxx::document::view &view);

    bsoncxx::document::view view() const;

    boost::optional<bsoncxx::types::value> element(std::string key);

    template<typename T>
    void append(std::string key ,const T &value){
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

};

#endif // ITEM_H
