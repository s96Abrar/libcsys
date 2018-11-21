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

#ifndef COMMAND_UTIL_H
#define COMMAND_UTIL_H

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT CommandUtil {
public:
    static QString sudoExec( const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray() );
    static QString exec( const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray() );
    static bool isExecutable( const QString &cmd );
};

#endif // COMMAND_UTIL_H
