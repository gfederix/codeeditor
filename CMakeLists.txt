cmake_minimum_required(VERSION 3.12)
project(codeeditor)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
set(DEFAULT_FLAGS cxx_std_17)

# Find the QtWidgets library
# https://doc.qt.io/qt-5/cmake-manual.html
find_package(Qt5Widgets CONFIG REQUIRED)
# https://docs.python.org/3/extending/
find_package(Python3 COMPONENTS Development REQUIRED)
find_package(pybind11 REQUIRED)

# Populate a CMake variable with the sources
set(codeeditor_SRC
  main.cpp
  codeeditor.cpp
  codeeditor.hpp
  )
# Tell CMake to create the helloworld executable
add_executable(codeeditor ${codeeditor_SRC})
# Use the Widgets module from Qt 5
target_link_libraries(codeeditor PRIVATE Qt5::Widgets Python3::Python pybind11::embed)
target_compile_features(codeeditor PUBLIC ${DEFAULT_FLAGS} )
# QT_NO_KEYWORDS it tells Qt not to define the moc keywords signals, slots, and
# emit, because these names will be used by a 3rd party library, e.g. Boost.
# Then to continue using Qt signals and slots with the no_keywords flag, simply
# replace all uses of the Qt moc keywords in your sources with the corresponding
# Qt macros Q_SIGNALS (or Q_SIGNAL), Q_SLOTS (or Q_SLOT), and Q_EMIT.
# https://stackoverflow.com/questions/23068700 /embedding-python3-in-qt-5
# https://doc.qt.io/qt-5/signalsandslots.html#using-qt-with-3rd-party-signals-and-slots
target_compile_definitions(codeeditor PRIVATE QT_NO_KEYWORDS)

# Code Frame Test
add_executable(codeframe codeframe.cpp codeframe.hpp)
target_link_libraries(codeframe PRIVATE Qt5::Widgets)
target_compile_features(codeframe PUBLIC ${DEFAULT_FLAGS} )
