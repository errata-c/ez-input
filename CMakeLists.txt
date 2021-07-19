cmake_minimum_required(VERSION 3.14)

project(EZ_INPUT
VERSION 0.2.1
LANGUAGES C CXX
)

include(GNUInstallDirs)
include(FetchContent)

FetchContent_Declare(
	ez-cmake
	GIT_REPOSITORY "https://github.com/errata-c/ez-cmake.git"
	GIT_TAG "a59477ebb9d8ce1f686b99118586310f47cb7a80"
)
FetchContent_MakeAvailable(ez-cmake)

option(BUILD_TESTS "Build the test executables" ON)
option(SEPARATE_DIRECTORY "Install the package into its own directory" ON)
set(CONFIG_DIR "${CMAKE_INSTALL_DATAROOTDIR}/ez-input" CACHE STRING "The relative directory to install package config files.")


find_package(glm CONFIG REQUIRED)
find_package(ez-bitflags CONFIG REQUIRED)
find_path(UTF8H_INCLUDE_DIRS "utf8h/utf8.h")

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
	"$<BUILD_INTERFACE:${UTF8H_INCLUDE_DIRS}>"
	"$<INSTALL_INTERFACE:include>"
)

target_compile_features(ez-input PUBLIC cxx_std_17)
target_link_libraries(ez-input PUBLIC 
	glm::glm 
	ez::bitflags
)
target_compile_options(ez-input PRIVATE "$<BUILD_INTERFACE:$<$<CXX_COMPILER_ID:MSVC>:/permissive->>")
set_target_properties(ez-input PROPERTIES EXPORT_NAME "input")

add_library(ez::input ALIAS ez-input)

if(${BUILD_TESTS})
	add_subdirectory("tests")
endif()

set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/ez-input)

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
    RUNTIME DESTINATION "bin/$<CONFIG>")

install_package(
	NAME "ez-input"
	NAMESPACE "ez::"
	EXPORT "ez-input-targets"
	VERSION "${EZ_INPUT_VERSION}"
	COMPATIBILITY "SameMajorVersion"
	DESTINATION "${CONFIG_DIR}"
	PRECONFIG "cmake/preconfig.cmake"
)