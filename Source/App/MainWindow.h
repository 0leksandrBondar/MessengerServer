#pragma once

#include <QMainWindow>

#include "../Server/Server.h"

class TabWidget;
class ToolBarWidget;
class StatusBarWidget;

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void setupUi();

private:
    Server _server;
    TabWidget* _tabWidget{ nullptr };
    QWidget* _centralWidget{ nullptr };
    ToolBarWidget* _toolBar{ nullptr };
    StatusBarWidget* _statusBar{ nullptr };
};
