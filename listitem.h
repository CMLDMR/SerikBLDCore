#ifndef LISTITEM_H
#define LISTITEM_H

#include "Config.h"
#include "SerikBLDCore_global.h"
#include "db.h"
#include "item.h"


namespace SerikBLDCore {



template <typename T>
class ListItem : public DB
{
public:
    ListItem(DB* db) : DB(db),__limit(20),__skip(0){}

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

    inline QVector<T>& UpdateList(const T& filter , const int &limit , const int &skip  ){
        __mlist.clear ();
        __limit = limit;
        __skip = skip;
        __count = this->countItem (filter);
        auto cursor = this->find ( filter , __limit , __skip );
        if( cursor )
        {
            for( auto item : cursor.value() )
            {
                T _item;
                _item.setDocumentView(item);
                __mlist.append (_item);
            }
        }
        this->__onlist (__mlist);
        return __mlist;
    }

    inline QVector<T>& UpdateList(const T& filter = T() ){
        __mlist.clear ();
        __count = this->countItem (filter);
        auto cursor = this->find ( filter , __limit , __skip );
        if( cursor )
        {
            for( auto item : cursor.value() )
            {
                T _item;
                _item.setDocumentView(item);
                __mlist.append (_item);
            }
        }
        this->__onlist (__mlist);
        return __mlist;
    }

    inline QVector<T>& UpdateList( const T& filter , const SerikBLDCore::FindOptions& options )
    {

        __mlist.clear ();
        __count = this->countItem (filter);

        __limit = options.limit ();
        __skip = options.skip ();

        auto cursor = this->find ( filter , options  );
        if( cursor )
        {
            for( auto item : cursor.value() )
            {
                T _item;
                _item.setDocumentView(item);
                __mlist.append (_item);
            }
        }
        this->__onlist (__mlist);
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
            }else{
                return false;
            }
        }
        return false;
    }


    inline QVector<T>& next(const T& filter ){
        __count = this->countItem (filter);
        if( __skip + __limit < __count )
        {
            __skip += __limit;
            return this->UpdateList (filter);
        }else{
            this->UpdateList (filter);
            this->__onlist (__mlist);
            return __mlist;
        }
    }

    inline QVector<T>& back( const T& filter ){
        __count = this->countItem (filter);
        if( __skip > __limit )
        {
            __skip -= __limit;
            return this->UpdateList (filter);
        }else{
            if( __skip > 0 )
            {
                __skip = 0;
            }
            this->UpdateList (filter);
            this->__onlist (__mlist);
            return __mlist;
        }
    }


    inline void setLimit( const int& limit ){ __limit = limit; }
    inline int limit() const { return __limit; }

    inline void setSkip( const int& skip ) { __skip = skip; }
    inline int skip() const { return __skip; }

    inline int totalCount () const { return __count; }


    virtual void onList( const QVector<T>  *mlist ) = 0;

    const QVector<T> &List() const
    {
        return __mlist;
    }


    virtual void errorOccured(const std::string &errorText) override
    {

    }

private:
    QVector<T> __mlist;

    void __onlist( QVector<T> &mlist ){
        this->onList (&mlist);
    }

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


    int __limit = 20;
    int __skip = 0;
    int __count = 0;



};



}





#endif // LISTITEM_H
