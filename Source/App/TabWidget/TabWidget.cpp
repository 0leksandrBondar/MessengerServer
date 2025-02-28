#include "TabWidget.h"

#include <QTabWidget>
#include <QVBoxLayout>

TabWidget::TabWidget(QWidget* parent) : _tabWidget{ new QTabWidget(parent) } { setupUi(); }

void TabWidget::setupUi()
{
    const auto vLayout = new QVBoxLayout();

    vLayout->addWidget(_tabWidget);

    setLayout(vLayout);
}