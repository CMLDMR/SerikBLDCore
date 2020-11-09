#include "talepmanager.h"
#include "talepkategorimanager.h"

SerikBLDCore::TalepManager::TalepManager() : DB()
{

}

SerikBLDCore::TalepManager::TalepManager(DB *mDB) : DB(mDB)
{

}

SerikBLDCore::TalepManager::TalepManager(mongocxx::database *_db) : DB(_db)
{

}

bool SerikBLDCore::TalepManager::insertTalep(const Talep *item)
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

std::string SerikBLDCore::TalepManager::insertTalep(const Talep &item)
{
    try {
        auto ins = this->insertItem (item);
        if( ins )
        {
            if( ins.value ().result ().inserted_count () )
            {
                return ins.value ().inserted_id ().get_oid ().value.to_string ();
            }else{
                return "";
            }
        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return "";
    }
}

bool SerikBLDCore::TalepManager::updateTalep(const Talep *item)
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

QVector<SerikBLDCore::Talep> SerikBLDCore::TalepManager::findTalep(const Talep &filter, int limit, int skip)
{
    QVector<Talep> list;

    mongocxx::options::find findOptions;

    findOptions.limit (limit);
    findOptions.skip (skip);


    Talep sortDoc;

    sortDoc.append("_id",-1);


    findOptions.sort (sortDoc.view ());

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

QVector<SerikBLDCore::Talep> SerikBLDCore::TalepManager::findTalep(const SerikBLDCore::Talep &filter, const SerikBLDCore::FindOptions &findOptions)
{
    QVector<Talep> list;

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

SerikBLDCore::Talep SerikBLDCore::TalepManager::findOneTalep(const Talep &filter)
{
    Talep item;

    auto val = this->findOneItem (filter);
    if( val )
    {
        item.setDocumentView (val.value ().view ());
    }
    return item;
}

int64_t SerikBLDCore::TalepManager::talepCount(const SerikBLDCore::Talep &filter)
{
    return this->countItem (filter);
}

bool SerikBLDCore::TalepManager::insertTalepSubItem(const TalepSubItem *item)
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

QVector<SerikBLDCore::TalepSubItem> SerikBLDCore::TalepManager::findTalepSubItem(const QString &talepOid)
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

SerikBLDCore::TalepKey::DurumPipelineResult SerikBLDCore::TalepManager::durumPipeLine(const QString &birim)
{
    TalepKey::DurumPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (make_document(kvp(TalepKey::Birim,birim.toStdString ())));

    stage.group (make_document(kvp("_id","$Durum"),
                               kvp("count",make_document(kvp("$sum",1)))));

    // Mahalle Mahalle Devam Ediyor Tamamlandı Olarak Ayırıyor.
//    stage.group (make_document(kvp("_id",make_document(kvp("Durum","$Durum"),kvp("Mahalle","$Mahalle"))),
//                               kvp("count",make_document(kvp("$sum",1)))));



    auto cursor = this->db ()->collection (SerikBLDCore::TalepKey::Collection).aggregate (stage);


    result.Beklemede = 0;
    result.RedEdildi = 0;
    result.Tamamlandi = 0;
    result.DevamEdiyor = 0;
    result.TeyitEdilmemis = 0;

    for( auto doc : cursor )
    {

        std::cout << __LINE__ << " " << __FUNCTION__ << " docView: " << bsoncxx::to_json (doc) << std::endl;

        try {
#ifdef Q_CC_MSVC
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::Beklemede)
            {
                result.Beklemede = doc["count"].get_int32 ().value;
            }
#endif

#ifdef Q_CC_GNU
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::Beklemede)
            {
                result.Beklemede = doc["count"].get_int32 ().value;
            }
#endif


        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beklemede = 0;
        }

        try {

#ifdef Q_CC_MSVC
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::RedEdildi)
            {
                result.RedEdildi = doc["count"].get_int32 ().value;
            }
#endif

#ifdef Q_CC_GNU
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::RedEdildi)
            {
                result.RedEdildi = doc["count"].get_int32 ().value;
            }
#endif

        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.RedEdildi = 0;
        }

        try {
#ifdef Q_CC_MSVC
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::Tamamlandi)
            {
                result.Tamamlandi = doc["count"].get_int32 ().value;
            }
#endif

#ifdef Q_CC_GNU
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::Tamamlandi)
            {
                result.Tamamlandi = doc["count"].get_int32 ().value;
            }
