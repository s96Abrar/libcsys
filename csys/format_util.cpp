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

#include "format_util.h"

QString FormatUtil::formatBytes(const quint64 &bytes)
{
#define formatUnit(v, u, t) QString().sprintf("%.1f %s", \
    (static_cast<double>(v) / static_cast<double>(u)), t)

    if (bytes == 1L) // bytes
        return QString("%1 byte").arg(bytes);
    else if (bytes < KIBI) // bytes
      return QString("%1 bytes").arg(bytes);
    else if (bytes < MEBI) // KiB
      return formatUnit(bytes, KIBI, "KiB");
    else if (bytes < GIBI) // MiB
      return formatUnit(bytes, MEBI, "MiB");
    else if (bytes < TEBI) // GiB
      return formatUnit(bytes, GIBI, "GiB");
    else                   // TiB
      return formatUnit(bytes, TEBI, "TiB");
#undef formatUnit
}
