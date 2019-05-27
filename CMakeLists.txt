cmake_minimum_required(VERSION 3.14)
project(alex_messung)
set(CMAKE_CXX_STANDARD 14)

# set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")


find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)
# need this to include the auto generated ui_mainwindow.h
# file from the qt5_wrap_ui call below.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(project_sources src/ui/mainscreen/mainwindow.cpp
        src/main.cpp
        src/controller_model/MeasurePoint.cpp src/controller_model/Measure.cpp src/controller_model/Measure.h)

set(project_headers src/ui/mainscreen/mainwindow.h src/controller_model/DataModel.cpp src/controller_model/DataModel.h)

set(project_ui src/ui/mainscreen/main_screen.ui)
# wrap the ui file to a c++ header
qt5_wrap_ui(ui_wrap ${project_ui})
qt5_wrap_cpp(moc_sources ${project_headers})
add_executable(alex_messung
        ${project_sources}
        ${project_headers}
        ${ui_wrap}
        ${moc_sources})

target_link_libraries(alex_messung
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)