#endif

        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Tamamlandi = 0;
        }

        try {
#ifdef Q_CC_MSVC
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::DevamEdiyor)
            {
                result.DevamEdiyor = doc["count"].get_int32 ().value;
            }
#endif

#ifdef Q_CC_GNU
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::DevamEdiyor)
            {
                result.DevamEdiyor = doc["count"].get_int32 ().value;
            }
#endif

        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.DevamEdiyor = 0;
        }

        try {
#ifdef Q_CC_MSVC
            if( doc["_id"].get_utf8 ().value.to_string() == TalepKey::DurumKey::TeyitEdilmemis){
                result.TeyitEdilmemis = doc["count"].get_int32 ().value;
            }
#endif

#ifdef Q_CC_GNU
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::TeyitEdilmemis){
                result.TeyitEdilmemis = doc["count"].get_int32 ().value;
            }
#endif

        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.TeyitEdilmemis = 0;
        }
    }
    return result;
}

SerikBLDCore::TalepKey::DurumPipelineResult SerikBLDCore::TalepManager::durumPipeLine(const SerikBLDCore::Talep &filter)
{
#ifdef Q_CC_MSVC


    TalepKey::DurumPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (filter.view ());

    stage.group (make_document(kvp("_id","$Durum"),
                               kvp("count",make_document(kvp("$sum",1)))));

    // Mahalle Mahalle Devam Ediyor Tamamlandı Olarak Ayırıyor.
//    stage.group (make_document(kvp("_id",make_document(kvp("Durum","$Durum"),kvp("Mahalle","$Mahalle"))),
//                               kvp("count",make_document(kvp("$sum",1)))));



    auto cursor = this->db ()->collection (SerikBLDCore::TalepKey::Collection).aggregate (stage);


    result.Beklemede = 0;
    result.RedEdildi = 0;
    result.Tamamlandi = 0;
    result.DevamEdiyor = 0;
    result.TeyitEdilmemis = 0;

    for( auto doc : cursor )
    {

        std::cout << __LINE__ << " " << __FUNCTION__ << " docView: " << bsoncxx::to_json (doc) << std::endl;

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


#endif

#ifdef Q_CC_GNU

    TalepKey::DurumPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (filter.view ());

    stage.group (make_document(kvp("_id","$Durum"),
                               kvp("count",make_document(kvp("$sum",1)))));

    // Mahalle Mahalle Devam Ediyor Tamamlandı Olarak Ayırıyor.
//    stage.group (make_document(kvp("_id",make_document(kvp("Durum","$Durum"),kvp("Mahalle","$Mahalle"))),
//                               kvp("count",make_document(kvp("$sum",1)))));



    auto cursor = this->db ()->collection (SerikBLDCore::TalepKey::Collection).aggregate (stage);


    result.Beklemede = 0;
    result.RedEdildi = 0;
    result.Tamamlandi = 0;
    result.DevamEdiyor = 0;
    result.TeyitEdilmemis = 0;

    for( auto doc : cursor )
    {

        std::cout << __LINE__ << " " << __FUNCTION__ << " docView: " << bsoncxx::to_json (doc) << std::endl;

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::Beklemede)
            {
                result.Beklemede = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beklemede = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::RedEdildi)
            {
                result.RedEdildi = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.RedEdildi = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::Tamamlandi)
            {
                result.Tamamlandi = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Tamamlandi = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::DevamEdiyor)
            {
                result.DevamEdiyor = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.DevamEdiyor = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::DurumKey::TeyitEdilmemis){
                result.TeyitEdilmemis = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.TeyitEdilmemis = 0;
        }
    }
    return result;
#endif

}

