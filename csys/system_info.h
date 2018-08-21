#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include "file_util.h"
#include "format_util.h"
#include "command_util.h"
#include "cpu_info.h"

#define PROC_CPUINFO "/proc/cpuinfo"

#include "libcsys_global.h"

class LIBCSYSSHARED_EXPORT SystemInfo
{
public:
    SystemInfo();

    QString getHostname() const;
    QString getPlatform() const;
    QString getDistribution() const;
    QString getKernel() const;
    QString getCpuModel() const;
    QString getCpuSpeed() const;
    QString getCpuCore() const;
    QString getUsername() const;

    QFileInfoList getCrashReports() const;
    QFileInfoList getAppLogs() const;
    QFileInfoList getAppCaches() const;

private:
    QString cpuCore;
    QString cpuModel;
    QString cpuSpeed;
    QString username;
};

#endif // SYSTEMINFO_H
