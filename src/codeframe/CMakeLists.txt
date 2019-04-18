# Code Frame Test
add_executable(codeframe main.cpp codeframe.cpp codeframe.hpp)
target_link_libraries(codeframe PRIVATE Qt5::Widgets)
target_compile_features(codeframe PUBLIC ${DEFAULT_FLAGS} )
install(TARGETS codeframe DESTINATION bin)
