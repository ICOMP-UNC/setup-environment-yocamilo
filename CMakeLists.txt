#   Request the minimum version of CMake, in case of lower version throws error.
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Establece la política CMP0048 en NEW
cmake_policy(SET CMP0048 NEW)

#   Define our project.
project(
    "First_Program"
    VERSION 1.2.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)

#   Enable testing
include(CTest)

#   Define, in this case, the C standard, we are going to use std17.
set(CMAKE_C_STANDARD 17)

#   Include the 'include' directory, where the headers are located.
include_directories(include)

#   To automatic download external deps
include(FetchContent)

#   Download Unity library with link
set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

#   Enable Debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

#   Ensures the named dependencies
FetchContent_MakeAvailable(Unity)

#   Defino el cÃ³digo fuente. Add the 'src' directory, where the source files are located.
file(GLOB_RECURSE SOURCES "src/*.c")

#   Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

target_link_libraries(${PROJECT_NAME} StaticCLib DynamicCLib)

#   Add subdirectory test
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()
