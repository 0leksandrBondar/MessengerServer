cmake_minimum_required(VERSION 3.16...3.29)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(SOURCE
        App/main.cpp
        App/MainWindow.h
        App/MainWindow.cpp
        App/StatusBarWidget.h
        App/StatusBarWidget.cpp

        Server/Server.h
        Server/Server.cpp
)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} PUBLIC
        Boost::asio
        Boost::endian
        Qt6::Core
        Qt6::Widgets
)