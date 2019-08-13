TEMPLATE = app
DESTDIR = $${BIN_PATH}/
QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/libs/
