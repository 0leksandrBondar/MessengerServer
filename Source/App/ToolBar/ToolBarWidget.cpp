#include "ToolBarWidget.h"

#include <QPushButton>
#include <QHBoxLayout>

ToolBarWidget::ToolBarWidget(QWidget* parent)
    : _runServerButton{ new QPushButton(QStringLiteral("Run")) },
      _stopServerButton{ new QPushButton(QStringLiteral("Stop")) }
{
    setupUi();
}

void ToolBarWidget::setupUi()
{
    auto* hLayout = new QHBoxLayout(this);

    _runServerButton->setFixedSize(50,30);
    _stopServerButton->setFixedSize(50,30);

    hLayout->addWidget(_runServerButton);
    hLayout->addWidget(_stopServerButton);
    hLayout->addStretch();

    setLayout(hLayout);
}
