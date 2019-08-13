/**************************************************************************
**  File: main.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 09.08.2019
**************************************************************************/

#include <QtWidgets/qapplication.h>
#include "presentation/mainwindow/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
