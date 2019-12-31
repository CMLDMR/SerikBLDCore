#include "db.h"
#include <QFile>
#include <QByteArray>
#include <QFileInfo>
#include <fstream>
#include <QDir>
//#include "item.h"



static int DBConnectionCount = 0;

SerikBLDCore::DB::DB()
{
//    std::cout << "New Connect: Connection Count: " << ++DBConnectionCount << std::endl;
//    mConstructWithNewClient = true;
//    try {
//        mClient = new mongocxx::client(mongocxx::uri(_url));
//    } catch (mongocxx::exception &e) {
//        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
//        std::cout << str << std::endl;
//    }
//    _mDB = mClient->database (DB__);
}

SerikBLDCore::DB::DB(const DB &db)
    :mDB(db.mDB)
{
    std::cout << "DB::DB(const DB &db): " << DBConnectionCount << std::endl;
    mConstructWithNewClient = false;
}

SerikBLDCore::DB::DB(SerikBLDCore::DB &&other)
    :mDB(other.mDB)
{
    std::cout << "DB::DB(DB &&db): " << DBConnectionCount << std::endl;
    mConstructWithNewClient = false;
}

SerikBLDCore::DB::DB(mongocxx::database *_db)
    :mDB( _db )
{
    std::cout << "DB::DB(mongocxx::database *_db): " << DBConnectionCount << std::endl;
    mConstructWithNewClient = false;
}

SerikBLDCore::DB::DB(DB *_db) : mDB(_db->db ())
{
    std::cout << "DB::DB(DB *_db): " << DBConnectionCount << std::endl;
    mConstructWithNewClient = false;
}

SerikBLDCore::DB::DB(const DB *_db) : mDB( _db->getDB ()->mDB )
{

}



SerikBLDCore::DB::~DB()
{
    std::cout << "-DB Destructor- Delete Client: " << mConstructWithNewClient << std::endl;
    if( mConstructWithNewClient )
    {
        std::cout << "Delete DB Connection, CurrentConnection Count: " <<  --DBConnectionCount << std::endl;
    }
    std::cout << "DB Destructor End" << std::endl;
}

SerikBLDCore::DB &SerikBLDCore::DB::operator=(const DB &otherDB)
{
    std::cout << "DB &DB::operator=(const DB &otherDB): " << DBConnectionCount << std::endl;
    mDB = otherDB.mDB;
    return *this;
}

SerikBLDCore::DB &SerikBLDCore::DB::operator=(SerikBLDCore::DB &&otherDB)
{
    std::cout << "DB &DB::operator=(const DB &otherDB): " << DBConnectionCount << std::endl;
    mDB = otherDB.mDB;
    return *this;
}

SerikBLDCore::DB &SerikBLDCore::DB::operator=(mongocxx::database *_db)
{
    std::cout << "DB &DB::operator=(const DB &otherDB): " << DBConnectionCount << std::endl;
    mDB = _db;
    return *this;
}

void SerikBLDCore::DB::errorOccured(const std::string &errorText)
{

}

QVector<QString> SerikBLDCore::DB::getMahalleler()
{

    QVector<QString> list;


    FindOptions options;

    options.setSkip (0);
    options.setLimit (0);
    options.setSort (Item("none").append("Mahalleler",-1));

    auto cursor = this->find (std::move(Item("Mahalleler")),options);
    if( cursor )
    {
        for( auto doc : cursor.value () )
        {
            try {
                list.append (doc["Mahalle"].get_utf8 ().value.to_string().c_str ());
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() ;
                this->setLastError (str.c_str ());
            }
        }
    }
    return list;

}



mongocxx::database *SerikBLDCore::DB::db()
{
    return mDB;
}

std::string SerikBLDCore::DB::downloadFile(const QString &fileOid, bool forceFilename)
{
    auto bucket = this->db ()->gridfs_bucket ();

    auto doc = bsoncxx::builder::basic::document{};

    try {
        doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{fileOid.toStdString ()}));
    } catch (bsoncxx::exception& e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() ;
        this->setLastError (str.c_str ());
        return "NULL";
    }



    mongocxx::gridfs::downloader downloader;
    try {
        auto roid = bsoncxx::types::value(doc.view()["key"].get_oid());
        downloader = bucket.open_download_stream(roid);

    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() ;
        this->setLastError (str.c_str ());
        return "";
    }


    auto file_length = downloader.file_length();
    std::int32_t bytes_counter = 0;

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
    }else{
        std::string str = "Error Can Not Open File: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + fullFilename.toStdString() ;
        this->setLastError (str.c_str ());
    }

    return fullFilename.toStdString ();
}

