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

#include "network_info.h"

NetworkInfo::NetworkInfo()
{
    for (const QNetworkInterface &net: QNetworkInterface::allInterfaces()) {
        if ((net.flags()  & QNetworkInterface::IsUp) &&
            (net.flags()  & QNetworkInterface::IsRunning) &&
            !(net.flags() & QNetworkInterface::IsLoopBack))
        {
            defaultNetworkInterface = net.name();
            break;
        }
    }

    rxPath = QString("/sys/class/net/%1/statistics/rx_bytes").arg(defaultNetworkInterface);
    txPath = QString("/sys/class/net/%1/statistics/tx_bytes").arg(defaultNetworkInterface);
}

QList<QNetworkInterface> NetworkInfo::getAllInterfaces()
{
    return QNetworkInterface::allInterfaces();
}

QString NetworkInfo::getDefaultNetworkInterface() const
{
    return defaultNetworkInterface;
}

quint64 NetworkInfo::getRXbytes() const
{
    quint64 rx = static_cast<quint64>(FileUtil::readStringFromFile(rxPath).trimmed().toLong());

    return rx;
}

quint64 NetworkInfo::getTXbytes() const
{
    quint64 tx = static_cast<quint64>(FileUtil::readStringFromFile(txPath).trimmed().toLong());

    return tx;
}
