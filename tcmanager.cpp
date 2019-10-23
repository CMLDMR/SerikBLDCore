#include "tcmanager.h"



TCManager::TCManager() : DB()
{

}

TCManager::TCManager(DB *mDB) : DB(mDB)
{

}

TCManager::TCManager(mongocxx::database *_db) : DB(_db)
{

}

boost::optional<TC> TCManager::Create_TC()
{
    auto item = new TC();

    try {
        auto ins = this->db ()->collection (TC::Collection).insert_one (item->view ());
        if( ins )
        {
            item->setOid (ins.value ().inserted_id ().get_oid ().value.to_string ());
            return *item;
        }else{
            return boost::none;
        }
    } catch (mongocxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }


}
