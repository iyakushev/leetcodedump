
cmake_minimum_required(VERSION 3.25)
project(LEET)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_SOURCE_DIR})

include(FetchContent)

FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.1.1
    GIT_PROGRESS TRUE
    OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(fmt)
find_package(fmt REQUIRED)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_compile_options(-fsanitize=address -fsanitize=undefined)
add_link_options(-fsanitize=address)

add_subdirectory(src)
