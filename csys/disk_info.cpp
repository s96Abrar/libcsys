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

#include "disk_info.h"


QList<Disk *> DiskInfo::getDisks() const
{
    QList<Disk*> lists;
    lists.clear();

    QList<QStorageInfo> storageInfoList = QStorageInfo::mountedVolumes();

    for(const QStorageInfo &info: storageInfoList) {
        Disk *disk = new Disk;
        disk->name = info.displayName();
        disk->device = info.device();
        disk->size = static_cast<quint64>(info.bytesTotal());
        disk->used = static_cast<quint64>(info.bytesTotal()) - static_cast<quint64>(info.bytesFree());
        disk->free = static_cast<quint64>(info.bytesFree());

        lists << disk;
    }

    return lists;
}

void DiskInfo::updateDiskInfo()
{
    getDisks();
}

QList<quint64> DiskInfo::getDiskIO() const
{
    static QString diskName = getDiskName();

    QList<quint64> diskReadWrite;

    QStringList diskStat = FileUtil::readStringFromFile(QString("/sys/block/%1/stat").arg(diskName))
            .trimmed()
            .split(QRegExp("\\s+"));

    if (diskStat.count() > 7) {
        diskReadWrite.append(static_cast<unsigned long long>(diskStat.at(2).toLongLong()) * 512);
        diskReadWrite.append(static_cast<unsigned long long>(diskStat.at(6).toLongLong()) * 512);
    }

    return diskReadWrite;
}

QString DiskInfo::getDiskName() const
{
    QDir blocks("/sys/block");

    for (const QFileInfo& entryInfo : blocks.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot)) {
        if (QFile::exists(QString("%1/device").arg(entryInfo.absoluteFilePath()))) {
            return entryInfo.baseName();
        }
    }
    return QString();
}
