#include "MainWindow.h"

#include <QVBoxLayout>

#include "StatusBar/StatusBarWidget.h"
#include "TabWidget/TabWidget.h"
#include "ToolBar/ToolBarWidget.h"

MainWindow::MainWindow(QWidget* parent)
    : _tabWidget{ new TabWidget() },
      _centralWidget(new QWidget(parent)),
      _toolBar{ new ToolBarWidget() },
      _statusBar{ new StatusBarWidget() }
{
    resize(900, 700);
    std::thread([this]() { _server.run(); }).detach();

    setupUi();
    setCentralWidget(_centralWidget);
}

void MainWindow::setupUi()
{
    const auto vLayout = new QVBoxLayout();

    vLayout->addWidget(_toolBar);
    vLayout->addWidget(_tabWidget);
    vLayout->addWidget(_statusBar);
    vLayout->setAlignment(Qt::AlignBottom);

    _centralWidget->setLayout(vLayout);
}
