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

#include "command_util.h"


QString CommandUtil::sudoExec(const QString &cmd, QStringList args, QByteArray data)
{
    args.push_front(cmd);

    QString result("");

    try {
        result = CommandUtil::exec("pkexec", args, data);
    } catch (QString &ex) {
        qCritical() << ex;
    }

    return result;
}

QString CommandUtil::exec(const QString &cmd, QStringList args, QByteArray data)
{
    QProcess* process = new QProcess;

    process->start(cmd, args);

    if (! data.isEmpty()) {
        process->write(data);
        process->waitForBytesWritten();
        process->closeWriteChannel();
    }

    process->waitForFinished();

    QTextStream stdOut(process->readAllStandardOutput());

    QString err = process->errorString();

    process->kill();
    process->close();

    if (process->error() != QProcess::UnknownError)
        throw err;

    return stdOut.readAll().trimmed();
}

bool CommandUtil::isExecutable(const QString &cmd)
{
    return !QStandardPaths::findExecutable(cmd).isEmpty();
}
