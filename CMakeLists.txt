cmake_minimum_required(VERSION 3.0)

project(
    Dstruct-Lib
    VERSION 1.0
    DESCRIPTION "A Simple Data Strucuture Lib for C developers"
    LANGUAGES C
    HOMEPAGE_URL "https://github.com/danofred00/dstruct-lib"
)

# lib files
file(GLOB_RECURSE LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/*)

# create a lib
add_library(dstruct SHARED ${LIB_SOURCES})
target_include_directories(dstruct PRIVATE ${CMAKE_SOURCE_DIR}/include)