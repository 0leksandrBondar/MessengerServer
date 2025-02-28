#include "StatusBarWidget.h"

#include <QLabel>
#include <QVBoxLayout>

StatusBarWidget::StatusBarWidget(QWidget* parent)
    : _ipLabel{ new QLabel() },
      _portLabel{ new QLabel() },
      _onlineUsersLabel{ new QLabel },
      _serverStatusLabel{ new QLabel }
{
    setupUi();
}

void StatusBarWidget::updatePortLabel(int port) const
{
    const QString portText
        = QString("<b>Port:</b> <span style='color:orange;'>%1</span>").arg(port);
    _portLabel->setText(portText);
}

void StatusBarWidget::updateOnlineUsers(int count) const
{
    const QString usersText
        = QString("<b>Online:</b> <span style='color:orange;'>%1</span>").arg(count);
    _onlineUsersLabel->setText(usersText);
}

void StatusBarWidget::updateIpLabel(const QString& ip)
{
    const QString ipAddress = QString("<b>IP:</b> <span style='color:orange;'>%1</span>").arg(ip);
    _ipLabel->setText(ipAddress);
}

void StatusBarWidget::updateServerStatus(bool isRunning) const
{
    const QString statusText = isRunning ? "<b>Status:</b> <span style='color:green;'>Online</span>"
                                         : "<b>Status:</b> <span style='color:red;'>Offline</span>";

    _serverStatusLabel->setText(statusText);
}

void StatusBarWidget::setupUi()
{
    auto* hLayout = new QHBoxLayout(this);

    updatePortLabel(8080);
    updateOnlineUsers(0);
    updateIpLabel("127.0.0.1");
    updateServerStatus(true);

    hLayout->addWidget(_serverStatusLabel);
    hLayout->addWidget(_onlineUsersLabel);
    hLayout->addWidget(_ipLabel);
    hLayout->addWidget(_portLabel);

    setLayout(hLayout);
}