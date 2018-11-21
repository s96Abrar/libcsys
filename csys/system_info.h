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

#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <QFileInfoList>
#include "libcsys_global.h"

//#define PROC_CPUINFO "/proc/cpuinfo"
//const QString PROC_CPUINFO = "/proc/cpuinfo";

class LIBCSYSSHARED_EXPORT SystemInfo {
public:
    SystemInfo();

    QString getHostname() const;
    QString getPlatform() const;
    QString getDistribution() const;
    QString getKernel() const;
    QString getCpuModel() const;
    QString getCpuSpeed() const;
    QString getCpuCore() const;
    QString getUsername() const;

    QFileInfoList getCrashReports() const;
    QFileInfoList getAppLogs() const;
    QFileInfoList getAppCaches() const;

private:
    QString cpuCore;
    QString cpuModel;
    QString cpuSpeed;
    QString username;
};

#endif // SYSTEMINFO_H
