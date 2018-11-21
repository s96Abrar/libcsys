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

#include "process_info.h"

#include "file_util.h"
#include "command_util.h"
#include "process.h"

void ProcessInfo::updateProcesses()
{
    processList.clear();

    try {
        QStringList columns = { "pid", "rss", "pmem", "vsize", "uname:50", "pcpu", "start_time",
                                "state", "group", "nice", "cputime", "session", "cmd"
                              };
        QStringList lines = CommandUtil::exec( "ps", {"ax", "-weo", columns.join( "," ), "--no-headings"} ).trimmed().split( QChar( '\n' ) );

        if ( ! lines.isEmpty() ) {
            QRegExp sep( "\\s+" );

            for ( const QString &line : lines ) {
                QStringList procLine = line.trimmed().split( sep );

                if ( procLine.count() >= columns.count() ) {
                    Process *proc = new Process;
                    proc->setPid( static_cast<int>( procLine.takeFirst().toLong() ) );
                    proc->setRss( static_cast<quint64>( procLine.takeFirst().toLong() ) << 10 );
                    proc->setPmem( procLine.takeFirst().toDouble() );
                    proc->setVsize( static_cast<quint64>( procLine.takeFirst().toLong() ) << 10 );
                    proc->setUname( procLine.takeFirst() );
                    proc->setPcpu( procLine.takeFirst().toDouble() );
                    proc->setStartTime( procLine.takeFirst() );
                    proc->setState( procLine.takeFirst() );
                    proc->setGroup( procLine.takeFirst() );
                    proc->setNice( procLine.takeFirst().toInt() );
                    proc->setCpuTime( procLine.takeFirst() );
                    proc->setSession( procLine.takeFirst() );
                    proc->setCmd( procLine.join( " " ) );

                    processList << proc;
                }
            }
        }
    } catch ( QString &ex ) {
        qCritical() << ex;
    }
}

QList<Process *> ProcessInfo::getProcessList() const
{
    return processList;
}
