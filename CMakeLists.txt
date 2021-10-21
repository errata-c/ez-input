cmake_minimum_required(VERSION 3.14)

project(EZ_INPUT
	VERSION 0.3.0
	LANGUAGES C CXX
)

include(FetchContent)

FetchContent_Declare(
	ez-cmake
	GIT_REPOSITORY "https://github.com/errata-c/ez-cmake.git"
	GIT_TAG "main"
)
FetchContent_MakeAvailable(ez-cmake)

option(EZ_INPUT_BUILD_TESTS "Build the test executables" OFF)
set(EZ_INPUT_CONFIG_DIR "share/ez-input" CACHE STRING "The relative directory to install cmake package config files.")

find_package(glm CONFIG REQUIRED)
find_package(ez-bitflags CONFIG REQUIRED)
find_package(utf8cpp CONFIG REQUIRED)

add_library("ez-input" STATIC 
	"src/Key.cpp" 
	"src/Mouse.cpp" 
	"src/InputEngine.cpp"
	"src/InputEvent.cpp"
	"src/InputState.cpp"
	"src/KeyMap.cpp"
	"src/KeyMods.cpp"
	"src/enumerations.cpp"
)

target_include_directories(ez-input PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)

target_compile_features(ez-input PUBLIC cxx_std_17)
target_link_libraries(ez-input 
PUBLIC 
	glm::glm 
	ez::bitflags
PRIVATE
	$<BUILD_INTERFACE:utf8cpp>
)
target_compile_options(ez-input PRIVATE "$<BUILD_INTERFACE:$<$<CXX_COMPILER_ID:MSVC>:/permissive->>")
set_target_properties(ez-input PROPERTIES EXPORT_NAME "input")

add_library(ez::input ALIAS ez-input)

if(EZ_INPUT_BUILD_TESTS)
	add_subdirectory("tests")
endif()

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
	TYPE INCLUDE
	FILES_MATCHING
	PATTERN "*.h" PATTERN "*.hpp"
)

install(TARGETS "ez-input"
    EXPORT "ez-input-targets"
    PUBLIC_HEADER DESTINATION "include"
    ARCHIVE DESTINATION "lib/$<CONFIG>"
    LIBRARY DESTINATION "lib/$<CONFIG>"
    RUNTIME DESTINATION "bin/$<CONFIG>"
)

install_package(
	NAME "ez-input"
	NAMESPACE "ez::"
	EXPORT "ez-input-targets"
	VERSION "${EZ_INPUT_VERSION}"
	COMPATIBILITY "SameMajorVersion"
	DESTINATION "${EZ_INPUT_CONFIG_DIR}"
	PRECONFIG "cmake/preconfig.cmake"
)