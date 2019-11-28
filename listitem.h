#ifndef LISTITEM_H
#define LISTITEM_H

#include "Config.h"
#include "SerikBLDCore_global.h"
#include "db.h"


namespace SerikBLDCore {



template <typename T>
class ListItem : public DB
{
public:
    ListItem(DB* db) : DB(db){}

    inline const T &itemAt(const QString &byOid)
    {
         T *item = new T();
        for( auto _item : __mlist )
        {
            auto _oid = _item.oid();
            if( _oid )
            {
                if( byOid.toStdString () == _oid.value().to_string() )
                {
                    item->setDocumentView(_item.view());// _item;
                    break;
                }
            }
        }
        return std::move(*item);
    }

    inline QVector<T>& UpdateList(const T& filter , const int &limit = 20 , const int &skip = 0 ){
        __mlist.clear ();
        auto cursor = this->find ( filter , limit , skip );
        if( cursor )
        {
            for( auto item : cursor.value() )
            {
                T _item;
                _item.setDocumentView(item);
                __mlist.append (_item);
            }
        }
        return __mlist;
    }

    inline bool UpdateItem( const T& item ){
        auto result = DB::updateItem (item);
        if( result )
        {
            if( result.value ().modified_count () )
            {
                replace (item);
                return true;
            }else{
                return false;
            }
        }
        return false;
    }

    inline std::string InsertItem( const T& item ){
        auto result = DB::insertItem (item);
        if( result )
        {
            if( result.value ().result ().inserted_count () )
            {
                T _item;
                _item.setDocumentView(item.view());
                _item.setOid( result.value ().inserted_id ().get_oid ().value.to_string () );
                __mlist.append (_item);
                return result.value ().inserted_id ().get_oid ().value.to_string ();
            }else{
                return "";
            }
        }else{
            return "";
        }
    }

    inline bool DeleteItem( const T& item ){
        auto result = DB::deleteItem (item);
        if( result )
        {
            if( result.value ().deleted_count () )
            {
                remove (item);
                return true;
            }
        }
        return false;
    }

private:
    QVector<T> __mlist;

    void replace( const T& item ){
        int index = 0;
        for( auto _item : __mlist )
        {
            if( _item.oid().value().to_string() == item.oid().value().to_string() )
            {
                __mlist.replace (index,item);
                break;
            }
            index++;
        }
    }

    void remove( const T& item ){
        int index = 0;
        for( auto _item : __mlist )
        {
            if( _item.oid().value().to_string() == item.oid().value().to_string() )
            {
                __mlist.remove (index);
                break;
            }
            index++;
        }
    }

};



}





#endif // LISTITEM_H
