#ifndef TALEPKATEGORI_H
#define TALEPKATEGORI_H

#include "Config.h"
#include "item.h"
#include "SerikBLDCore_global.h"

namespace SerikBLDCore {


class SERIKBLDCORE_EXPORT TalepKategori : public Item
{
public:
    explicit TalepKategori();
    TalepKategori( const TalepKategori& other );
    TalepKategori( TalepKategori&& other );


    TalepKategori& operator=( const TalepKategori& other );
    TalepKategori& operator=( TalepKategori&& other );

    void setKategoriName( const QString& name );
    QString KategoriName() const;


public:
    static const std::string Collection;
    static const std::string Baslik;


};


}



#endif // TALEPKATEGORI_H
