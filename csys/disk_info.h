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
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA*/

#ifndef DISKINFO_H
#define DISKINFO_H

#include "command_util.h"
#include "file_util.h"
#include "libcsys_global.h"

#include <QStorageInfo>
#include <QString>


#define PROC_MOUNTS "/proc/mounts"

class Disk;

class LIBCSYSSHARED_EXPORT DiskInfo
{
public:
    QList<Disk *> getDisks() const;
    void updateDiskInfo();
    QList<quint64> getDiskIO() const;
    QString getDiskName() const;

private:

};

class Disk {
public:
    QString name;
    QString device;
    quint64 size;
    quint64 free;
    quint64 used;
};


#endif // DISKINFO_H
