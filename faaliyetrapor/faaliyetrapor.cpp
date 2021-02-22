#include "faaliyetrapor.h"
#include <QUuid>


SerikBLDCore::Faaliyet::RaporItem::RaporItem()
    :SerikBLDCore::Item (Key::Collection)
{
    this->append(Key::uuid,QUuid::createUuid ().toString (QUuid::WithoutBraces).toStdString ());
}

SerikBLDCore::Faaliyet::RaporItem::RaporItem(const SerikBLDCore::Faaliyet::RaporItem &other)
    :SerikBLDCore::Item (Key::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Faaliyet::RaporItem::RaporItem(SerikBLDCore::Faaliyet::RaporItem &&other)
    :SerikBLDCore::Item (Key::Collection)
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Faaliyet::RaporItem &SerikBLDCore::Faaliyet::RaporItem::operator=(const SerikBLDCore::Faaliyet::RaporItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Faaliyet::RaporItem &SerikBLDCore::Faaliyet::RaporItem::operator=(SerikBLDCore::Faaliyet::RaporItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

std::string SerikBLDCore::Faaliyet::RaporItem::getText() const
{
    auto val = this->element (Key::text);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

std::string SerikBLDCore::Faaliyet::RaporItem::uuid() const
{
    auto val = this->element (Key::uuid);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Faaliyet::RaporItem &SerikBLDCore::Faaliyet::RaporItem::setParentUuid(const std::string &uuid)
{
    this->append(Key::parentuuid,uuid);
    return *this;
}

std::string SerikBLDCore::Faaliyet::RaporItem::parentUuid() const
{
    auto val = this->element (Key::parentuuid);
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}


bool SerikBLDCore::Faaliyet::RaporItem::isBaslik() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::baslik);
    }
    return false;
}

bool SerikBLDCore::Faaliyet::RaporItem::isAltBaslik() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::altBaslik);
    }
    return false;
}

bool SerikBLDCore::Faaliyet::RaporItem::isParagraf() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::paragraf);
    }
    return false;
}

bool SerikBLDCore::Faaliyet::RaporItem::isImg() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::img);
    }
    return false;
}

bool SerikBLDCore::Faaliyet::RaporItem::isTable() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::table);
    }
    return false;
}

bool SerikBLDCore::Faaliyet::RaporItem::isPageBreak() const
{
    auto val = this->element (Key::type);
    if( val ){
        return (val.value ().get_utf8 ().value.to_string() == Key::Type::pageBreak);
    }
    return false;
}

SerikBLDCore::Faaliyet::RaporItem &SerikBLDCore::Faaliyet::RaporItem::setText(const std::string &text)
{
    this->append(Key::text,text);
    return *this;
}

SerikBLDCore::Faaliyet::BaslikItem::BaslikItem()
{
    this->append(Key::type,Key::Type::baslik);
}

SerikBLDCore::Faaliyet::AltBaslikItem::AltBaslikItem()
{
    this->append(Key::type,Key::Type::altBaslik);
}

SerikBLDCore::Faaliyet::ParagrafItem::ParagrafItem()
{
    this->append(Key::type,Key::Type::paragraf);
}

SerikBLDCore::Faaliyet::ImgItem::ImgItem()
{
    this->append(Key::type,Key::Type::img);
}

SerikBLDCore::Faaliyet::ImgItem &SerikBLDCore::Faaliyet::ImgItem::setImgOid(const std::string &imgOid)
{
    this->append("imgoid",bsoncxx::oid{imgOid});
    return *this;
}

