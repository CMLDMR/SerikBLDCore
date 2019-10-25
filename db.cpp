#include "db.h"
#include <QFile>
#include <QByteArray>
#include <QFileInfo>
#include <fstream>
#include <QDir>
#include "item.h"

static int DBConnectionCount = 0;

DB::DB()
{

    std::cout << "Connection Count: " << ++DBConnectionCount << std::endl;
    mConstructWithNewClient = true;
    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }
    _mDB = mClient->database (DB__);
}

DB::DB(const DB &db)
    :mDB(db.mDB)
{
    mConstructWithNewClient = false;
}

DB::DB(mongocxx::database *_db)
    :mDB( _db )
{
    std::cout << "DB::DB(mongocxx::database *_db): " << DBConnectionCount << std::endl;
    mConstructWithNewClient = false;
}

DB::DB(DB *_db) : mDB(_db->db ())
{
    mConstructWithNewClient = false;
}



DB::~DB()
{
    std::cout << "DB Destructor " << std::endl;
    if( mConstructWithNewClient )
    {
        std::cout << "Delete DB Connection, CurrentConnection Count: " <<  --DBConnectionCount << std::endl;
        delete mClient;
    }
}

DB &DB::operator=(const DB &otherDB)
{
    mClient = otherDB.mClient;
    _mDB = mClient->database (DB__);
    return *this;
}

mongocxx::database *DB::db()
{
    if( mConstructWithNewClient )
    {
        return &_mDB;
    }else{
        return mDB;
    }
}

std::string DB::downloadFile(const QString &fileOid, bool forceFilename)
{
    auto bucket = this->db ()->gridfs_bucket ();

    auto doc = bsoncxx::builder::basic::document{};

    try {
        doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{fileOid.toStdString ()}));
    } catch (bsoncxx::exception& e) {
        std::cout << __LINE__ << " Error: " << e.what() << std::endl;
        return "NULL";
    }



    mongocxx::gridfs::downloader downloader;
    try {
        auto roid = bsoncxx::types::value(doc.view()["key"].get_oid());
        downloader = bucket.open_download_stream(roid);

    } catch (bsoncxx::exception &e) {
        return "";
    }


    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename;

    QDir dir;

    if( !dir.exists ("tempfile") )
    {
        dir.mkdir ("tempfile");
    }

    if( forceFilename )
    {
        fullFilename = QString("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
    }else{
        fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
                .arg(downloader.files_document()["_id"].get_oid().value.to_string().c_str());
    }


    if( QFile::exists(fullFilename) )
    {
        return fullFilename.toStdString ();
    }else{
        std::cout << "FILE NOT FOUND: " << fullFilename.toStdString() << std::endl;
    }

    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

    std::ofstream out;

    out.open(fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


    if( out.is_open() )
    {

        while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {

            auto bufferPtr = buffer.get();
            out.write(reinterpret_cast<char*>(bufferPtr),length_read);

            bytes_counter += static_cast<std::int32_t>( length_read );

        }

        out.close();
    }

    else{
        std::cout << "Error Can Not Open File: " <<fullFilename.toStdString() << std::endl;
    }

    return fullFilename.toStdString ();
}

std::string DB::downloadFileWeb(const QString &fileOid, bool forceFilename)
{
    auto bucket = this->db ()->gridfs_bucket ();

    auto doc = bsoncxx::builder::basic::document{};

    try {
        doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{fileOid.toStdString ()}));
    } catch (bsoncxx::exception& e) {
        std::cout << __LINE__ << " Error: " << e.what() << std::endl;
        return "NULL";
    }



    mongocxx::gridfs::downloader downloader;
    try {
        auto roid = bsoncxx::types::value(doc.view()["key"].get_oid());
        downloader = bucket.open_download_stream(roid);

    } catch (bsoncxx::exception &e) {
        return "";
    }


    auto file_length = downloader.file_length();
    auto bytes_counter = 0;

    QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

    QString fullFilename;

    QDir dir;

    dir.cd ("docroot");

    if( !dir.exists ("tempfile") )
    {
        dir.mkdir ("tempfile");
    }

    if( forceFilename )
    {
        fullFilename = QString("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
    }else{
        fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
                .arg(downloader.files_document()["_id"].get_oid().value.to_string().c_str());
    }


    if( QFile::exists("docroot/"+fullFilename) )
    {
        return fullFilename.toStdString ();
    }else{
        std::cout << "FILE NOT FOUND: " << fullFilename.toStdString() << std::endl;
    }

    auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
    auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

    std::ofstream out;

    out.open("docroot/"+fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


    if( out.is_open() )
    {

        while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {

            auto bufferPtr = buffer.get();
            out.write(reinterpret_cast<char*>(bufferPtr),length_read);

            bytes_counter += static_cast<std::int32_t>( length_read );

        }

        out.close();
    }

    else{
        std::cout << "Error Can Not Open File: " <<fullFilename.toStdString() << std::endl;
    }

    return fullFilename.toStdString ();
}

bsoncxx::types::value DB::uploadfile(QString filepath)
{
    auto bucket = this->db ()->gridfs_bucket ();
    QFile file( filepath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        QFileInfo info(filepath);
        auto uploader = bucket.open_upload_stream(info.fileName().toStdString().c_str());
        QByteArray ar = file.readAll();
        uploader.write((std::uint8_t*)ar.data(),ar.size());
        auto res = uploader.close();
        file.close();
        return res.id();
    }
}

mongocxx::stdx::optional<mongocxx::result::insert_one> DB::insertItem(const Item &item)
{

    try {
        auto ins = this->db ()->collection (item.getCollection ()).insert_one (item.view ());
        return ins;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::result::update> DB::updateItem(const Item &item)
{
    auto filter = item.ItemFilter();

    if( filter )
    {
        try {
            auto upt = this->db ()->collection (item.getCollection ()).update_one (filter.value ().view (),item.view ());
            return upt;
        } catch (mongocxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return mongocxx::stdx::nullopt;
        }
    }else{
        return mongocxx::stdx::nullopt;
    }

}

mongocxx::stdx::optional<bsoncxx::document::value> DB::findOneItem(const Item &item)
{
    try {
        auto value = this->db ()->collection (item.getCollection ()).find_one (item.view ());
        return value;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::cursor> DB::find(const Item &item, const mongocxx::options::find findOptions)
{
    try {
        auto cursor = this->db ()->collection (item.getCollection ()).find (item.view (),findOptions);
        return std::move(cursor);
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::result::delete_result> DB::deleteItem(const Item &item)
{
    try {
        auto del = this->db ()->collection (item.getCollection ()).delete_one (item.view ());
        return del;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return mongocxx::stdx::nullopt;
    }
}



std::int64_t DB::countItem(const Item &item)
{
    try {
        auto count = this->db ()->collection (item.getCollection ()).count_documents (item.view ());
        return count;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return -1;
    }
}
