#pragma once

#include <QWidget>

class QLabel;

class StatusBarWidget final : public QWidget
{
public:
    StatusBarWidget(QWidget* parent = nullptr);

    void updatePortLabel(int port) const;
    void updateOnlineUsers(int count) const;
    void updateIpLabel(const QString& ip);
    void updateServerStatus(bool isRunning) const;

private:
    void setupUi();

private:
    QLabel* _ipLabel{ nullptr };
    QLabel* _portLabel{ nullptr };
    QLabel* _onlineUsersLabel{ nullptr };
    QLabel* _serverStatusLabel{ nullptr };
};