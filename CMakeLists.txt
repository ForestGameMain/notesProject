cmake_minimum_required(VERSION 3.21)
project(notesProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(notesProject
        main.cpp
        cmake-build-debug/main.py
        cmake-build-debug/design.glade
        )

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
