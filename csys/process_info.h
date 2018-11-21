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

#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include "libcsys_global.h"

class Process;

class LIBCSYSSHARED_EXPORT ProcessInfo : public QObject {
    Q_OBJECT

public:
    QList<Process *> getProcessList() const;

public slots:
    void updateProcesses();

private:
    QList<Process *> processList;
};

#endif // PROCESS_INFO_H
