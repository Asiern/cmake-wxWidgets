#include "mainWindow.h"

mainWindow::mainWindow() : wxFrame(NULL, wxID_ANY, "foo", wxDefaultPosition, wxSize(500, 500))
{
	Centre();
}

mainWindow::~mainWindow()
{
}
