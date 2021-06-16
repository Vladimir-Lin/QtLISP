NAME         = QtLISP
TARGET       = $${NAME}
QT           = core
QT          -= gui
CONFIG(static,static|shared) {
# static version does not support Qt Script now
QT          -= script
} else {
QT          += script
}
QT          += network
QT          += sql

load(qt_build_config)
load(qt_module)

DEFINES     += ECL_UNICODE

INCLUDEPATH += $${PWD}/../../include/QtLISP

HEADERS     += $${PWD}/../../include/QtLISP/qtlisp.h
# HEADERS     += $${PWD}/nLISPInternal.h

SOURCES     += $${PWD}/nLISP.cpp
# SOURCES     += $${PWD}/nLISPInternal.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)

# TRNAME       = $${NAME}
# include ($${PWD}/../../Translations.pri)

# win32 {
# LIBS        += -lecl/ecl
# }
