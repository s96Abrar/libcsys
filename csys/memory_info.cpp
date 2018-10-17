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

#include "memory_info.h"


MemoryInfo::MemoryInfo():
    memTotal(0),
    memFree(0),
    memUsed(0)
{ }

/* https://access.redhat.com/solutions/406773
 *
 * https://stackoverflow.com/questions/41224738/
 *   Total used memory = MemTotal - MemFree
 *   Non cache/buffer memory (green) = Total used memory - (Buffers + Cached memory)
 *   Buffers (blue) = Buffers
 *   Cached memory (yellow) = Cached + SReclaimable - Shmem
 *   Swap = SwapTotal - SwapFree
*/
void MemoryInfo::updateMemoryInfo()
{
    QStringList lines = FileUtil::readListFromFile(PROC_MEMINFO)
            .filter(QRegExp("^MemTotal|^MemFree|^Buffers|^Cached|^SwapTotal|^SwapFree|^Shmem|^SReclaimable"));
    QRegExp sep("\\s+");

#define getValue(l) static_cast<quint64>(lines.at(l).split(sep).at(1).toLong()) << 10;
    memTotal = getValue(0);
    memFree = getValue(1);
    buffers = getValue(2);
    cached = getValue(3);
    swapTotal = getValue(4);
    swapFree = getValue(5);
    sreclaimable = getValue(6);
    shmem = getValue(7);
#undef getValue

    cached = (cached + sreclaimable - shmem);
    memUsed = (memTotal - (memFree + buffers + cached));
    swapUsed = (swapTotal - swapFree);
}

quint64 MemoryInfo::getSwapUsed() const
{
    return swapUsed;
}

quint64 MemoryInfo::getSwapFree() const
{
    return swapFree;
}

quint64 MemoryInfo::getSwapTotal() const
{
    return swapTotal;
}

quint64 MemoryInfo::getMemUsed() const
{
    return memUsed;
}

quint64 MemoryInfo::getMemFree() const
{
    return memFree;
}

quint64 MemoryInfo::getMemTotal() const
{
    return memTotal;
}
