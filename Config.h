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


#endif // CONFIG_H
