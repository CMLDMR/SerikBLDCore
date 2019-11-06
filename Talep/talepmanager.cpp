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
