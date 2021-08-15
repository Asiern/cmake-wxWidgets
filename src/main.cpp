#include "main.h"
#include "mainWindow.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    mainWindow *window = new mainWindow();
    window->Show();
    return true;
}