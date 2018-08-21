QT       += widgets core network gui charts concurrent dbus

TARGET = csys
TEMPLATE = lib

# disable all build warnings
CONFIG += warn_off
CONFIG += silent warn_on shared_and_static


# Disable Debug on Release
CONFIG(release):DEFINES += QT_NO_DEBUG_OUTPUT

VERSION = 1.0.9
DEFINES += LIBCSYS_LIBRARY

HEADERS += \
    Info/cpu_info.h \
    Info/disk_info.h \
    Info/memory_info.h \
    Info/network_info.h \
    Info/process.h \
    Info/process_info.h \
    Info/system_info.h \
    Utils/command_util.h \
    Utils/file_util.h \
    Utils/format_util.h \
    battery.h \
    info_manager.h \
    libcsys_global.h \
    upower.h \
    udisks2.h

SOURCES += \
    Info/cpu_info.cpp \
    Info/disk_info.cpp \
    Info/memory_info.cpp \
    Info/network_info.cpp \
    Info/process.cpp \
    Info/process_info.cpp \
    Info/system_info.cpp \
    Utils/command_util.cpp \
    Utils/file_util.cpp \
    Utils/format_util.cpp \
    battery.cpp \
    info_manager.cpp \
    upower.cpp \
    udisks2.cpp

MOC_DIR			= ../build/moc
OBJECTS_DIR		= ../build/obj
RCC_DIR			= ../build/qrc
UI_DIR			= ../build/uic

unix {
        isEmpty(PREFIX) {
                PREFIX = /usr
        }

        INSTALLS	+= target includes data
        CONFIG		+= create_pc no_install_prl link_pkgconfig
        contains(DEFINES, LIB64): target.path = $$INSTALL_PREFIX/lib64
        else: target.path = $$INSTALL_PREFIX/lib

        target.path			= $$PREFIX/lib/
        includes.files	=  upower.h battery.h info_manager.h system_info.h udisks2.h format_util.cpp system_info.cpp
        includes.path		= $$PREFIX/include/

        data.path = $$PREFIX/share/lib$$TARGET/
        data.files = Changelog README

        QMAKE_PKGCONFIG_NAME = libcprime
        QMAKE_PKGCONFIG_DESCRIPTION = A Qt based archiving solution with libarchive backend
        QMAKE_PKGCONFIG_PREFIX  = $$INSTALL_PREFIX
        QMAKE_PKGCONFIG_LIBDIR  = $$target.path
        QMAKE_PKGCONFIG_INCDIR  = $$includes.path
        QMAKE_PKGCONFIG_VERSION = $$VERSION
        QMAKE_PKGCONFIG_DESTDIR = pkgconfig
}

