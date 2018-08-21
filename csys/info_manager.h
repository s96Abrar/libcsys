#ifndef INFO_MANAGER_H
#define INFO_MANAGER_H

#include <QObject>

#include "cpu_info.h"
#include "disk_info.h"
#include "memory_info.h"
#include "network_info.h"
#include "system_info.h"
#include "process_info.h"

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT InfoManager
{

public:
    static InfoManager *ins();

    quint8 getCpuCoreCount() const;
    QList<int> getCpuPercents() const;
    QList<double> getCpuLoadAvgs() const;

    quint64 getSwapUsed() const;
    quint64 getSwapTotal() const;
    quint64 getMemUsed() const;
    quint64 getMemTotal() const;
    void updateMemoryInfo();

    quint64 getRXbytes() const;
    quint64 getTXbytes() const;

    QList<Disk*> getDisks() const;
    QList<quint64> getDiskIO();
    void updateDiskInfo();

    QFileInfoList getCrashReports() const;
    QFileInfoList getAppLogs() const;
    QFileInfoList getAppCaches() const;

    void updateProcesses();
    QList<Process> getProcesses() const;
    QString getUserName() const;

private:
    CpuInfo ci;
    DiskInfo di;
    MemoryInfo mi;
    NetworkInfo ni;
    SystemInfo si;
    ProcessInfo pi;

    static InfoManager *instance;

};

#endif // INFO_MANAGER_H
