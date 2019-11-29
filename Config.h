#ifndef CONFIG_H
#define CONFIG_H



#include <QtGlobal>
#include <QString>
#include <QVector>
#include <QMetaEnum>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
//#ifdef Q_OS_WIN
//#define MOBILE



//#endif


#define MAKE_STRINGS(VAR) #VAR



//////////////////////////////////
// CHECK PLATFORM
#ifdef Q_OS_WIN
#define DESKTOP
#endif





#ifdef Q_OS_LINUX
#define DESKTOP
#endif

#ifdef Q_OS_MACOS
#define DESKTOP
#endif


#ifdef Q_OS_IOS
#define MOBILE
#endif


#ifdef Q_OS_ANDROID
#define MOBILE
#endif
//END CHECK PLATFORM
//////////////////////////////////


namespace SerikBLDCore {

namespace BilgiEdinme {
namespace Key {
static const std::string GeriDonus{"geriDonus"};
static const std::string JulianDay{"julianDay"};
static const std::string TCOid{"TCOid"};
static const std::string Konu{"Konu"};
static const std::string Mesaj{"Mesaj"};
static const std::string Birim{"Birim"};
static const std::string CevapOid{"CevapOid"};
}
}

}
















#endif // CONFIG_H
