cmake_minimum_required(VERSION 3.30)

set(SOURCE main.cpp)

add_executable(${PROJECT_NAME}  ${SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    Boost::asio
)
