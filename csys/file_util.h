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

#ifndef FILEUTIL_H
#define FILEUTIL_H

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT FileUtil {
public:
    static QString readStringFromFile( const QString &path, const QIODevice::OpenMode &mode = QIODevice::ReadOnly );
    static QStringList readListFromFile( const QString &path, const QIODevice::OpenMode &mode = QIODevice::ReadOnly );

    static bool writeFile( const QString &path, const QString &content, const QIODevice::OpenMode &mode = QIODevice::WriteOnly | QIODevice::Truncate );
    static QStringList directoryList( const QString &path );
    static quint64 getFileSize( const QString &path );

};

#endif // FILEUTIL_H
