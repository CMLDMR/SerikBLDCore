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

namespace SerikBLDCore {

class Item;
class FindOptions;

class SERIKBLDCORE_EXPORT DB
{
public:
    explicit DB();
    DB( const DB &db);
    DB( DB&& other );
    DB( mongocxx::database* _db );
    DB( DB* _db );
    DB( const DB* _db );
    virtual ~DB();

    DB& operator=(const DB& otherDB);
    DB& operator=( DB&& otherDB );
    DB& operator=( mongocxx::database* _db );



    const DB* getDB() const {
        return this;
    }

    DB* getDB(){
        return this;
    }



    QVector<QString> getMahalleler() ;


    mongocxx::database* db();

    std::string downloadFile(const QString &fileOid , bool forceFilename = false);
    std::string downloadFileWeb( const QString &fileOid , bool forceFilename = false );
    bsoncxx::types::value uploadfile(QString filepath );
    bsoncxx::types::value uploadfile(QString filepath ) const;
    bool deleteGridFS( const QString &fileOid );

    mongocxx::stdx::optional<mongocxx::result::insert_one> insertItem(const Item &item);
    mongocxx::stdx::optional<mongocxx::result::update> updateItem( const Item &item);
    mongocxx::stdx::optional<bsoncxx::document::value> findOneItem(const Item &item );
    mongocxx::stdx::optional<bsoncxx::document::value> findOneItem(const Item &item , const Item &findOptions );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item , const mongocxx::options::find findOptions );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item , const int &limit = 20 , const int &skip = 0  );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item , const FindOptions& options  );

    mongocxx::stdx::optional<mongocxx::result::delete_result> deleteItem( const Item &item );


    /**
     * @brief countItem
     * Toplam item sayısını Geri Döndürür
     * @param item
     * @return
     */
    int64_t countItem( const Item &item );

private:




private:
//    mongocxx::database _mDB;
//    mongocxx::client* mClient;

    bool mConstructWithNewClient;
    mongocxx::database* mDB;
};

}


#endif // DB_H
