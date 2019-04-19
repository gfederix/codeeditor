add_executable(codeeditor
  main.cpp
  codeframe/codeframe.cpp
  codeframe/codeframe.hpp)
# Use the Widgets module from Qt 5
target_link_libraries(codeeditor PRIVATE Qt5::Widgets Qt5::Gui Python3::Python pybind11::embed)
target_compile_features(codeeditor PUBLIC ${DEFAULT_FLAGS} )
# QT_NO_KEYWORDS it tells Qt not to define the moc keywords signals, slots, and
# emit, because these names will be used by a 3rd party library, e.g. Boost.
# Then to continue using Qt signals and slots with the no_keywords flag, simply
# replace all uses of the Qt moc keywords in your sources with the corresponding
# Qt macros Q_SIGNALS (or Q_SIGNAL), Q_SLOTS (or Q_SLOT), and Q_EMIT.
# https://stackoverflow.com/questions/23068700 /embedding-python3-in-qt-5
# https://doc.qt.io/qt-5/signalsandslots.html#using-qt-with-3rd-party-signals-and-slots
target_compile_definitions(codeeditor PRIVATE QT_NO_KEYWORDS)
target_include_directories(codeeditor PRIVATE ${PROJECT_BINARY_DIR})
install(TARGETS codeeditor DESTINATION bin)
set(PY_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/codeeditor.py)
configure_file(config.h.in config.h)
add_subdirectory(codeframe)
# Code Frame Test
# add_executable(codeframe codeframe.cpp codeframe.hpp)
# target_link_libraries(codeframe PRIVATE Qt5::Widgets)
# target_compile_features(codeframe PUBLIC ${DEFAULT_FLAGS} )
