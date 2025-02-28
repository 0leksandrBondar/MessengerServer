#pragma once

#include <QWidget>

class QTabWidget;

class TabWidget final : public QWidget
{
public:
    explicit TabWidget(QWidget* parent = nullptr);

private:
    void setupUi();

private:
    QTabWidget* _tabWidget{ nullptr };
};