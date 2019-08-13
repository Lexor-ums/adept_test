TEMPLATE = subdirs

SUBDIRS += \
    app \
    lib

include(../common.pri)
system(for item in $(ls config/*.ini); do cp -f $item $${BIN_PATH}$item; done)