std::string SerikBLDCore::DB::downloadFileWeb(const QString &fileOid, bool forceFilename)
{
    auto bucket = this->mDB->gridfs_bucket ();

    auto doc = bsoncxx::builder::basic::document{};

    try {
        doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{fileOid.toStdString ()}));
    } catch (bsoncxx::exception& e) {
        std::string str = "Error: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() ;
        this->setLastError (str.c_str ());
        return "NULL";
    }



    mongocxx::gridfs::downloader downloader;
    try {
        auto roid = bsoncxx::types::value(doc.view()["key"].get_oid());
        downloader = bucket.open_download_stream(roid);
    } catch (bsoncxx::exception &e) {
        std::string str = "Error: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() ;
        this->setLastError (str.c_str ());
        return "img/404-header.png";
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
    }else{
        std::string str = "Error Can Not Open File: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + fullFilename.toStdString() ;
        this->setLastError (str.c_str ());
    }

    return fullFilename.toStdString ();
}

bsoncxx::types::value SerikBLDCore::DB::uploadfile(QString filepath)
{
    auto bucket = this->db ()->gridfs_bucket ();
    QFile file( filepath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        QFileInfo info(filepath);
        auto uploader = bucket.open_upload_stream(info.fileName().toStdString().c_str());
        QByteArray ar = file.readAll();
        file.close();

        uploader.write((std::uint8_t*)ar.data(),ar.size());
        auto res = uploader.close();
        return res.id();
    }else{
        std::string str = "Error Can Not Open File: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + filepath.toStdString() ;
        this->setLastError (str.c_str ());
    }
}

bsoncxx::types::value SerikBLDCore::DB::uploadfile(QString filepath) const
{
    auto bucket = mDB->gridfs_bucket ();
    mongocxx::gridfs::uploader uploader;
    QFile file( filepath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        QFileInfo info(filepath);
        uploader = bucket.open_upload_stream(info.fileName().toStdString().c_str());
        QByteArray ar = file.readAll();
        file.close();

        uploader.write((std::uint8_t*)ar.data(),ar.size());
        auto res = uploader.close();
        return res.id();
    }else{
        std::string str = "Error Can Not Open File: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + filepath.toStdString() ;
        const_cast<SerikBLDCore::DB*>(this)->setLastError (str.c_str ());
        return uploader.close ().id ();
    }
}

bool SerikBLDCore::DB::deleteGridFS(const QString &fileOid)
{
    bsoncxx::types::value id(bsoncxx::types::b_oid{bsoncxx::oid{fileOid.toStdString ()}});
    try {
        mDB->gridfs_bucket ().delete_file (id);
        return true;
    } catch (mongocxx::gridfs_exception &e) {
        std::string str = "ERROR GridFS Exception: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return false;
    } catch ( mongocxx::bulk_write_exception &e) {
        std::string str = "ERROR bulk_write_exception: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return false;
    }
}

