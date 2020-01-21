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


#include "item.h"


namespace SerikBLDCore {

class Item;
class FindOptions;

class SERIKBLDCORE_EXPORT DB
{
public:
    explicit DB();
    DB( const DB &db);
    DB( DB&& other );
    explicit DB( mongocxx::database* _db );
    explicit DB( DB* _db );
    explicit DB( const DB* _db );
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


    virtual void errorOccured( const std::string& errorText );

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


    template< typename V>
    mongocxx::stdx::optional<mongocxx::result::update> pushValue( const Item& filter , const std::string& key , const V& value )
    {
        Item item("none");
        item.append("$push",Item("none").append(key,value));
        try {
            auto upt = this->db ()->collection (filter.getCollection ()).update_one (filter.view (),item.view ());
            return upt;
        } catch (mongocxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return mongocxx::stdx::nullopt;
        }
    }


    template< typename V>
    mongocxx::stdx::optional<mongocxx::result::update> pullValue( const Item& filter , const std::string& key , const V& value )
    {
        Item item("none");
        item.append("$pull",Item("none").append(key,value));
        try {
            auto upt = this->db ()->collection (filter.getCollection ()).update_one (filter.view (),item.view ());
            return upt;
        } catch (mongocxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            this->setLastError (str.c_str ());
            return mongocxx::stdx::nullopt;
        }
    }

    template< typename V >
    inline bool setField( const Item& filter , const std::string &field , const V& value ){

        auto _oid = filter.oid ();

        if( !_oid )
        {
            this->setLastError (QString("%1 %2 Required Object ID").arg (__LINE__)
                                .arg (__FUNCTION__));
            return false;
        }

        Item setDoc( filter.getCollection() );
        setDoc.append( "_id" , filter.oid().value());
        setDoc.append( field , value );
        auto result = DB::updateItem (setDoc);
        if( result )
        {
            if( result.value().modified_count() )
            {
                return true;
            }else{
                setLastError (QString("%1 Modified Document").arg (result.value ().modified_count ()));
                return false;
            }
        }else{
            setLastError (QString("setField No Result"));
            return false;
        }
    }


    bool incValue( const Item& filter , const std::string& field , const std::int64_t& value );

    bool incValue( const Item& filter , const std::string& field , const std::int32_t& value );

    mongocxx::stdx::optional<mongocxx::result::delete_result> deleteItem( const Item &item );


    /**
     * @brief countItem
     * Toplam item sayısını Geri Döndürür
     * @param item
     * @return
     */
    int64_t countItem( const Item &item );




    QString getLastError();
    void setLastError(const QString &lastError);

private:
    //    mongocxx::database _mDB;
    //    mongocxx::client* mClient;

    QString mLastError;
    bool mConstructWithNewClient;
    mongocxx::database* mDB;
};





}


#endif // DB_H
