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

#include "info_manager.h"

InfoManager *InfoManager::instance = nullptr;

InfoManager *InfoManager::ins()
{
    if(! instance){
        instance = new InfoManager;
    }

    return instance;
}

QString InfoManager::getUserName() const
{
    return si.getUsername();
}

/*
 * CPU Provider
 */
quint8 InfoManager::getCpuCoreCount() const
{
    return ci.getCpuCoreCount();
}

QList<int> InfoManager::getCpuPercents() const
{
    return ci.getCpuPercents();
}

QList<double> InfoManager::getCpuLoadAvgs() const
{
    return ci.getLoadAvgs();
}

/*
 * Memory Provider
 */
void InfoManager::updateMemoryInfo()
{
    mi.updateMemoryInfo();
}

quint64 InfoManager::getSwapUsed() const
{
    return mi.getSwapUsed();
}

quint64 InfoManager::getSwapTotal() const
{
    return mi.getSwapTotal();
}

quint64 InfoManager::getMemUsed() const
{
    return mi.getMemUsed();
}

quint64 InfoManager::getMemTotal() const
{
    return mi.getMemTotal();
}

/*
 * Disk Provider
 */
QList<Disk *> InfoManager::getDisks() const
{
    return di.getDisks();
}

void InfoManager::updateDiskInfo()
{
    di.updateDiskInfo();
}

QList<quint64> InfoManager::getDiskIO()
{
    return di.getDiskIO();
}

/********************
 * Network Provider
 *******************/
quint64 InfoManager::getRXbytes() const
{
    return ni.getRXbytes();
}

quint64 InfoManager::getTXbytes() const
{
    return ni.getTXbytes();
}

/********************
 * System Provider
 *******************/
QFileInfoList InfoManager::getCrashReports() const
{
    return si.getCrashReports();
}

QFileInfoList InfoManager::getAppLogs() const
{
    return si.getAppLogs();
}

QFileInfoList InfoManager::getAppCaches() const
{
    return si.getAppCaches();
}

/********************
 * Process Provider
 *******************/
void InfoManager::updateProcesses()
{
    pi.updateProcesses();
}

QList<Process> InfoManager::getProcesses() const
{
    return pi.getProcessList();
}