std::string SerikBLDCore::Faaliyet::ImgItem::getImgOid() const
{
    auto val = this->element ("imgoid");
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

SerikBLDCore::Faaliyet::TableItem::TableItem()
{
    this->append(Key::type,Key::Type::table);

}

SerikBLDCore::Faaliyet::TableItem &SerikBLDCore::Faaliyet::TableItem::setHeaders(const std::vector<std::string> &headers)
{

    for( const auto &item : headers ){
        this->pushArray ("header",item);
    }
    return *this;
}



std::vector<std::string> SerikBLDCore::Faaliyet::TableItem::headers() const
{
    std::vector<std::string> header;

    auto val = this->element ("header");
    if( val ){
        auto arr = val.value ().get_array ().value;

//        std::transform(arr.begin (),arr.end (),header.begin (),[](const bsoncxx::array::element &element ){
//            return element.get_utf8 ().value.to_string();
//        });

        for(const auto &item : arr ){
            header.push_back (item.get_utf8 ().value.to_string());
        }
    }
    return header;
}



SerikBLDCore::Faaliyet::TableItem &SerikBLDCore::Faaliyet::TableItem::appendCell(const int &row, const int &col, const std::string &value)
{
    if( !_appendCell (row,col,value) ){
        errorOccured ("Ekleme Yapılamadı");
    }
    return *this;
}

SerikBLDCore::Faaliyet::TableItem &SerikBLDCore::Faaliyet::TableItem::setCell(const int &row, const int &col, const std::string &value)
{
    if( !_appendCell (row,col,value) ){
        errorOccured ("Ekleme Yapılamadı");
    }
    return *this;
}

std::string SerikBLDCore::Faaliyet::TableItem::cell(const int &row, const int &col) const
{
    std::string returnValue = "";
    auto val = this->element ("table");
    if( val ){

        try{
            auto arrayView = val.value ().get_array ().value;
            for( auto item : arrayView ){
                auto doc = item.get_document ().value;
                if( doc["row"].get_int32 ().value == row ){
                    if( doc["col"].get_int32 ().value == col ){
                        returnValue = doc["data"].get_utf8 ().value.to_string();
                        break;
                    }
                }
            }
        }catch(bsoncxx::exception &e){

            return returnValue;
        }
    }
    return returnValue;
}

void SerikBLDCore::Faaliyet::TableItem::resetCells()
{
    this->removeElement ("table");
}

void SerikBLDCore::Faaliyet::TableItem::resetTable()
{
    this->resetCells ();
}

int SerikBLDCore::Faaliyet::TableItem::row() const
{
    int _row = 0;

    auto val = this->element ("table");
    if( val ){

        try{
            auto arrayView = val.value ().get_array ().value;
            for( auto item : arrayView ){
                auto doc = item.get_document ().value;
                _row = std::max(doc["row"].get_int32 ().value,_row);
            }
        }catch(bsoncxx::exception &e){

        }
    }
    return _row+1;

}

int SerikBLDCore::Faaliyet::TableItem::column() const
{
    int _col = 0;

    auto val = this->element ("table");
    if( val ){

        try{
            auto arrayView = val.value ().get_array ().value;
            for( auto item : arrayView ){
                auto doc = item.get_document ().value;
                _col = std::max(doc["col"].get_int32 ().value,_col);
            }
        }catch(bsoncxx::exception &e){

        }
    }
    return _col+1;
}

bool SerikBLDCore::Faaliyet::TableItem::_appendCell(const int &row, const int &col, const std::string &value)
{
    auto val = this->element ("table");
    if( val ){
        try{


            auto arrayView = val.value ().get_array ().value;

            for( auto item : arrayView ){
                auto doc = item.get_document ().value;
                if( doc["row"].get_int32 ().value == row ){
                    if( doc["col"].get_int32 ().value == col ){
                        this->pullArray ("table",item.get_value () );
                        break;
                    }
                }

            }


        }catch(bsoncxx::exception &e){
            errorOccured (e.what ());
            return false;
        }

    }



    SerikBLDCore::Item item("null");
    item.append("row",bsoncxx::types::b_int32{row});
    item.append("col",bsoncxx::types::b_int32{col});
    item.append("data",value);
    this->pushArray ("table",item);
    return true;
}




SerikBLDCore::Faaliyet::Manager::Manager(SerikBLDCore::DB *_mDB)
    :SerikBLDCore::ListItem<SerikBLDCore::Faaliyet::RaporItem> (_mDB)
{

}

void SerikBLDCore::Faaliyet::Manager::onList(const QVector<SerikBLDCore::Faaliyet::RaporItem> *mlist)
{

}

void SerikBLDCore::Faaliyet::Manager::errorOccured(const std::string &errorText)
{

}

bool SerikBLDCore::Faaliyet::Manager::insertFaaliyetItem(const SerikBLDCore::Faaliyet::FaaliyetItem &faaliyetItem)
{
    auto count = this->getDB ()->countItem (faaliyetItem);
    if( count ){
        this->errorOccured ("Bu Faaliyet Zaten Var. İlk Önce Mevcut Faaliyeti Siliniz!");
        return false;
    }
    auto ins = this->getDB ()->insertItem (faaliyetItem);
    if( ins.value ().result ().inserted_count () ){
         return true;
    }else{
        this->errorOccured ("Faaliyet Oluşturulamadı");
        return false;
    }

}

std::unique_ptr<SerikBLDCore::Faaliyet::FaaliyetItem> SerikBLDCore::Faaliyet::Manager::getFaaliyetItem(const std::string &birim, const int64_t &yil)
{
    auto item = std::make_unique<SerikBLDCore::Faaliyet::FaaliyetItem>();
    auto val = this->getDB ()->findOneItem (SerikBLDCore::Faaliyet::FaaliyetItem().setBirim (birim).setYil (yil));
    if( val ){
        item->setDocumentView (val.value ().view ());
        return item;
    }else{
        this->errorOccured ("Böyle Bir Faaliyet Raporu Yok!");
        return nullptr;
    }
}

std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> SerikBLDCore::Faaliyet::Manager::ListFaaliyetItem(const std::string &birim, const int64_t &yil)
{

    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> itemList;

    if( birim.size () ){
        auto cursor = this->getDB ()->find (SerikBLDCore::Faaliyet::FaaliyetItem().setBirim (birim).setYil (yil),SerikBLDCore::FindOptions().setLimit (100));
        if( cursor ){
            for(const auto &view : cursor.value () ){
                SerikBLDCore::Faaliyet::FaaliyetItem item;
                item.setDocumentView (view);
                itemList.push_back (item);
            }
        }
    }else{
        auto cursor = this->getDB ()->find (SerikBLDCore::Faaliyet::FaaliyetItem().setYil (yil),SerikBLDCore::FindOptions().setLimit (100));
        if( cursor ){
            for(const auto &view : cursor.value () ){
                SerikBLDCore::Faaliyet::FaaliyetItem item;
                item.setDocumentView (view);
                itemList.push_back (item);
            }
        }
    }


    return itemList;
}

std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> SerikBLDCore::Faaliyet::Manager::ListFaaliyetItem(const std::string &birim)
{
    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> itemList;

    if( birim.size () ){
        auto cursor = this->getDB ()->find (SerikBLDCore::Faaliyet::FaaliyetItem().setBirim (birim),SerikBLDCore::FindOptions().setLimit (100));
        if( cursor ){
            for(const auto &view : cursor.value () ){
                SerikBLDCore::Faaliyet::FaaliyetItem item;
                item.setDocumentView (view);
                itemList.push_back (item);
            }
        }
    }else{
        auto cursor = this->getDB ()->find (SerikBLDCore::Faaliyet::FaaliyetItem(),SerikBLDCore::FindOptions().setLimit (100));
        if( cursor ){
            for(const auto &view : cursor.value () ){
                SerikBLDCore::Faaliyet::FaaliyetItem item;
                item.setDocumentView (view);
                itemList.push_back (item);
            }
        }
    }


    return itemList;
}

std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> SerikBLDCore::Faaliyet::Manager::ListFaaliyetItem(const int64_t &yil)
{
    std::vector<SerikBLDCore::Faaliyet::FaaliyetItem> itemList;
        auto cursor = this->getDB ()->find (SerikBLDCore::Faaliyet::FaaliyetItem().setYil (yil),SerikBLDCore::FindOptions().setLimit (100));
        if( cursor ){
            for(const auto &view : cursor.value () ){
                SerikBLDCore::Faaliyet::FaaliyetItem item;
                item.setDocumentView (view);
                itemList.push_back (item);
            }
        }
        return itemList;
}

std::unique_ptr<SerikBLDCore::Faaliyet::FaaliyetItem> SerikBLDCore::Faaliyet::Manager::FaaliyetItem(const std::string &birim, const int64_t &yil)
{

    auto item = std::make_unique<SerikBLDCore::Faaliyet::FaaliyetItem>();

    auto val = this->getDB ()->findOneItem (SerikBLDCore::Faaliyet::FaaliyetItem().setBirim (birim).setYil (yil));

    if( val ){
        item->setDocumentView (val.value ().view ());
    }

    return item;

}



SerikBLDCore::Faaliyet::FaaliyetItem::FaaliyetItem()
    :SerikBLDCore::Item ("FaaliyetItem")
{

}

SerikBLDCore::Faaliyet::FaaliyetItem::FaaliyetItem(const SerikBLDCore::Faaliyet::FaaliyetItem &other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Faaliyet::FaaliyetItem::FaaliyetItem(SerikBLDCore::Faaliyet::FaaliyetItem &&other)
    :SerikBLDCore::Item (other.getCollection ())
{
    this->setDocumentView (other.view ());
}

SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::operator=(const SerikBLDCore::Faaliyet::FaaliyetItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::operator=( SerikBLDCore::Faaliyet::FaaliyetItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::setBirim(const std::string &birim)
{
    this->append("birim",birim);
    return *this;
}

std::string SerikBLDCore::Faaliyet::FaaliyetItem::getBirim() const
{
    auto val = this->element ("birim");
    if( val ){
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::setYil(const int64_t &yil)
{
    this->append("yil",yil);
    return *this;
}

int64_t SerikBLDCore::Faaliyet::FaaliyetItem::getYil() const
{
    auto val = this->element ("yil");
    if( val ){
        return val.value ().get_int64 ().value;
    }
    return 0;
}

SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::setFaaliyet(  const  bsoncxx::array::view &array)
{
    this->append("faaliyet",array);
    return *this;
}

bsoncxx::array::view SerikBLDCore::Faaliyet::FaaliyetItem::getFaaliyetView() const
{
    auto val = this->element ("faaliyet");
    if( val ){
        return val.value ().get_array ().value;
    }
    return bsoncxx::builder::basic::array{}.view ();
}



SerikBLDCore::Faaliyet::FaaliyetItem &SerikBLDCore::Faaliyet::FaaliyetItem::setOnay(const bool &onay, const bsoncxx::oid &onaylayanOid)
{
    this->append(Key::onayli,onay);
    this->append(Key::onaylayan,onaylayanOid);
    return *this;
}

bool SerikBLDCore::Faaliyet::FaaliyetItem::getOnay() const
{
    auto val = this->element (Key::onayli);
    if( val ){
        return val.value ().get_bool ().value;
    }
    return false;
}

std::string SerikBLDCore::Faaliyet::FaaliyetItem::getOnaylayan() const
{
    auto val = this->element (Key::onaylayan);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

std::vector<SerikBLDCore::Faaliyet::RaporItem> SerikBLDCore::Faaliyet::FaaliyetItem::getFaaliyetList() const
{
    std::vector<SerikBLDCore::Faaliyet::RaporItem> list;
    for( auto item : getFaaliyetView () ){
        RaporItem _item;
        _item.setDocumentView (item.get_document ().view ());
        list.push_back (_item);
    }
    return list;

}





SerikBLDCore::Faaliyet::PageBreak::PageBreak()
{
    this->append(Key::type,Key::Type::pageBreak);

}
