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

#ifndef INFO_MANAGER_H
#define INFO_MANAGER_H

#include <QObject>

#include "cpu_info.h"
#include "disk_info.h"
#include "memory_info.h"
#include "network_info.h"
#include "system_info.h"
#include "process_info.h"

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT InfoManager
{

public:
    static InfoManager *ins();

    quint8 getCpuCoreCount() const;
    QList<int> getCpuPercents() const;
    QList<double> getCpuLoadAvgs() const;

    quint64 getSwapUsed() const;
    quint64 getSwapTotal() const;
    quint64 getMemUsed() const;
    quint64 getMemTotal() const;
    void updateMemoryInfo();

    quint64 getRXbytes() const;
    quint64 getTXbytes() const;

    QList<Disk*> getDisks() const;
    QList<quint64> getDiskIO();
    void updateDiskInfo();

    QFileInfoList getCrashReports() const;
    QFileInfoList getAppLogs() const;
    QFileInfoList getAppCaches() const;

    void updateProcesses();
    QList<Process> getProcesses() const;
    QString getUserName() const;

private:
    CpuInfo ci;
    DiskInfo di;
    MemoryInfo mi;
    NetworkInfo ni;
    SystemInfo si;
    ProcessInfo pi;

    static InfoManager *instance;

};

#endif // INFO_MANAGER_H
