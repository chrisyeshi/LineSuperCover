cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_library(linesuper ${SOURCES} ${HEADERS})

enable_testing()
add_subdirectory(tests)