SerikBLDCore::TalepKey::KaynakPipelineResult SerikBLDCore::TalepManager::kaynakPipeLine(const QString &birim)
{

#ifdef Q_CC_MSVC

    TalepKey::KaynakPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (make_document(kvp(TalepKey::Birim,birim.toStdString ())));

    stage.group (make_document(kvp("_id","$Kaynak"),
                               kvp("count",make_document(kvp("$sum",1)))));

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



#endif

#ifdef Q_CC_GNU

    TalepKey::KaynakPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (make_document(kvp(TalepKey::Birim,birim.toStdString ())));

    stage.group (make_document(kvp("_id","$Kaynak"),
                               kvp("count",make_document(kvp("$sum",1)))));

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
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Sms)
            {
                result.Sms = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Sms = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Web)
            {
                result.Web = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Web = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Mobil)
            {
                result.Mobil = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Mobil = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Telefon)
            {
                result.Telefon = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Telefon = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Beyazmasa){
                result.Beyazmasa = doc["count"].get_int32 ().value;
            }


        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beyazmasa = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::SosyalMedya){
                result.SosyalMedya = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.SosyalMedya = 0;
        }
    }
    return result;




#endif


}

SerikBLDCore::TalepKey::KaynakPipelineResult SerikBLDCore::TalepManager::kaynakPipeLine(const SerikBLDCore::Talep &filter)
{

#ifdef Q_CC_MSVC

    TalepKey::KaynakPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (filter.view ());

    stage.group (make_document(kvp("_id","$Kaynak"),
                               kvp("count",make_document(kvp("$sum",1)))));

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


#endif

#ifdef Q_CC_GNU
    TalepKey::KaynakPipelineResult result;
    mongocxx::pipeline stage;

    stage.match (filter.view ());

    stage.group (make_document(kvp("_id","$Kaynak"),
                               kvp("count",make_document(kvp("$sum",1)))));

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
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Sms)
            {
                result.Sms = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Sms = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Web)
            {
                result.Web = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Web = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Mobil)
            {
                result.Mobil = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Mobil = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Telefon)
            {
                result.Telefon = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Telefon = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::Beyazmasa){
                result.Beyazmasa = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.Beyazmasa = 0;
        }

        try {
            if( doc["_id"].get_utf8 ().value == TalepKey::KaynakKey::SosyalMedya){
                result.SosyalMedya = doc["count"].get_int32 ().value;
            }
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.SosyalMedya = 0;
        }
    }
    return result;
#endif


}

std::vector<SerikBLDCore::TalepKey::KategoriPipelineResult> SerikBLDCore::TalepManager::kategoriPipeLine(const SerikBLDCore::Talep &filter)
{

    std::vector<SerikBLDCore::TalepKey::KategoriPipelineResult> resultList;

    TalepKategoriManager* mKategoriManager = new TalepKategoriManager(this->getDB ());


    mKategoriManager->setLimit (1000);

    mKategoriManager->UpdateList ();

    mongocxx::pipeline stage;

    stage.match (filter.view ());

    stage.group (make_document(kvp("_id","$"+TalepKey::KategoriOid),
                               kvp("count",make_document(kvp("$sum",1)))));

    auto cursor = this->db ()->collection (TalepKey::Collection).aggregate (stage);

    for( auto doc : cursor )
    {
        TalepKey::KategoriPipelineResult result;
        result.mSayi = 0;
        try {
            result.mKategoriOid = doc["_id"].get_oid ().value.to_string ();
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            result.mKategoriOid = "";
        }

        if( result.mKategoriOid.size () )
        {
            try {
                result.mKategori = mKategoriManager->KategoriName (doc["_id"].get_oid ().value.to_string().c_str ()).toStdString ();
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                std::cout << str << std::endl;
            }

            try {
                result.mSayi = doc["count"].get_int32 ().value;
            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                std::cout << str << std::endl;
            }
            resultList.push_back (result);
        }

    }
    return resultList;
}
