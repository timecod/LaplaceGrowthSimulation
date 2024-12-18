cmake_minimum_required(VERSION 3.16)
project(LaplaceGrowth)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h 
    src/mainwindow.ui
)
add_executable(LaplaceGrowth ${SOURCES})

target_link_libraries(LaplaceGrowth Qt6::Widgets )
