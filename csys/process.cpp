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

#include "process.h"


pid_t Process::getPid() const
{
    return pid;
}

void Process::setPid(const pid_t &value)
{
    pid = value;
}

quint64 Process::getRss() const
{
    return rss;
}

void Process::setRss(const quint64 &value)
{
    rss = value;
}

double Process::getPmem() const
{
    return pmem;
}

void Process::setPmem(const double &value)
{
    pmem = value;
}

quint64 Process::getVsize() const
{
    return vsize;
}

void Process::setVsize(const quint64 &value)
{
    vsize = value;
}

QString Process::getUname() const
{
    return uname;
}

void Process::setUname(const QString &value)
{
    uname = value;
}

double Process::getPcpu() const
{
    return pcpu;
}

void Process::setPcpu(const double &value)
{
    pcpu = value;
}

QString Process::getCmd() const
{
    return cmd;
}

void Process::setCmd(const QString &value)
{
    cmd = value;
}

QString Process::getStartTime() const
{
    return startTime;
}

void Process::setStartTime(const QString &value)
{
    startTime = value;
}

QString Process::getState() const
{
    return state;
}

void Process::setState(const QString &value)
{
    state = value;
}

QString Process::getGroup() const
{
    return group;
}

void Process::setGroup(const QString &value)
{
    group = value;
}

int Process::getNice() const
{
    return nice;
}

void Process::setNice(const int &value)
{
    nice = value;
}

QString Process::getCpuTime() const
{
    return cpuTime;
}

void Process::setCpuTime(const QString &value)
{
    cpuTime = value;
}

QString Process::getSession() const
{
    return session;
}

void Process::setSession(const QString &value)
{
    session = value;
}
