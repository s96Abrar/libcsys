QT       += widgets core network gui charts concurrent dbus

TARGET    = csys
TEMPLATE  = lib

# disable all build warnings
CONFIG   += silent warn_on build_all c++11

INCLUDEPATH += ./csys/
DEPENDPATH  += ./csys/

# Disable Debug on Release
#CONFIG(release):DEFINES += QT_NO_DEBUG_OUTPUT

VERSION = 2.3.0
DEFINES += LIBCSYS_LIBRARY

MOC_DIR			= ../build/moc
OBJECTS_DIR		= ../build/obj
RCC_DIR			= ../build/qrc
UI_DIR			= ../build/uic

unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }

        INSTALLS	+= target includes
        CONFIG		+= create_pc create_prl no_install_prl link_pkgconfig
        contains(DEFINES, LIB64): target.path = $$INSTALL_PREFIX/lib64
        else: target.path = $$INSTALL_PREFIX/lib

        target.path			= $$PREFIX/lib/
        includes.files	                = libcsys_global.h csys/*.h
        includes.path		        = $$PREFIX/include/csys

        QMAKE_PKGCONFIG_FILE        = csys
        QMAKE_PKGCONFIG_NAME        = libcsys
        QMAKE_PKGCONFIG_DESCRIPTION = Library for CoreApps
        QMAKE_PKGCONFIG_PREFIX      = $$INSTALL_PREFIX
        QMAKE_PKGCONFIG_LIBDIR      = $$target.path
        QMAKE_PKGCONFIG_INCDIR      = $$includes.path
        QMAKE_PKGCONFIG_VERSION     = $$VERSION
        QMAKE_PKGCONFIG_DESTDIR     = pkgconfig # Destination Directory where pkgconfig installed
}

HEADERS += \
    csys/cpu_info.h \
    csys/disk_info.h \
    csys/memory_info.h \
    csys/network_info.h \
    csys/process.h \
    csys/process_info.h \
    csys/system_info.h \
    csys/command_util.h \
    csys/file_util.h \
    csys/format_util.h \
    csys/battery.h \
    csys/info_manager.h \
    csys/upower.h \
    csys/udisks2.h \
    libcsys_global.h

SOURCES += \
    csys/cpu_info.cpp \
    csys/disk_info.cpp \
    csys/memory_info.cpp \
    csys/network_info.cpp \
    csys/process.cpp \
    csys/process_info.cpp \
    csys/system_info.cpp \
    csys/command_util.cpp \
    csys/file_util.cpp \
    csys/format_util.cpp \
    csys/battery.cpp \
    csys/info_manager.cpp \
    csys/upower.cpp \
    csys/udisks2.cpp
