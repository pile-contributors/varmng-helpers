#include <varmng/varmng.h>
#include "../../../varmng/varmng-private.h"
#include "mainwindow.h"

#ifdef _WIN32
#   include <windows.h>
#   include <stdio.h>
#   include <io.h>
#   include <Fcntl.h>
#endif

#include <QApplication>

#ifdef _WIN32
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
    int argc = __argc;
    char **argv = __argv;
#else
int   main    ( int argc, char *argv[] )
{
#endif

    /* prepare to start */
    QApplication apl(argc, argv);

    /* prepare the ground for easy access to settings */
    QCoreApplication::setOrganizationName("Piles");
    QCoreApplication::setOrganizationDomain("pile-contributors.github.io");
    QCoreApplication::setApplicationName("varmng");

    MainWindow mw;
    mw.show ();

    return apl.exec();
}
