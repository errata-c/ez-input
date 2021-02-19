
find_package(SFML CONFIG REQUIRED COMPONENTS system window)
find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glew REQUIRED)

add_library(test_interface INTERFACE)
target_link_libraries(test_interface INTERFACE GLEW::GLEW ez::input fmt::fmt)
target_compile_features(test_interface INTERFACE cxx_std_17)

add_executable(sfml_test "sfml/main.cpp")
target_link_libraries(sfml_test PRIVATE test_interface sfml-system sfml-window)

add_executable(sdl_test "sdl/main.cpp")
target_link_libraries(sdl_test PRIVATE test_interface SDL2::SDL2 SDL2::SDL2main)

add_executable(operator_test "operator/main.cpp")
target_link_libraries(operator_test PRIVATE test_interface sfml-system sfml-window)

add_executable(format_test "format/main.cpp")
target_link_libraries(format_test PRIVATE test_interface)