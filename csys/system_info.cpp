/*
A Library for CoreApps .

This file is part of libcsys.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "system_info.h"
#include "file_util.h"
#include "format_util.h"
#include "command_util.h"
#include "cpu_info.h"

#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>

SystemInfo::SystemInfo()
{
    QStringList lines = FileUtil::readListFromFile( PROC_CPUINFO )
                        .filter( QRegExp( "^model name" ) );

    QString unknown( QObject::tr( "Unknown" ) );

    if ( ! lines.isEmpty() ) {
        QRegExp regexp( "\\s+" );
        QString space( " " );

        QStringList model = lines.first().split( ":" );

        if ( model.last().contains( '@' ) ) { // intel
            model = model.last().split( "@" );

            if ( model.count() > 1 ) {
                this->cpuModel = model.first().trimmed().replace( regexp, space );
                this->cpuSpeed = model.last().trimmed().replace( regexp, space );
            }
        } else { // AMD
            this->cpuModel = model.last();
            this->cpuSpeed = unknown;
        }
    } else {
        this->cpuModel = unknown;
        this->cpuSpeed = unknown;
    }

    CpuInfo ci;
    this->cpuCore = QString::number( ci.getCpuCoreCount() );

    // get username
    QString name = qgetenv( "USER" );

    if ( name.isEmpty() ) {
        name = qgetenv( "USERNAME" );
    }

    try {
        if ( name.isEmpty() ) {
            name = CommandUtil::exec( "whoami" ).trimmed();
        }
    } catch ( const QString &ex ) {
        qCritical() << ex;
    }

    this->username = name;
}

QString SystemInfo::getUsername() const
{
    return username;
}

QString SystemInfo::getHostname() const
{
    return QSysInfo::machineHostName();
}

QString SystemInfo::getPlatform() const
{
    return QString( "%1 %2" )
           .arg( QSysInfo::kernelType() )
           .arg( QSysInfo::currentCpuArchitecture() );
}

QString SystemInfo::getDistribution() const
{
    return QSysInfo::prettyProductName();
}

QString SystemInfo::getKernel() const
{
    return QSysInfo::kernelVersion();
}

QString SystemInfo::getCpuModel() const
{
    return this->cpuModel;
}

QString SystemInfo::getCpuSpeed() const
{
    return this->cpuSpeed;
}

QString SystemInfo::getCpuCore() const
{
    return this->cpuCore;
}

QFileInfoList SystemInfo::getCrashReports() const
{
    QDir reports( "/var/crash" );

    return reports.entryInfoList( QDir::Files );
}

QFileInfoList SystemInfo::getAppLogs() const
{
    QDir logs( "/var/log" );

    return logs.entryInfoList( QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot );
}

QFileInfoList SystemInfo::getAppCaches() const
{
    QString homePath = QStandardPaths::writableLocation( QStandardPaths::HomeLocation );
    QDir caches( homePath + "/.cache" );

    return caches.entryInfoList( QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot );
}
