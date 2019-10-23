#ifndef DB_H
#define DB_H


#include "SerikBLDCore_global.h"
#include <iostream>
#include <QString>
#include <QtGlobal>



#ifdef Q_OS_WINDOWS
#include "../url.h"
#include "mongoheaders.h"
#include <boost/optional.hpp>
#endif

class Item;

class SERIKBLDCORE_EXPORT DB
{
public:
    explicit DB();
    DB( const DB &db);
    DB( mongocxx::database* _db );
    DB( DB* _db );
    ~DB();

    DB& operator=(const DB& otherDB);

    mongocxx::database* db();

    std::string downloadFile(const QString &fileOid , bool forceFilename = false);
    bsoncxx::types::value uploadfile(QString filepath );

    mongocxx::stdx::optional<mongocxx::result::insert_one> insertItem(const Item &item);
    mongocxx::stdx::optional<mongocxx::result::update> updateItem( const Item &item);
    mongocxx::stdx::optional<bsoncxx::document::value> findOneItem( const Item &item );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item );

    ///
    /// \brief countItem
    /// \param item
    /// \return
    /// return item matched Count else if error return -1
    int64_t countItem( const Item &item );

private:




private:
    mongocxx::database _mDB;
    mongocxx::client* mClient;

    bool mConstructWithNewClient;
    mongocxx::database* mDB;
};

#endif // DB_H
