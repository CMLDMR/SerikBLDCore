#include "tc.h"
#include <QRandomGenerator>

const std::string TC::Collection = "TC";


TC::TC(TC *other) : Item() , DB()
{

    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}

void TC::setTCNO(const QString &tcno)
{
    this->append(KeyTC,tcno.toStdString ());
}

void TC::setAdSoyad(const QString &adsoyad)
{
    this->append(KeyAdSoyad,adsoyad.toStdString ());
}

void TC::setCepTelefonu(const QString &cepTelefonu)
{
    this->append(KeyCepTelefonu,cepTelefonu.toStdString ());

}

void TC::setMahalle(const QString &mahalle)
{
    this->append(KeyMahalle,mahalle.toStdString ());

}

void TC::setTamAdress(const QString &adres)
{
    this->append(KeyAdres,adres.toStdString ());

}

void TC::setPassword(const QString &password)
{
    if( password == "" )
    {
        auto _password = QString::number (1234+(QRandomGenerator::global ()->generate ()%10000));
        this->append(KeyPassword,_password.toStdString ());
    }else{
        this->append(KeyPassword,password.toStdString ());
    }

}

void TC::setNormalTelefon(const QString &normalTelefon)
{
    this->append(KeyNormalTelefon,normalTelefon.toStdString ());
}

void TC::setCalismaSMS(const bool &smsgitsin)
{
    this->append(KeyCalismaSMS,smsgitsin);

}
