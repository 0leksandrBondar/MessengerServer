#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    resize(900, 700);
    std::thread([this]() { _server.run(); }).detach();
}
