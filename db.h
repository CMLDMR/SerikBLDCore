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

class SERIKBLDCORE_EXPORT DB
{
public:
    explicit DB();
    DB(mongocxx::database* _db);
    DB(DB* _db);
    ~DB();

    mongocxx::database* db();

    std::string downloadFile(const QString &fileOid , bool forceFilename = false);

    bsoncxx::types::value uploadfile(QString filepath );

private:
    mongocxx::database* mDB;




private:
    mongocxx::database _mDB;
    mongocxx::client* mClient;
};

#endif // DB_H
