#pragma once

#include <QMainWindow>

#include "../Server/Server.h"

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    Server _server;
};
