cmake_minimum_required(VERSION 3.7)
project(qt-app)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(include)
add_executable(main src/main.cpp src/main_window.cpp)
target_link_libraries(main Qt5::Widgets)
