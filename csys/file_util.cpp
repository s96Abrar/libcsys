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

#include "file_util.h"


FileUtil::FileUtil()
{

}

QString FileUtil::readStringFromFile(const QString &path, const QIODevice::OpenMode &mode)
{
    QSharedPointer<QFile> file(new QFile(path));

    QString data;

    if(file->open(mode)) {

      data = file->readAll();

      file->close();
    }

    return data;
}

QStringList FileUtil::readListFromFile(const QString &path, const QIODevice::OpenMode &mode)
{
    QStringList list = FileUtil::readStringFromFile(path, mode).trimmed().split("\n");

    return list;
}

bool FileUtil::writeFile(const QString &path, const QString &content, const QIODevice::OpenMode &mode)
{
    QFile file(path);

    if(file.open(mode))
    {
        QTextStream stream(&file);
        stream << content.toUtf8() << endl;

        file.close();

        return true;
    }

    return false;
}

QStringList FileUtil::directoryList(const QString &path)
{
    QDir dir(path);

    QStringList list;

    for (const QFileInfo &info : dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files))
        list << info.fileName();

    return list;
}

quint64 FileUtil::getFileSize(const QString &path)
{
    quint64 totalSize = 0;

    QFileInfo info(path);

    if (info.exists())
    {
        if (info.isFile()) {
            totalSize += static_cast<quint64>(info.size());
        }
        else if (info.isDir()) {

            QDir dir(path);

            for (const QFileInfo &i : dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs)) {
                totalSize += getFileSize(i.absoluteFilePath());
            }
        }
    }

    return totalSize;
}


