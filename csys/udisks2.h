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
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#ifndef UDISKS2_H
#define UDISKS2_H

#include "libcsys_global.h"

class QDBusObjectPath;
class QDBusInterface;
//class QDBusReply;
class QDBusConnection;
class QXmlStreamReader;

class UDisks2Block;
class UDisks2Drive;
class UDisks2Filesystem;

class LIBCSYSSHARED_EXPORT UDisks2 : public QObject {
    Q_OBJECT

public:
    explicit UDisks2( QObject *parent = nullptr );
    ~UDisks2();

    QStringList blockDevices();
    UDisks2Block *blockDevice( const QString &node );

    QStringList drives();
    UDisks2Drive *drive( const QString &node );

signals:
    void deviceInformationChanged( QString node, QVariantMap info );
    void driveAdded( const QString &node );
    void driveRemoved( const QString &node );
    void driveChanged( const QString &node );
    void blockDeviceAdded( const QString &node );
    void blockDeviceRemoved( const QString &node );
    void blockDeviceChanged( const QString &node );
    void filesystemAdded( const QString &node );
    void filesystemRemoved( const QString &node );
    void filesystemChanged( const QString &node );

private:
    void addDrive( const QString &node );
    void addBlock( const QString &node );
    void removeDrive( const QString &node );
    void removeBlock( const QString &node );

    QMap<QString, UDisks2Drive *> drives_;
    QMap<QString, UDisks2Block *> blocks_;

private slots:
    void dbus_interfaceAdded( const QDBusObjectPath &path, const QMap<QString, QVariant> &interfaces );
    void dbus_interfaceRemoved( const QDBusObjectPath &path, const QStringList &interfaces );
};

class LIBCSYSSHARED_EXPORT UDisks2Block : public QObject {
    Q_OBJECT
public:
    explicit UDisks2Block( const QString &node, QObject *parent = nullptr );

public:
    QString name;
    QString dev;
    QString id;
    QString drive;
    qulonglong size;
    bool readonly;
    QString usage;
    QString type;
    QString toString();
    QString toStringToSeperate( int i );

    void update();
    void updateFilesystem();
    void addFilesystem();
    void removeFilesystem();
    UDisks2Filesystem *fileSystem();

signals:
    void filesystemAdded( const QString &node );
    void filesystemRemoved( const QString &node );
    void filesystemChanged( const QString &node );
    void changed( const QString &node );

private slots:
    void self_propertiesChanged( const QString &interface, const QVariantMap &changedProp, const QStringList &invalidatedProp );

private:
    QDBusInterface *dbus;
    UDisks2Filesystem *fs;
};

class LIBCSYSSHARED_EXPORT UDisks2Filesystem : public QObject {
    Q_OBJECT
public:
    UDisks2Filesystem( const QString &node, QObject *parent = nullptr );
    QStringList mountPoints() const;
    QString mount();
    void unmount();
    void update();
    bool isValid();
    QString name;

private:
    QDBusInterface *dbus;
    QDBusInterface *dbusProp;
    QStringList mountPoints_;
};

class LIBCSYSSHARED_EXPORT UDisks2Drive : public QObject {
    Q_OBJECT
public:
    explicit UDisks2Drive( const QString &node, QObject *parent = nullptr );

    QString name;
    quint64 size;
    QString vendor;
    QString model;
    QString serial;
    QString id;
    QString media;
    bool optical;
    bool removable;
    bool available;
    QString toString();
    QString toStringToSeperate( int i );

    void update();

signals:
    void changed( const QString &node );

private slots:
    void self_propertiesChanged( const QString &interface, const QVariantMap &changed, const QStringList &invalidated );

private:
    QDBusInterface *dbus;

};


#endif // UDISKS2_H
