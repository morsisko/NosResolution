#include "mainwindow.h"
#include <QApplication>
#include <Windows.h>
#include <memory>


DWORD WINAPI DLLStart(LPVOID param)
{
    int argc = 0;
    QApplication app(argc, NULL);
    MainWindow window;
    window.show();
    app.exec();

    return 0;
}
BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, DLLStart, 0, 0, 0);
        DisableThreadLibraryCalls(hinstDLL);
    break;
    }
return TRUE;
}
