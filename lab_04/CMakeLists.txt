cmake_minimum_required(VERSION 3.21)

# Standalone-capable: this file works either as its own top-level project
# (cd lab_04 && cmake --preset release) or as a subdirectory of the root
# aggregate build (root CMakeLists.txt's add_subdirectory()). Project-wide
# settings only need to be (re)established in the former case - the root
# project already sets them for the aggregate build.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  project(lab04 LANGUAGES C)

  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED ON)
  set(CMAKE_C_EXTENSIONS OFF)

  if (MSVC)
    add_compile_options(/W4 /WX)
  else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
  endif ()
endif ()

add_executable(lab04
        src/main.c
        src/utils.c
)

target_include_directories(lab04 PRIVATE include)

target_compile_options(lab04 PRIVATE -Wall -Wextra -Werror -pedantic)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FormatTargets.cmake)
  add_format_targets(
          ${CMAKE_CURRENT_SOURCE_DIR}/*.c
          ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
endif ()
