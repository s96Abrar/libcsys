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

#ifndef PROCESS_H
#define PROCESS_H

#include "file_util.h"

#include "libcsys_global.h"


class LIBCSYSSHARED_EXPORT Process {

public:
    pid_t getPid() const;
    void setPid(const pid_t &value);

    quint64 getRss() const;
    void setRss(const quint64 &value);

    double getPmem() const;
    void setPmem(const double &value);

    quint64 getVsize() const;
    void setVsize(const quint64 &value);

    QString getUname() const;
    void setUname(const QString &value);

    double getPcpu() const;
    void setPcpu(const double &value);

    QString getStartTime() const;
    void setStartTime(const QString &value);

    QString getState() const;
    void setState(const QString &value);

    QString getGroup() const;
    void setGroup(const QString &value);

    int getNice() const;
    void setNice(const int &value);

    QString getCpuTime() const;
    void setCpuTime(const QString &value);

    QString getSession() const;
    void setSession(const QString &value);

    QString getCmd() const;
    void setCmd(const QString &value);

private:
    pid_t pid;
    quint64 rss;
    double pmem;
    quint64 vsize;
    QString uname;
    double pcpu;
    QString startTime;
    QString state;
    QString group;
    int nice;
    QString cpuTime;
    QString session;
    QString cmd;
};


#endif // PROCESS_H
