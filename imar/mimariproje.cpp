#include "mimariproje.h"

const std::string SerikBLDCore::Imar::MimariProje::MainProje::Collection{"MimariProjeler"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyFirmaOid{"firmaOid"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyBasvuruJulianDay{"basvuruTarihi"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyAda{"ada"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyParsel{"parsel"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyAdi{"projeAdi"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyMahalle{"projeMahalle"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyOnay{"projeOnay"};
const std::string SerikBLDCore::Imar::MimariProje::MainProje::keyOnaylamaTarihi{"projeOnaylamaJulian"};

SerikBLDCore::Imar::MimariProje::MainProje::MainProje()
    :SerikBLDCore::Item (Collection)
{

}

SerikBLDCore::Imar::MimariProje::MainProje::MainProje( const bsoncxx::oid& firmaOid , const std::int64_t& basvuruJulianday )
    :SerikBLDCore::Item (Collection)
{
    this->append(keyFirmaOid,firmaOid);
    this->append(keyBasvuruJulianDay,bsoncxx::types::b_int64{basvuruJulianday});
}

SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setAdi(const std::string &adi)
{
    this->append(keyAdi,adi);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setAda(const int &adaNo)
{
    this->append(keyAda,bsoncxx::types::b_int64{adaNo});
    return *this;
}

SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setParsel(const int &parselNo)
{
    this->append(keyParsel,bsoncxx::types::b_int64{parselNo});
    return *this;
}



SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setMahalle(const std::string &mahalle)
{
    this->append(keyMahalle,mahalle);
    return *this;
}



SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setFirmaOid(const bsoncxx::oid &firmaOid)
{
    this->append(keyFirmaOid,firmaOid);
    return *this;
}

SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setBasvuruJulianDay(const int64_t &basvuruJulianDay)
{
    this->append(keyBasvuruJulianDay,bsoncxx::types::b_int64{basvuruJulianDay});
    return *this;
}

SerikBLDCore::Imar::MimariProje::MainProje &SerikBLDCore::Imar::MimariProje::MainProje::setOnay(const bool &onay)
{
    this->append(keyOnay,onay);
    this->append(keyOnaylamaTarihi,bsoncxx::types::b_int64{QDate::currentDate ().toJulianDay ()});
    return *this;
}


std::string SerikBLDCore::Imar::MimariProje::MainProje::adi() const
{
    auto val = this->element (keyAdi);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }else{
        return "";
    }
}

std::string SerikBLDCore::Imar::MimariProje::MainProje::firmaOid() const
{
    auto val = this->element (keyFirmaOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }else{
        return "";
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MainProje::basvuruJulianDay() const
{
    auto val = this->element (keyBasvuruJulianDay);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MainProje::ada() const
{
    auto val = this->element (keyAda);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MainProje::parsel() const
{
    auto val = this->element (keyParsel);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}


std::string SerikBLDCore::Imar::MimariProje::MainProje::mahalle() const
{
    auto val = this->element (keyMahalle);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }else{
        return "";
    }
}

bool SerikBLDCore::Imar::MimariProje::MainProje::onay() const
{
    auto val = this->element (keyOnay);
    if( val ){
        return val.value ().get_bool ().value;
    }else{
        return false;
    }
}

int64_t SerikBLDCore::Imar::MimariProje::MainProje::onaylamaJulianDay() const
{
    auto val = this->element (keyOnaylamaTarihi);
    if( val ){
        return val.value ().get_int64 ().value;
    }else{
        return -1;
    }
}


const std::string SerikBLDCore::Imar::MimariProje::FileProject::keyFileOid{"fileoid"};
const std::string SerikBLDCore::Imar::MimariProje::FileProject::keyOnay{"onay"};
const std::string SerikBLDCore::Imar::MimariProje::FileProject::keyProjeAdi{"projeAdi"};
SerikBLDCore::Imar::MimariProje::FileProject::FileProject()
    :SerikBLDCore::Item ("")
{

}

SerikBLDCore::Imar::MimariProje::FileProject &SerikBLDCore::Imar::MimariProje::FileProject::setFileOid(const bsoncxx::oid &fileOid)
{
    this->append(keyFileOid,fileOid);
    return *this;
}

SerikBLDCore::Imar::MimariProje::FileProject &SerikBLDCore::Imar::MimariProje::FileProject::setOnay(const bool &onay)
{
    this->append(keyOnay,onay);
    return *this;
}

SerikBLDCore::Imar::MimariProje::FileProject &SerikBLDCore::Imar::MimariProje::FileProject::setProjeAdi(const std::string &projeAdi)
{
    this->append(keyProjeAdi,projeAdi);
    return *this;
}

std::string SerikBLDCore::Imar::MimariProje::FileProject::fileOid() const
{
    auto val = this->element (keyFileOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

bool SerikBLDCore::Imar::MimariProje::FileProject::onay() const
{
    auto val = this->element (keyOnay);
    if( val ){
        return val.value ().get_bool ().value;
    }
    return false;
}

std::string SerikBLDCore::Imar::MimariProje::FileProject::projeAdi() const
{
    auto val = this->element (keyProjeAdi);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }
    return "";
}










const std::string SerikBLDCore::Imar::MimariProje::BaseProject::Collection{"MainBaseProjeler"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyMainProjeOid{"mimariProjeOid"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyProje{"projeFile"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyProjeOnay{"projeOnay"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyAssignPersonelOid{"assignedPersonelOid"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyAssignPersonelName{"assignedPersonelName"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyProjectType{"projectType"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyProjeTitle{"projectTitle"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyOwnerOid{"projectOwnerOid"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyOwnerAdSoyad{"projectOwnerAdSoyad"};
const std::string SerikBLDCore::Imar::MimariProje::BaseProject::keyOwnerTelefon{"projectOwnerTelefon"};

SerikBLDCore::Imar::MimariProje::BaseProject::BaseProject()
    :SerikBLDCore::Item (Collection)
{

}

SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::setProjectType(SerikBLDCore::Imar::MimariProje::BaseProject::ProjectType type)
{
    this->append(keyProjectType,static_cast<std::int32_t>(type));
    return *this;
}

SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::setMainProjeOid(const bsoncxx::oid &mimariOid)
{
    this->append(keyMainProjeOid,mimariOid);
    return *this;
}


SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::setOnay(const bool &onay)
{
    if( onay ){
        if( !this->onaylanabilir () ){
            errorOccured ("Bu Projeyi Onaylanamanız için Proje Dosyalarını Onaylamalısınız!");
            return *this;
        }
    }
    this->append(keyProjeOnay,onay);
    return *this;
}

SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::assignPersonel(const bsoncxx::oid &personelOid, const std::string &personelName)
{
    this->append(keyAssignPersonelOid,personelOid);
    this->append(keyAssignPersonelName,personelName);
    return *this;
}

bool SerikBLDCore::Imar::MimariProje::BaseProject::deAssignPersonel(const bsoncxx::oid &personelOid)
{
    if( assignedPersonelOid () == personelOid.to_string () ){
        this->removeElement (keyAssignPersonelOid);
        this->removeElement (keyAssignPersonelName);
        return true;
    }
    errorOccured ("Bu PersonelOid ile Dokümandaki PersonelOid Aynı Değil");
    return false;
}

SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::addProje(const SerikBLDCore::Imar::MimariProje::FileProject &project)
{
    this->pushArray(keyProje,project.view ());
    return *this;
}

bool SerikBLDCore::Imar::MimariProje::BaseProject::removeProje(const bsoncxx::oid &projectOid)
{
    bool removed = false;
    auto val = this->element (keyProje);
    if( val ){
        auto arr = array{};
        for( auto item : val.value ().get_array ().value ){
            std::cout << "Type: " << bsoncxx::to_string (item.type ()) << " - " << bsoncxx::to_json (item.get_document ().view ()) << std::endl;
            if( projectOid != item.get_document ().view ()[FileProject::keyFileOid].get_oid ().value ){
                arr.append (item.get_document ().view ());
            }
        }
        std::cout << "remove Key Elements" << std::endl;
        this->removeElement (keyProje);
        std::cout << "add new Arr" << std::endl;
        for( auto item : arr.view ()){
            this->pushArray(keyProje,item.get_document ().value);
        }
        std::cout << "removed True" << std::endl;
        removed = true;
    }
    return removed;
}

SerikBLDCore::Imar::MimariProje::BaseProject &SerikBLDCore::Imar::MimariProje::BaseProject::setProjectOwner(const bsoncxx::oid &mtcOid, const std::string &adSoyad, const std::string &telefon)
{
    this->append(keyOwnerOid,mtcOid);
    this->append(keyOwnerAdSoyad,adSoyad);
    this->append(keyOwnerTelefon,telefon);
    return *this;
}



std::string SerikBLDCore::Imar::MimariProje::BaseProject::title() const
{
    auto val = this->element (keyProjeTitle);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }
    return "Bilinmeyen Proje Adı";
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::mainProjectOid() const
{
    auto val = this->element (keyMainProjeOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}



bool SerikBLDCore::Imar::MimariProje::BaseProject::onay() const
{
    auto val = this->element (keyProjeOnay);
    if( val ){
        return val.value ().get_bool ().value;
    }
    return false;
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::assignedPersonelOid() const
{
    auto val = this->element (keyAssignPersonelOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::assignedPersonelName() const
{
    auto val = this->element (keyAssignPersonelName);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string ();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }
    return "";
}

int64_t SerikBLDCore::Imar::MimariProje::BaseProject::projeCount() const
{
    std::int64_t count = 0;
    auto val = this->element (keyProje);
    if( val ){
        count = std::distance(val.value ().get_array ().value.begin (),
                              val.value ().get_array ().value.end ());
    }
    return count;
}



#ifdef Q_CC_MSVC
boost::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::at(const int &index) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        if( index >= this->projeCount () || index < 0 ) return boost::none;
        int counter = 0;
        for( auto item : val.value ().get_array ().value ){
            if( counter == index ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }else{
                counter++;
            }
        }
    }else{
        return boost::none;
    }
    return project;
}

boost::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::at(const bsoncxx::oid &fileoid) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        for( auto item : val.value ().get_array ().value ){
            if( fileoid == item.get_document ().view ()[FileProject::keyFileOid].get_oid ().value ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }
        }
    }else{
        return boost::none;
    }
    return project;
}


boost::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::operator[](const int &index) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        if( index >= this->projeCount () || index < 0 ) return boost::none;
        int counter = 0;
        for( auto item : val.value ().get_array ().value ){
            if( counter == index ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }else{
                counter++;
            }
        }
    }else{
        return boost::none;
    }
    return project;
}

boost::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::operator[](const bsoncxx::oid &fileoid) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        for( auto item : val.value ().get_array ().value ){
            if( fileoid == item.get_document ().view ()[FileProject::keyFileOid].get_oid ().value ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }
        }
    }else{
        return boost::none;
    }
    return project;
}


#endif
#ifdef Q_CC_GNU

std::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::at(const int &index) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        if( index >= this->projeCount () || index < 0 ) return std::nullopt;
        int counter = 0;
        for( auto item : val.value ().get_array ().value ){
            if( counter == index ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }else{
                counter++;
            }
        }
    }else{
        return std::nullopt;
    }
    return project;
}

std::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::at(const bsoncxx::oid &fileoid) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        for( auto item : val.value ().get_array ().value ){
            if( fileoid == item.get_document ().view ()[FileProject::keyFileOid].get_oid ().value ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }
        }
    }else{
        return std::nullopt;
    }
    return project;
}

std::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::operator[](const int &index) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        if( index >= this->projeCount () || index < 0 ) return std::nullopt;
        int counter = 0;
        for( auto item : val.value ().get_array ().value ){
            if( counter == index ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }else{
                counter++;
            }
        }
    }else{
        return std::nullopt;
    }
    return project;
}

std::optional<SerikBLDCore::Imar::MimariProje::FileProject> SerikBLDCore::Imar::MimariProje::BaseProject::operator[](const bsoncxx::oid &fileoid) const
{
    FileProject project;
    auto val = this->element (keyProje);
    if( val ){
        for( auto item : val.value ().get_array ().value ){
            if( fileoid == item.get_document ().view ()[FileProject::keyFileOid].get_oid ().value ){
                project.setDocumentView (item.get_document ().view ());
                break;
            }
        }
    }else{
        return std::nullopt;
    }
    return project;
}


#endif


bool SerikBLDCore::Imar::MimariProje::BaseProject::onaylanabilir() const
{
    bool _onaylanabilir = true;
    for( auto i = 0 ; i < this->projeCount () ; i++ ){
        auto fileProje = this->at (i);
        if( fileProje ){
            if( !fileProje->onay () ){
                _onaylanabilir = false;
            }
        }
    }
    return _onaylanabilir;
}

SerikBLDCore::Imar::MimariProje::BaseProject::ProjectType SerikBLDCore::Imar::MimariProje::BaseProject::type() const
{
    auto val = this->element (keyProjectType);
    if( val ){
        return static_cast<ProjectType>(val->get_int32 ().value);
    }
    return ProjectType::Bilinmiyor;
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::ownerOid() const
{
    auto val = this->element (keyOwnerOid);
    if( val ){
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::ownerAdSoyad() const
{
    auto val = this->element (keyOwnerAdSoyad);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }
    return "";
}

std::string SerikBLDCore::Imar::MimariProje::BaseProject::ownerTelefon() const
{
    auto val = this->element (keyOwnerTelefon);
    if( val ){
#ifdef Q_CC_MSVC
        return val.value ().get_utf8 ().value.to_string();
#endif
#ifdef Q_CC_GNU
        return val.value ().get_utf8 ().value.data ();
#endif
    }
    return "";
}


SerikBLDCore::Imar::MimariProje::MimariProje SerikBLDCore::Imar::MimariProje::BaseProject::toMimariProje()
{
    MimariProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::StatikProje SerikBLDCore::Imar::MimariProje::BaseProject::toStatikProje()
{
    StatikProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::ElektrikProje SerikBLDCore::Imar::MimariProje::BaseProject::toElectricProje()
{
    ElektrikProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::MechanicProje SerikBLDCore::Imar::MimariProje::BaseProject::toMechanicProjec()
{
    MechanicProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::RuhsatProje SerikBLDCore::Imar::MimariProje::BaseProject::toRuhsat()
{
    RuhsatProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::IskeleProje SerikBLDCore::Imar::MimariProje::BaseProject::toIskele()
{
    IskeleProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::IskanProje SerikBLDCore::Imar::MimariProje::BaseProject::toIskan()
{
    IskanProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::ZeminEtudu SerikBLDCore::Imar::MimariProje::BaseProject::toZeminEtudu()
{
    ZeminEtudu proje;
    proje.setDocumentView (this->view ());
    return proje;
}

SerikBLDCore::Imar::MimariProje::AsansorProje SerikBLDCore::Imar::MimariProje::BaseProject::toAsansor()
{
    AsansorProje proje;
    proje.setDocumentView (this->view ());
    return proje;
}






SerikBLDCore::Imar::MimariProje::MimariProje::MimariProje()
{
    this->setProjectType (ProjectType::Mimari);
    this->append(keyProjeTitle,"Mimari");
}

std::string SerikBLDCore::Imar::MimariProje::MimariProje::iconPath() const
{
    return "icon/dwgicon.png";
}










SerikBLDCore::Imar::MimariProje::StatikProje::StatikProje()
{
    this->setProjectType (ProjectType::Statik);
    this->append(keyProjeTitle,"Statik");
}



std::string SerikBLDCore::Imar::MimariProje::StatikProje::iconPath() const
{
    return "icon/staticicon.png";
}




SerikBLDCore::Imar::MimariProje::ElektrikProje::ElektrikProje()
{
    this->setProjectType (ProjectType::Elektrik);
    this->append(keyProjeTitle,"Elektrik");
}

std::string SerikBLDCore::Imar::MimariProje::ElektrikProje::iconPath() const
{
    return "icon/elektrikicon.png";
}

SerikBLDCore::Imar::MimariProje::MechanicProje::MechanicProje()
{
    this->setProjectType (ProjectType::Mekanik);
    this->append(keyProjeTitle,"Mekanik");
}

std::string SerikBLDCore::Imar::MimariProje::MechanicProje::iconPath() const
{
    return "icon/mechanicicon.png";
}

SerikBLDCore::Imar::MimariProje::RuhsatProje::RuhsatProje()
{
    this->setProjectType (ProjectType::Ruhsat);
    this->append(keyProjeTitle,"Ruhsat");
}

std::string SerikBLDCore::Imar::MimariProje::RuhsatProje::iconPath() const
{
    return "icon/ruhsat.png";
}

SerikBLDCore::Imar::MimariProje::IskeleProje::IskeleProje()
{
    this->setProjectType (ProjectType::Iskele);
    this->append(keyProjeTitle,"İskele");
}

std::string SerikBLDCore::Imar::MimariProje::IskeleProje::iconPath() const
{
    return "icon/iskele.png";
}

SerikBLDCore::Imar::MimariProje::ZeminEtudu::ZeminEtudu()
{
    this->setProjectType (ProjectType::ZeminEtudu);
    this->append(keyProjeTitle,"Zemin Etüdü");
}

std::string SerikBLDCore::Imar::MimariProje::ZeminEtudu::iconPath() const
{
    return "icon/zeminetudu.png";
}

SerikBLDCore::Imar::MimariProje::AsansorProje::AsansorProje()
{
    this->setProjectType (ProjectType::Asansor);
    this->append(keyProjeTitle,"Asansör");
}

std::string SerikBLDCore::Imar::MimariProje::AsansorProje::iconPath() const
{
    return "icon/asansor.png";
}

SerikBLDCore::Imar::MimariProje::IskanProje::IskanProje()
{
    this->setProjectType (ProjectType::Iskan);
    this->append(keyProjeTitle,"İskan");
}

std::string SerikBLDCore::Imar::MimariProje::IskanProje::iconPath() const
{
    return "icon/iskan.png";

}
