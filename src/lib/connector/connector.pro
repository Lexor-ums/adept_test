include(../../../common.pri)
include(../../../lib.pri)
DEFINES += DATABASE_LIBRARY
TARGET = connectortodatabase
SOURCES += connectortodatabase.cpp
HEADERS += database.h connectortodatabase.h
QT += sql
system(for item in $(ls config/*.ini); do cp -f $item $${BIN_PATH}$item; done)
