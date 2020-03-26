#include "talepkategorimanager.h"


#include <QDebug>


SerikBLDCore::TalepKategoriManager::TalepKategoriManager(DB *_mDB)
    : ListItem<SerikBLDCore::TalepKategori>(_mDB)
{


}

void SerikBLDCore::TalepKategoriManager::onList(const QVector<SerikBLDCore::TalepKategori> *mlist)
{
    qDebug() << "Talep Kategori Manager";

    for( auto item : *mlist )
    {
        qDebug() << item.KategoriName ();
    }

}

void SerikBLDCore::TalepKategoriManager::errorOccured(const std::string &errorText)
{

}
