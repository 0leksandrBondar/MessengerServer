#pragma once

#include <QWidget>

class QPushButton;

class ToolBarWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBarWidget(QWidget* parent = nullptr);

private:
    void setupUi();

private:
    QPushButton* _runServerButton{ nullptr };
    QPushButton* _stopServerButton{ nullptr };
};