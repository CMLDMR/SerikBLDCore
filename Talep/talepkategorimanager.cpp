#include "talepkategorimanager.h"


#include <QDebug>


SerikBLDCore::TalepKategoriManager::TalepKategoriManager(DB *_mDB)
    : ListItem<SerikBLDCore::TalepKategori>(_mDB)
{


}

void SerikBLDCore::TalepKategoriManager::onList(const QVector<SerikBLDCore::TalepKategori> *mlist)
{


}

void SerikBLDCore::TalepKategoriManager::errorOccured(const std::string &errorText)
{

}

QString SerikBLDCore::TalepKategoriManager::KategoriName(const QString &kategoriOid) const
{

    QString kategoriName;

    for( auto item : this->List () )
    {
        if( kategoriOid == item.oid ().value ().to_string ().c_str () )
        {
            kategoriName = item.KategoriName ();
            break;
        }
    }

    return kategoriName;
}
