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

#ifndef UPOWER_H
#define UPOWER_H

#include <QMap>
#include "libcsys_global.h"

class Battery;
class QtDBus;
class QDBusObjectPath;
class QDBusInterface;
class QDBusServiceWatcher;

class LIBCSYSSHARED_EXPORT UPower : public QObject {
    Q_OBJECT
    Q_CLASSINFO( "author", "Brieuc ROBLIN" )
    Q_CLASSINFO( "url", "http://pt.pyrotools.org/" )

public:
    UPower( QObject *parent = nullptr );
    ~UPower();

    int numberOfBattery() const;
    const QMap<QString, Battery *> *batteries() const;
    const QString version() const;

    bool isAvailable() const;
    bool isOnBattery() const;
    bool isLowBattery() const;
    bool isLidClosed() const;
    bool isLidPresent() const;

    bool systemCanSuspend() const;
    bool systemCanHibernate() const;
    bool systemCanReboot() const;
    bool systemCanHalt() const;

private:
    void createDBusWatcher();
    bool addBattery( Battery *battery );
    void removeBattery( Battery *battery );

    bool                    m_available;
    QDBusInterface          *m_interface;
    QDBusServiceWatcher     *m_watcher;
    QMap<QString, Battery *> *m_batteries;

    static const QString m_consolkit_interface;
    static const QString m_consolkit_path;
    static const QString m_upower_interface;
    static const QString m_upower_path;

public Q_SLOTS:
    void suspendSystem();
    void hibernateSystem();
    void rebootSystem() const;
    void haltSystem() const;

    Battery *battery( const QString &path ) const;

private Q_SLOTS:
    void createDBusInterface();
    void clearBattery();

    bool addBattery( const QDBusObjectPath &path );
    void removeBattery( const QDBusObjectPath &path );
    void refreshBatteries();

Q_SIGNALS:
    /* UPower */
    void available();
    void unavailable();

    /* Success & Fail messages */
    void systemSuspend( bool );
    void systemHibernate( bool );
    void systemReboot( bool );
    void systemHalt( bool );

    /* Battery notifications */
    void batteryConnected( Battery * );
    void batteryConnected( const QString & );
    void batteryDisconnected( Battery * );
    void batteryDisconnected( const QString & );
};

#endif
