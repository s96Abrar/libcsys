/*
An Library for CoreApps .

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

#ifndef CPUINFO_H
#define CPUINFO_H

#include <QDebug>
#include <QVector>

#include "file_util.h"
#include "libcsys_global.h"

//#define PROC_CPUINFO "/proc/cpuinfo"
//#define PROC_LOADAVG "/proc/loadavg"
//#define PROC_STAT    "/proc/stat"

const QString PROC_CPUINFO = "/proc/cpuinfo";
const QString PROC_LOADAVG = "/proc/loadavg";
const QString PROC_STAT    = "/proc/stat";

class LIBCSYSSHARED_EXPORT CpuInfo
{
public:
    quint8 getCpuCoreCount() const;
    QList<int> getCpuPercents() const;
    QList<double> getLoadAvgs() const;

private:
    int getCpuPercent(const QList<double> &cpuTimes, const int &processor = 0) const;
};

#endif // CPUINFO_H
