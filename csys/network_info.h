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

#ifndef NETWORK_INFO_H
#define NETWORK_INFO_H

#include "libcsys_global.h"

class QNetworkInterface;

class LIBCSYSSHARED_EXPORT NetworkInfo {
public:
    NetworkInfo();

    QString getDefaultNetworkInterface() const;
    QList<QNetworkInterface> getAllInterfaces();

    quint64 getRXbytes() const;
    quint64 getTXbytes() const;

private:
    QString defaultNetworkInterface;

    QString rxPath;
    QString txPath;
};

#endif // NETWORK_INFO_H