mongocxx::stdx::optional<mongocxx::result::insert_one> SerikBLDCore::DB::insertItem(const Item &item)
{

    try {
        auto ins = this->db ()->collection (item.getCollection ()).insert_one (item.view ());
        return ins;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::result::update> SerikBLDCore::DB::updateItem(const Item &item)
{

    auto filter = document{};

    try {
        filter.append (kvp("_id",item.view ()["_id"].get_oid ().value));
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return boost::none;
    }

    auto doc = document{};

    bool _errorOccured = false;
    for( auto element : item.view () )
    {
        if( element.key ().to_string() != "_id" )
        {
            try {
                doc.append (kvp(element.key (),element.get_value ()));
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                this->setLastError (str.c_str ());
                _errorOccured = true;
                break;
            }
        }
    }


    if( _errorOccured ) return boost::none;

    auto setDoc = document{};


    try {
        setDoc.append (kvp("$set",doc));
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return boost::none;
    }


    try {
        auto upt = this->db ()->collection (item.getCollection ()).update_one (filter.view (),setDoc.view ());
        return upt;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }


}

mongocxx::stdx::optional<bsoncxx::document::value> SerikBLDCore::DB::findOneItem(const Item &item )
{
    try {
        auto value = this->db ()->collection (item.getCollection ()).find_one (item.view ());
        return value;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Collection: " + item.getCollection ();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<bsoncxx::document::value> SerikBLDCore::DB::findOneItem(const SerikBLDCore::Item &item, const SerikBLDCore::Item &findOptions)
{
    mongocxx::options::find findOptions_;

    findOptions_.sort (findOptions.view ());

    try {
        auto value = this->db ()->collection (item.getCollection ()).find_one (item.view (),findOptions_);
        return value;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Collection: " + item.getCollection ();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::cursor> SerikBLDCore::DB::find(const Item &item, const mongocxx::options::find findOptions)
{
    try {
        auto cursor = this->db ()->collection (item.getCollection ()).find (item.view (),findOptions);
        return std::move(cursor);
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() +" Collection: " + item.getCollection ();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::cursor> SerikBLDCore::DB::find(const SerikBLDCore::Item &item, const int &limit, const int &skip)
{
    mongocxx::options::find findOptions;

    findOptions.limit (limit);
    findOptions.skip (skip);

    Item sortItem(item.getCollection ());
    sortItem.append("_id",-1);

    findOptions.sort (sortItem.view ());


    try {
        auto cursor = this->db ()->collection (item.getCollection ()).find (item.view (),findOptions);
        return std::move(cursor);
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() +" Collection: " + item.getCollection ();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}

mongocxx::stdx::optional<mongocxx::cursor> SerikBLDCore::DB::find(const SerikBLDCore::Item &item, const SerikBLDCore::FindOptions &options)
{
    mongocxx::options::find findOptions;
    auto doc = document{};

    if( options.limit () != 0 )
    {
        findOptions.limit (options.limit ());
    }

    findOptions.skip (options.skip ());

    doc.clear ();
    if( !options.projection ().view ().empty () )
    {
        auto __view = options.element ("projection");
        if( __view )
        {
            for( auto __item : __view.value ().get_document ().value)
            {
                try {
                    doc.append (kvp(__item.key ().to_string(),__item.get_value ()));
                } catch (bsoncxx::exception &e) {
                    std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                    this->setLastError (str.c_str ());
                }
            }
            findOptions.projection (doc.view ());
        }
    }

    doc.clear ();
    if( !options.sort ().view ().empty () )
    {
        auto __view = options.element ("sort");
        if( __view )
        {
            for( auto __item : __view.value ().get_document ().value)
            {
                try {
                    doc.append (kvp(__item.key ().to_string(),__item.get_value ()));
                } catch (bsoncxx::exception &e) {
                    std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                    this->setLastError (str.c_str ());
                }
            }
            findOptions.sort (doc.view ());
        }
    }


    try {
        auto cursor = this->db ()->collection (item.getCollection ()).find (item.view (),findOptions);
        return std::move(cursor);
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() +" Collection: " + item.getCollection ();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}



mongocxx::stdx::optional<mongocxx::result::delete_result> SerikBLDCore::DB::deleteItem(const Item &item)
{
    try {
        auto del = this->db ()->collection (item.getCollection ()).delete_one (item.view ());
        return del;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return mongocxx::stdx::nullopt;
    }
}



std::int64_t SerikBLDCore::DB::countItem(const Item &item)
{
    try {
        auto count = this->db ()->collection (item.getCollection ()).count_documents (item.view ());
        return count;
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        this->setLastError (str.c_str ());
        return -1;
    }
}

QString SerikBLDCore::DB::getLastError()
{
    auto str = mLastError;
    mLastError = "";
    return str;
}

void SerikBLDCore::DB::setLastError(const QString &lastError)
{
    mLastError = lastError;
    errorOccured (lastError.toStdString ());
}


