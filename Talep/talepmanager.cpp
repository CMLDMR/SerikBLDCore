#include "talepmanager.h"

TalepManager::TalepManager() : DB()
{

}

TalepManager::TalepManager(DB *mDB) : DB(mDB)
{

}

TalepManager::TalepManager(mongocxx::database *_db) : DB(_db)
{

}

bool TalepManager::insertTalep(const Talep *item)
{
    try {
        auto ins = this->insertItem (*item);
        if( ins )
        {
            if( ins.value ().result ().inserted_count () )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }
}

bool TalepManager::updateTalep(const Talep *item)
{
    try {
        auto ins = this->updateItem (*item);
        if( ins )
        {
            if( ins.value ().result ().modified_count ())
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }
}

QVector<Talep> TalepManager::findTalep(const Talep &filter, int limit, int skip)
{
    QVector<Talep> list;

    mongocxx::options::find findOptions;

    findOptions.limit (limit);
    findOptions.skip (skip);

    try {
        auto cursor = this->find (filter,findOptions);
        if( cursor )
        {
            for( auto item : cursor.value ())
            {
                Talep talep;
                talep.setDocumentView (item);
                list.append (talep);
            }
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }
    return list;
}

Talep TalepManager::findOneTalep(const Talep &filter)
{
    Talep item;

    auto val = this->findOneItem (filter);
    if( val )
    {
        item.setDocumentView (val.value ().view ());
    }
    return item;
}

bool TalepManager::insertTalepSubItem(const TalepSubItem *item)
{
    try {
        auto ins = this->insertItem (*item);
        if( ins )
        {
            if( ins.value ().result ().inserted_count () )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return false;
    }
}

QVector<TalepSubItem> TalepManager::findTalepSubItem(const QString &talepOid)
{
    TalepSubItem filter;
    filter.setTalepOid (talepOid);


    QVector<TalepSubItem> list;


    try {
        auto cursor = this->find (filter);
        if( cursor )
        {
            for( auto item : cursor.value ())
            {
                TalepSubItem talep;
                talep.setDocumentView (item);
                list.append (talep);
            }
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
    }
    return list;
}

TalepKey::DurumPipelineResult TalepManager::durumPipeLine(const QString &birim)
{
    TalepKey::DurumPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (make_document(kvp(TalepKey::Birim,birim.toStdString ())));

    stage.group (make_document(kvp("_id","$Durum"),
                               kvp("count",make_document(kvp("$sum",1)))));

    // Mahalle Mahalle Devam Ediyor Tamamlandı Olarak Ayırıyor.
//    stage.group (make_document(kvp("_id",make_document(kvp("Durum","$Durum"),kvp("Mahalle","$Mahalle"))),
//                               kvp("count",make_document(kvp("$sum",1)))));



    auto cursor = this->db ()->collection (TalepKey::Collection).aggregate (stage);

    for( auto doc : cursor )
    {
        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::Beklemede)
            {
                result.Beklemede = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beklemede = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::RedEdildi)
            {
                result.RedEdildi = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.RedEdildi = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::Tamamlandi)
            {
                result.Tamamlandi = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Tamamlandi = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::DevamEdiyor)
            {
                result.DevamEdiyor = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.DevamEdiyor = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::TeyitEdilmemis){
                result.TeyitEdilmemis = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.TeyitEdilmemis = 0;
        }
    }
    return result;
}

TalepKey::KaynakPipelineResult TalepManager::kaynakPipeLine(const QString &birim)
{
    TalepKey::KaynakPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (make_document(kvp(TalepKey::Birim,birim.toStdString ())));

    stage.group (make_document(kvp("_id","$Kaynak"),
                               kvp("count",make_document(kvp("$sum",1)))));

    // Mahalle Mahalle Devam Ediyor Tamamlandı Olarak Ayırıyor.
//    stage.group (make_document(kvp("_id",make_document(kvp("Durum","$Durum"),kvp("Mahalle","$Mahalle"))),
//                               kvp("count",make_document(kvp("$sum",1)))));


    result.Sms = 0;
    result.Web = 0;
    result.Mobil = 0;
    result.Telefon = 0;
    result.Beyazmasa = 0;
    result.SosyalMedya = 0;

    auto cursor = this->db ()->collection (TalepKey::Collection).aggregate (stage);

    for( auto doc : cursor )
    {
        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::Sms)
            {
                result.Sms = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Sms = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::Web)
            {
                result.Web = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Web = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::Mobil)
            {
                result.Mobil = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Mobil = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::Telefon)
            {
                result.Telefon = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Telefon = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::Beyazmasa){
                result.Beyazmasa = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beyazmasa = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::KaynakKey::SosyalMedya){
                result.SosyalMedya = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.SosyalMedya = 0;
        }
    }
    return result;
}
