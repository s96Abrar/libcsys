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

#ifndef MEMORYINFO_H
#define MEMORYINFO_H

#include "file_util.h"

#include <QDebug>

//#define PROC_MEMINFO "/proc/meminfo"

const QString PROC_MEMINFO = "/proc/meminfo";

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT MemoryInfo
{
public:
    MemoryInfo();

    void updateMemoryInfo();

    quint64 getMemTotal() const;
    quint64 getMemFree() const;
    quint64 getMemUsed() const;

    quint64 getSwapTotal() const;
    quint64 getSwapFree() const;
    quint64 getSwapUsed() const;

private:
    // memory
    quint64 memTotal;
    quint64 memFree;
    quint64 memUsed;
    quint64 buffers;
    quint64 cached;
    quint64 sreclaimable;
    quint64 shmem;

    // swap
    quint64 swapTotal;
    quint64 swapFree;
    quint64 swapUsed;
};

#endif // MEMORYINFO_H
