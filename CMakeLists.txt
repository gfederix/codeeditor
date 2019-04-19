cmake_minimum_required(VERSION 3.12)
project(codeeditor
  VERSION 0.1
  DESCRIPTION "No Description yet"
  HOMEPAGE_URL "https://github.com/gfederix/codeeditor"
  LANGUAGES CXX)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# DEFAULT_FLAGS
set(DEFAULT_FLAGS cxx_std_17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Find the QtWidgets library
# https://doc.qt.io/qt-5/cmake-manual.html
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
# https://docs.python.org/3/extending/
find_package(Python3 COMPONENTS Development REQUIRED)
find_package(pybind11 REQUIRED)

add_subdirectory(src)
