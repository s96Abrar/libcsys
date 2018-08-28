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

#include "cpu_info.h"


quint8 CpuInfo::getCpuCoreCount() const
{
    static quint8 count = 0;

    if (! count) {
        QStringList cpuinfo = FileUtil::readListFromFile(PROC_CPUINFO);

        if (! cpuinfo.isEmpty())
            count = cpuinfo.filter(QRegExp("^processor")).count();
    }

    return count;
}

QList<double> CpuInfo::getLoadAvgs() const
{
    QList<double> avgs = {0, 0, 0};

    QStringList strListAvgs = FileUtil::readStringFromFile(PROC_LOADAVG).split(QRegExp("\\s+"));

    if (strListAvgs.count() > 2) {
        avgs.clear();
        avgs << strListAvgs.takeFirst().toDouble();
        avgs << strListAvgs.takeFirst().toDouble();
        avgs << strListAvgs.takeFirst().toDouble();
    }

    return avgs;
}

QList<int> CpuInfo::getCpuPercents() const
{
    QList<double> cpuTimes;

    QList<int> cpuPercents;

    QStringList times = FileUtil::readListFromFile(PROC_STAT);

    if (! times.isEmpty())
    {
     /*  user nice system idle iowait  irq  softirq steal guest guest_nice
        cpu  4705 356  584    3699   23    23     0       0     0      0
         .
        cpuN 4705 356  584    3699   23    23     0       0     0      0

          The meanings of the columns are as follows, from left to right:
             - user: normal processes executing in user mode
             - nice: niced processes executing in user mode
             - system: processes executing in kernel mode
             - idle: twiddling thumbs
             - iowait: waiting for I/O to complete
             - irq: servicing interrupts
             - softirq: servicing softirqs
             - steal: involuntary wait
             - guest: running a normal guest
             - guest_nice: running a niced guest
        */

        QRegExp sep("\\s+");
        int count = CpuInfo::getCpuCoreCount() + 1;
        for (int i = 0; i < count; ++i)
        {
            QStringList n_times = times.at(i).split(sep);
            n_times.removeFirst();
            for (const QString &t : n_times)
                cpuTimes << t.toDouble();

            cpuPercents << getCpuPercent(cpuTimes, i);

            cpuTimes.clear();
        }
    }

    return cpuPercents;
}

int CpuInfo::getCpuPercent(const QList<double> &cpuTimes, const int &processor) const
{
    const int N = getCpuCoreCount()+1;

    static QVector<double> l_idles(N);
    static QVector<double> l_totals(N);

    int utilisation = 0;

    if (cpuTimes.count() > 0) {

        double idle = cpuTimes.at(3) + cpuTimes.at(4); // get (idle + iowait)
        double total = 0.0;
        for (const double &t : cpuTimes) total += t; // get total time

        double idle_delta  = idle  - l_idles[processor];
        double total_delta = total - l_totals[processor];

        if (static_cast<int>(total_delta))
            utilisation = 100 * ((static_cast<int>(total_delta) - static_cast<int>(idle_delta)) / static_cast<int>(total_delta));

        l_idles[processor] = idle;
        l_totals[processor] = total;
    }

    if (utilisation > 100) utilisation = 100;
    else if (utilisation < 0) utilisation = 0;

    return utilisation;
}
