PROJECT_ROOT_PATH = $${PWD}
BIN_PATH = $${PROJECT_ROOT_PATH}/bin/


LIBS_PATH = $${PROJECT_ROOT_PATH}/bin/libs/
LIBS += -L$${LIBS_PATH}

CONFIG(release, debug|release) {
CONFIG += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
}

!exists($${PROJECT_ROOT_PATH}/bin/) {
    system(mkdir $${PROJECT_ROOT_PATH}/bin/)
}

!exists($${BIN_PATH}config/) {
    system(mkdir $${BIN_PATH}config/)
}

