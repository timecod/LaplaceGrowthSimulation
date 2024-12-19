cmake_minimum_required(VERSION 3.16)
project(LaplaceGrowth)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt6 COMPONENTS Widgets Graphs Charts REQUIRED)
set(SOURCES
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/mainwindow.ui
    src/configsub.h
    src/configsub.cpp
    src/configsub.ui
    src/canvassub.h 
    src/canvassub.cpp
    src/matproc.h 
    src/matproc.cpp
)

add_executable(LaplaceGrowth ${SOURCES})

target_include_directories(LaplaceGrowth PRIVATE /usr/include/eigen3)
target_link_libraries(LaplaceGrowth Qt6::Widgets Qt6::Graphs Qt6::Charts)
